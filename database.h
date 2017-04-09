#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QSqlDatabase>

class Database
{
public:
    QSqlDatabase db;
    Database(QString dbName);

    //Student-related Methods
    void addStudent(QString studentName, QString passcode);
    void removeStudent(QString sid);
    void getStudent(QString sid);

    //Course-related Methods attributes votes
    void addCourse(QString courseNum, QString courseName);
    void removeCourse(QString cid);
    void getCourse(QString cid);

    //File-related Methods
    void addFile(QString file);
    void removeFile(QString fid);
    void getFile(QString fid);

private:
    void setConnections(QString dbName);
    void closeDatabase();

};


#endif // DATABASE_H


