#ifndef COURSE_H
#define COURSE_H

#include <QString>


class Course
{
private:
    QString instructorName;
    QString courseID;
    QString courseName;
    QString institution;
public:
    Course();
    QString getInstructorName();
    QString getCourseID();
    QString getCourseName();
    QString getInstitution();
    void setInstructorName(QString instructor);
    void setCourseID(QString id);
    void setCourseName(QString name);
    void setInstitution(QString school);
};

#endif // COURSE_H
