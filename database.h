
#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QSqlDatabase>



#include <QString>
class Database
{
public:
    QSqlDatabase db;
    Database();

    //Student-related Methods
    void addStudent(QString studentName, QString passcode);
    void removeStudent(QString sid);
    QString getStudent(QString sid);

    //Course-related Methods attributes votes
    void addCourse(QString courseName);
    void removeCourse(QString cid);
    QString getCourse(QString cid);

    //Chapter-related Methods
    void addChapter(QString chapterName,QString courseName, QString date);
    void removeChapter(QString chapterName, QString courseName, QString date);
    QString getChapter(QString chapterName, QString courseName, QString studentId,QString date);

    //Notes-related Methods
    void addNote(QString courseName,QString chapterName,QString date, QString studentId, QString contents);
    void removeNote(QString courseName,QString chapterName,QString studentId);
    QString getNote(QString courseName,QString chapterName,QString studentId);

private:
    void setConnections();
    void closeDatabase();

};



#endif // DATABASE_H

