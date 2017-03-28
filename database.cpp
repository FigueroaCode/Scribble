#include "database.h"

Database::Database()
{
  public:
    QSqlDatabase db;
    //Constructor
    Database(QString serverName, QString dbName) {
        setConnections(serverName, dbName);
    }
    
    void createTable();

    //Student-related Methods
    void addStudent(QString studentName, QString passcode) {
        QSqlQuery query;
        String sid;
        query.exec("SELECT * FROM Student");

        QSqlDatabase defaultDB = QSqlDatabase::database();
        if (defaultDB.driver() ->hasFeature(QSqlDriver :: QuerySize)) {
            sid = query.size() + 1;
        } else {
            query.last();
            sid = query.at() + 2;
        }

        QSqlQuery2 query2;
        QString queryString = "INSERT INTO Student (sid, sname, passcode) VALUES (sid, studentName, passcode)");

        query2.prepare(queryString);

    }
  
    void removeStudent(QString sid) {
        QSqlQuery query;
        query.exec("DELETE FROM Student WHERE sid = %1", sid);
    }
  
    void getStudent(QString sid) {
        QSqlQuery query;

        if (query.exec("SELECT * FROM Student WHERE sid = %1", sid)) {
            while (query.next()) {
                qDebug << query.value(1).toString();
            }
        } else {
           qDebug << "Oops " << db.lastError().text();
        }

    }

    //Course-related Methods attributes votes
    void addCourse(QString courseNum, QStrig courseName) {
        QSqlQuery query;
        QString queryString = "INSERT INTO Course (courseNum, courseName) VALUES (courseNum, courseName)");
        query.prepare(queryString);
    }
  
    void removeCourse(QString cid) {
        QSqlQuery query;
        query.exec("DELETE FROM Course WHERE cid = %1", cid);
    }
  
    void getCourse(QString cid) {
        QSqlQuery query;

        if (query.exec("SELECT * FROM Course WHERE cid = %1", cid)) {
            while (query.next()) {
                qDebug << query.value(1).toString();
            }
        } else {
           qDebug << "Oops " << db.lastError().text();
        }
    }

    //File-related Methods
    void addFile(QString file) {
        QSqlQuery query;
        String fid;
        query.exec("SELECT * FROM File");

        QSqlDatabase defaultDB = QSqlDatabase::database();
        if (defaultDB.driver() ->hasFeature(QSqlDriver :: QuerySize)) {
            fid = query.size() + 1;
        } else {
            query.last();
            fid = query.at() + 2;
        }

        QSqlQuery2 query2;
        QString queryString = "INSERT INTO File (fid, file) VALUES (fid, file)");

        query2.prepare(queryString);
    }
  
    void removeFile(QString fid) {
        QSqlQuery query;
        query.exec("DELETE FROM File WHERE fid = %1", fid);
    }
  
    void getFile(QString fid) {
        QSqlQuery query;

        if (query.exec("SELECT * FROM File WHERE sid = %1", fid)) {
            while (query.next()) {
                qDebug << query.value(1).toString();
            }
        } else {
           qDebug << "Oops " << db.lastError().text();
        }
    }

private:
    void setConnections(QString serverName, QString dbName) {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setConnectOptions();

        QString dsn = QString("DRIVER = {SQL Native Client}; SERVER = %1; DATABASE = %2; Trusted_Connection=Yes;", serverName, dbName);
        db.setDatabaseName(dsn);
        if (db.open()) {
            qDebug << "open successfully";
        } else {
            qDebug << "Oops " << db.lastError().text();
        }
    }
    
    void closeDatabase() {
        db.close();
    }

};


}
