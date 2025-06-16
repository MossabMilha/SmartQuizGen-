#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "ui_HomePage.h"
#include "homepagefunctions.h"
#include "quizexamen.h"
#include "user.h"
#include "pdf.h"
#include "quiz.h"
#include "question.h"
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QFile>
#include <QDialog>
#include <QApplication>
#include <QDir>
#include <vector>  // ✅ added

namespace Ui {
class HomePage;
}

class User;

class HomePage : public QDialog {
    Q_OBJECT

private:
    bool generateAllowed = false;
    QString uploadedFilePath;

public:
    explicit HomePage(User* user, QWidget *parent = nullptr);
    ~HomePage();

private:
    Ui::HomePage* ui;       // ✅ changed to pointer
    User* currentUser;      // ✅ changed to pointer
};

#endif // HOMEPAGE_H
