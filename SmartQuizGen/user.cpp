#include "user.h"

// Constructor
User::User(const QString &fName, const QString &lName, const QString &uName, const QString &mail, const QString &pass, bool CanBeSave)
    : firstName(fName), lastName(lName), username(uName), email(mail), CanBeSave(CanBeSave) {
    setPassword(pass);
}
// Getters
QString User::getFirstName() const { return firstName; }
QString User::getLastName() const { return lastName; }
QString User::getUsername() const { return username; }
QString User::getEmail() const { return email; }
QString User::getPassword() const {
    QString decryptedPassword = Encryption::decrypt(password);
    return decryptedPassword;
}
int User::getId(QString username) {
    QSqlQuery query;
    query.prepare("SELECT Id FROM users WHERE Username = :username");
    query.bindValue(":username", username);
    if (!query.exec()) {
        qDebug() << "Error fetching ID:" << query.lastError().text();return -1;
    }
    if (query.next()) {
        int userId = query.value(0).toInt();
        return userId;
    }
    return -1;
}
int User::getId() const {
    return getId(this->getUsername());
}
QString User::getSaveState() const { return CanBeSave ? "True" : "False"; }



User User::getUserById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE Id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString firstName = query.value("FirstName").toString();
        QString lastName = query.value("LastName").toString();
        QString username = query.value("Username").toString();
        QString email = query.value("email").toString();
        QString password = query.value("Password").toString();
        bool canBeSaved = true;

        return User(firstName, lastName, username, email, password, canBeSaved);
    } else {

        return User("", "", "", "", "", false);
    }
}
User User::getUserByUsername(QString username) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE Username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString firstName = query.value("FirstName").toString();
        QString lastName = query.value("LastName").toString();
        QString email = query.value("email").toString();
        QString password = query.value("Password").toString();
        bool canBeSaved = true;

        return User(firstName, lastName, username, email, password, canBeSaved);
    } else {
        return User("", "", "", "", "", false);
    }
}

User User::getUserByEmail(QString email) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        QString firstName = query.value("FirstName").toString();
        QString lastName = query.value("LastName").toString();
        QString username = query.value("Username").toString();
        QString password = query.value("Password").toString();
        bool canBeSaved = true;

        return User(firstName, lastName, username, email, password, canBeSaved);
    } else {
        return User("", "", "", "", "", false);
    }
}


// Setters
void User::setFirstName(const QString &fName) { firstName = fName; }
void User::setLastName(const QString &lName) { lastName = lName; }
void User::setUsername(const QString &uName) { username = uName; }
void User::setEmail(const QString &mail) { email = mail; }
void User::setPassword(const QString &pass) {
    password = Encryption::encrypt(pass);
    qDebug() << "Encrypted Password: " << password;
}


// Save state setters
void User::SaveStateTrue() { CanBeSave = true; }
void User::SaveStateFalse() { CanBeSave = false; }


bool User::isUsernameUsed(const QString& username) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (!query.exec()) {
        return false;
    }
    return query.next() && query.value(0).toInt() > 0;
}

bool User::isEmailUsed(const QString& email) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE email = :email");
    query.bindValue(":email", email);
    if (!query.exec()) {
        return false;
    }
    return query.next() && query.value(0).toInt() > 0;
}

bool User::saveUserToDb() {

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        qWarning() << "Database is not open!";
        return false;
    }


    QSqlQuery query;


    query.prepare("INSERT INTO users (FirstName, LastName,Username,Password,email)"
                  "VALUES (:firstName, :lastName, :username, :password, :email)");

    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.bindValue(":canBeSaved", CanBeSave);

    if (!query.exec()) {
        return false;
    }


    return true;
}
bool User::ChangePassword(const QString& email,const QString& password){
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        qWarning() << "Database is not open!";
        return false;
    }


    QSqlQuery query;
    QString encryptedPassword = Encryption::encrypt(password);
    query.prepare("UPDATE users SET Password = :password, updated_at = CURRENT_TIMESTAMP WHERE email = :email");
    query.bindValue(":password", encryptedPassword);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qWarning() << "Password update failed:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qWarning() << "No user found with the given email.";
        return false;
    }

    return true;
}
