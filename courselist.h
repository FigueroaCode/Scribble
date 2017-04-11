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
    QString sortByID(QString id);
    QString sortByProfessor(QString professor);
    QString sortByInstitution(QString institution);
    bool courseExist(QString name);
    Course *getCourse(QString name, QString id);
    void addCourse(Course* course);

};

#endif // COURSELIST_H
