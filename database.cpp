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
Database:: Database(QString dbName) {
    setConnections(dbName);
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

void Database::getStudent(QString sid) {
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
void Database::addCourse(QString courseNum, QString courseName) {
    QSqlQuery query;
    QString queryString = "INSERT INTO Course (courseNum, courseName) VALUES (courseNum, courseName)";
    query.prepare(queryString);
}

void Database::removeCourse(QString cid) {
    QSqlQuery query;
    QString userStr = "DELETE FROM Course WHERE cid = :cid";
    query.prepare(userStr);
    query.bindValue(":cid", cid);
    query.exec();
}

void Database::getCourse(QString cid) {
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

//File-related Methods
void Database::addFile(QString file) {
    QSqlQuery query;
    QString fid;
    query.exec("SELECT * FROM File");

    QSqlDatabase defaultDB = QSqlDatabase::database();
    if (defaultDB.driver() ->hasFeature(QSqlDriver :: QuerySize)) {
        fid = query.size() + 1;
    } else {
        query.last();
        fid = query.at() + 2;
    }

    QSqlQuery query2;
    QString queryString = "INSERT INTO File (fid, file) VALUES (fid, file)";

    query2.prepare(queryString);
}

void Database::removeFile(QString fid) {
    QSqlQuery query;
    QString userStr = "DELETE FROM File WHERE fid = :fid";
    query.prepare(userStr);
    query.bindValue(":fid", fid);
    query.exec();
}

void Database::getFile(QString fid) {
    QSqlQuery query;
    QString userStr = "SELECT * FROM File WHERE fid = :fid";
    query.prepare(userStr);
    query.bindValue(":fid", fid);
    if (query.exec()) {
        while (query.next()) {
            QString msg = query.value(1).toString();
            qDebug() << msg;
        }
    } else {
       qDebug() << "Oops " << db.lastError().text();
    }
}

void Database::setConnections(QString dbName) {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();

    QString dsn = "DRIVER = {SQL Native Client}; SERVER = MSSQLSERVER; DATABASE = " + dbName + "; Trusted_Connection=Yes;";
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

