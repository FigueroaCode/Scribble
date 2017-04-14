#ifndef COURSELIST_H
#define COURSELIST_H

#include <QString>
#include <QVector>
#include "course.h"


class CourseList
{
private:
    QVector<Course*> courses;
public:
    CourseList();
    QString sortName(QString name);
    bool courseExist(QString name);
    Course *getCourse(int index);
    void addCourse(Course* course);
    int getSize();


};

#endif // COURSELIST_H
