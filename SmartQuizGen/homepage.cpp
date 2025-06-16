extern "C" {
#include <Python.h>
}

#include "homepage.h"
#include "showpdfs.h"
#include "choosequiz.h"

QString jsonQuizData; // Global variable to store JSON before saving

void parseJsonQuiz(const QString& jsonString, Quiz& quiz) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    if (!doc.isNull()) {
        QJsonObject quizObject = doc.object();
        QJsonArray quizArray = quizObject["quiz"].toArray();
        for (const QJsonValue& value : quizArray) {
            QJsonObject questionObj = value.toObject();
            QString questionText = questionObj["question"].toString();
            QJsonArray optionsArray = questionObj["options"].toArray();
            QString correctAnswer = questionObj["correct_answer"].toString();
            std::vector<QString> options;
            for (const QJsonValue& optionValue : optionsArray) {
                options.push_back(optionValue.toString());
            }
            Question question(questionText, options, correctAnswer);
            quiz.addQuestion(question);
        }
    } else {
        qWarning() << "Failed to parse JSON.";
    }
}

HomePage::HomePage(User* user, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::HomePage),
    currentUser(user),
    uploadedFilePath("")
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setModal(true);

    ui->UsernameTitle->setText(currentUser->getUsername());
    int userId = User::getId(currentUser->getUsername());  // assumed static

    connect(ui->UploadAndGenerateButton, &QPushButton::clicked, this, [this, userId]() {
        QString filePath = QFileDialog::getOpenFileName(
            this,
            "Select PDF Document",
            QDir::homePath(),
            "PDF Files (*.pdf);;All Files (*)"
            );

        if (filePath.isEmpty()) return;

        ui->UploadAndGenerateButton->setEnabled(false);
        ui->UploadAndGenerateButton->setText("Processing...");
        QApplication::processEvents();

        QString output = homePageFunctions::Generatepdf(userId, filePath);

        ui->UploadAndGenerateButton->setEnabled(true);
        ui->UploadAndGenerateButton->setText("📄 Upload PDF & Generate Quiz");

        if (output == "Quiz generation completed successfully.") {
            QMessageBox::information(this, "Success", "Quiz generated successfully!\nYour quiz is ready to use.");
        } else {
            QMessageBox::critical(this, "Error", output);
        }
    });

    connect(ui->UploadButton, &QPushButton::clicked, this, [this, userId]() {
        QString filePath = QFileDialog::getOpenFileName(
            this,
            "Select PDF Document",
            QDir::homePath(),
            "PDF Files (*.pdf);;All Files (*)"
            );

        if (filePath.isEmpty()) return;

        ui->UploadButton->setEnabled(false);
        ui->UploadButton->setText("Uploading...");
        QApplication::processEvents();

        QString output = homePageFunctions::uploadpdf(userId, filePath, nullptr);

        ui->UploadButton->setEnabled(true);
        ui->UploadButton->setText("📤 Upload PDF");

        if (output == "PDF successfully saved to the database.") {
            QMessageBox::information(this, "Success", "PDF uploaded successfully!\nYou can now generate quizzes from it.");
        } else {
            QMessageBox::critical(this, "Error", output);
        }
    });

    connect(ui->GenerateFromOldButton, &QPushButton::clicked, this, [this, userId]() {
        User user = User::getUserById(userId);  // assumed static
        ShowPdfs* ShowPdfsPage = new ShowPdfs(&user);
        ShowPdfsPage->setAttribute(Qt::WA_DeleteOnClose);
        ShowPdfsPage->show();
        this->hide();
    });

    connect(ui->PassQuizButton, &QPushButton::clicked, this, [this, userId]() {
        User user = User::getUserById(userId);  // assumed static
        ChooseQuiz* ChooseQuizPage = new ChooseQuiz(&user);
        ChooseQuizPage->setAttribute(Qt::WA_DeleteOnClose);
        ChooseQuizPage->show();
        this->hide();
    });
}

HomePage::~HomePage() {
    delete ui;
}
