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

bool Course::textbookExist(Textbook* txtbook){
   return textbooks.contains(txtbook);
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

int Course::findIndex(QString name){
    for(int i = 0; i < textbooks.size(); i++){
        if(textbooks.at(i)->getTextbookName() == name)
            return i;
    }

    return -1;
}
