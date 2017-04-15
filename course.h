#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QVector>
#include "textbook.h"

class Course
{
private:
    QString courseName;
    QVector<Textbook*> textbooks;

public:
    Course();
    QString getCourseName();
    QVector<Textbook*> getTextbooks();
    bool textbookExist(Textbook* txtbook);
    Textbook* getTextbook(int index);
    void addTextbook(Textbook* textbook);
    void removeTextbook(int index);
    void setCourseName(QString name);
    int findIndex(QString name);
};

#endif // COURSE_H
