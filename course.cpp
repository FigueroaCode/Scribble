#include "course.h"

#include <QString>

Course::Course()
{
    instructorName = "";
    courseID = "";
    courseName = "";
    institution = "";
}

QString Course::getInstructorName(){
    return instructorName;
}

QString Course::getCourseID(){
    return courseID;
}

QString Course::getCourseName(){
    return courseName;
}

QString Course::getInstitution(){
    return institution;
}

void Course::setInstructorName(QString instructor){
    instructorName = instructor;
}

void Course::setCourseID(QString id){
    courseID = id;
}

void Course::setCourseName(QString name){
    courseName = name;
}

void Course::setInstitution(QString school){
    institution = school;
}
