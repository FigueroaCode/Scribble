#include "database.h"
#include <sql.h>
#include <windows.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

//Constructor
Database:: Database() {
    setConnections();
}

//Student-related Methods
void Database::addStudent(QString studentName, QString passcode) {
    QSqlQuery query;
    QString sid;
    query.exec("SELECT * FROM Student");

    QSqlDatabase defaultDB = QSqlDatabase::database();
    if (defaultDB.driver() ->hasFeature(QSqlDriver :: QuerySize)) {
        sid = query.size() + 1;
    } else {
        query.last();
        sid = query.at() + 2;
    }

    QSqlQuery query2;
    QString queryString = "INSERT INTO Student (sid, sname, passcode) VALUES (sid, studentName, passcode)";

    query2.prepare(queryString);

}
void Database::removeStudent(QString sid) {
    QSqlQuery query;
    query.prepare("DELETE FROM Student WHERE sid = ?");
    query.boundValue(sid);
    query.exec();
}
QString Database::getStudent(QString sid) {
    QSqlQuery query;
    QString userStr("SELECT * FROM Student WHERE sid = :sid");
    query.prepare(userStr);
    query.bindValue(":sid", sid);
    if (query.exec()) {
        while (query.next()) {
            qDebug() << query.value(1).toString();
        }
    } else {
       qDebug() << "Oops " << db.lastError().text();
    }

}

//Course-related Methods attributes votes
void Database::addCourse(QString courseName) {
    QSqlQuery query;
    QString queryString = "INSERT INTO Course (courseName) VALUES (courseName)";
    query.prepare(queryString);
}
void Database::removeCourse(QString cid) {
    QSqlQuery query;
    QString userStr = "DELETE FROM Course WHERE cid = :cid";
    query.prepare(userStr);
    query.bindValue(":cid", cid);
    query.exec();
}
QString Database::getCourse(QString cid) {
    QSqlQuery query;
    QString userStr = "SELECT * FROM Course WHERE cid = :cid";
    query.prepare(userStr);
    query.bindValue(":cid", cid);


    if (query.exec()) {
        while (query.next()) {
            qDebug() << query.value(1).toString();
        }
    } else {
       qDebug() << "Oops " << db.lastError().text();
    }
}

//Chapter-related Methods
void addChapter(QString chapterName,QString courseName, QString date){
    QSqlQuery query;
    QString queryString = "INSERT INTO Chapters (CourseName, ChapterName, Date) VALUES (courseName, chapterName,"
                          ", date)";

    query.prepare(queryString);
}
void removeChapter(QString chapterName, QString courseName, QString date) {
    QSqlQuery query;
    QString userStr = "DELETE FROM Chapters WHERE CourseName = :courseName AND ChapterName = :chapterName AND Date = :studentId";
    query.prepare(userStr);
    query.bindValue(":courseName", courseName);
    query.bindValue(":chapterName", chapterName);
    query.bindValue(":date", date);
    query.exec();
}
QString getChapter(QString chapterName, QString courseName, QString studentId,QString date){
    QSqlQuery query;
    QString userStr = "SELECT * FROM Chapters WHERE CourseName = :courseName AND ChapterName = :chapterName";
    query.prepare(userStr);
    query.bindValue(":courseName", courseName);
    query.bindValue(":chapterName", chapterName);

    if (query.exec()) {
        while (query.next()) {
           QString date = query.value(2).toString();
           return date;
        }
    } else {
       return "Oops, can't find the chapter requested. ";
    }
}

//Notes-related Methods
void Database::addNote(QString courseName,QString chapterName,QString date, QString studentId, QString contents) {

    QSqlQuery query;
    QString queryString = "INSERT INTO Notes (CourseName, ChapterName, StudentId, Date, Contents) VALUES (courseName, chapterName,"
                          ", date, studentId, contents)";

    query.prepare(queryString);
}
void Database::removeNote(QString courseName,QString chapterName,QString studentId) {
    QSqlQuery query;
    QString userStr = "DELETE FROM Notes WHERE courseName = :courseName AND chapterName = :chapterName AND studentId = :studentId";
    query.prepare(userStr);
    query.bindValue(":courseName", courseName);
    query.bindValue(":chapterName", chapterName);
    query.bindValue(":studentId", studentId);
    query.exec();
}
QString Database::getNote(QString courseName,QString chapterName,QString studentId) {
    QSqlQuery query;
    QString userStr = "SELECT * FROM Notes WHERE courseName = :courseName AND chapterName = :chapterName AND studentId = :studentId";
    query.prepare(userStr);
    query.bindValue(":courseName", courseName);
    query.bindValue(":chapterName", chapterName);
    query.bindValue(":studentId", studentId);

    if (query.exec()) {
        while (query.next()) {
           QString date = query.value(3).toString();
           return date;
        }
    } else {
       qDebug() << "Oops " << db.lastError().text();
    }
}

//if the database you want to access is Course Database,
//pass database name "Courses" as the parameter there to get the access

void Database::setConnections() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();

    QString dsn = "DRIVER = {SQL Native Client}; SERVER = MSSQLSERVER; DATABASE = COP3503; Trusted_Connection=Yes;";
    db.setDatabaseName(dsn);
    if (db.open()) {
        qDebug() << "open successfully";
    } else {
        qDebug() << "Oops " << db.lastError().text();
    }
}

void Database::closeDatabase() {
    db.close();
}

