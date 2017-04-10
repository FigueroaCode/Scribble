#include "student.h"

Student::Student()
{
    studentName = "";
    studentEmail = "";
    studentUsername = "";
    bool hasVoted = false;
}

QString Student::getName(){
    return studentName;
}

QString Student::getEmail(){
    return studentEmail;
}

QString Student::getUserName(){
    return studentUsername;
}

bool Student::voteStatus(){
    return hasVoted;
}

void Student::setName(QString name){
    studentName = name;
}

void Student::setEmail(QString email){
    studentEmail = email;
}

void Student::setUsername(QString username){
    studentUsername = username;
}

void Student::setUserStatus(bool status){
    hasVoted = status;
}
