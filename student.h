#ifndef STUDENT_H
#define STUDENT_H

#include <QString>


class Student
{
private:
    QString studentName;
    QString studentEmail;
    QString studentUsername;
    bool hasVoted;
public:
    Student();
    QString getName();
    QString getEmail();
    QString getUserName();
    bool voteStatus();
    void setName(QString name);
    void setEmail(QString email);
    void setUsername(QString username);
    void setUserStatus(bool status);
};

#endif // STUDENT_H
