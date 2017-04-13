#include "course.h"

#include <QString>

Course::Course()
{
    courseName = "";
}

QString Course::getCourseName(){
    return courseName;
}

QVector<Textbook*> Course::getTextbooks(){
    return textbooks;
}

Textbook* Course::getTextbook(int index){
    return textbooks.at(index);
}

void Course::addTextbook(Textbook* textbook){
    textbooks.append(textbook);
}

void Course::removeTextbook(int index){
    textbooks.remove(index);
}

void Course::setCourseName(QString name){
    courseName = name;
}

