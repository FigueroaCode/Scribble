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
    Course *getCourse(QString name);
    void addCourse(Course* course);

};

#endif // COURSELIST_H
