#include "courselist.h"
#include <QString>
#include <QDebug>
using namespace std;

CourseList::CourseList()
{

}

QString CourseList::sortName(QString name){
    QString courseName;
    QString courseTeacher;
    for(int i = 0; i < courses.size() ; i ++){
        if (courses.at(i)->getCourseName() == name){
            courseName = courses.at(i)->getCourseName();
            courseTeacher = courses.at(i)->getInstructorName();
            qDebug() << courseName << ", " << courseTeacher << endl;
        }
    }

    return "";
}

QString CourseList::sortByID(QString id){
    QString courseID;
    QString courseName;
    for(int i = 0; i < courses.size(); i++){
        if(courses.at(i)->getCourseID() == id){
            courseID = courses.at(i)->getCourseID();
            courseName = courses.at(i)->getCourseName();
            qDebug() << courseID << ", " << courseName << endl;
        }
    }

    return "";
}

QString CourseList::sortByProfessor(QString professor){
    QString courseTeacher;
    QString courseName;
    for(int i = 0; i < courses.size(); i ++){
        if (courses.at(i)->getInstructorName() == professor){
            courseTeacher = courses.at(i)->getInstructorName();
            courseName = courses.at(i)->getCourseName();
            qDebug() << courseTeacher << ", " << courseName << endl;
        }
    }

    return "";
}

QString CourseList::sortByInstitution(QString institution){
    QString courseSchool;
    QString courseName;
    for(int i = 0; i < courses.size(); i ++){
        if(courses.at(i)->getInstitution() == institution){
            courseSchool = courses.at(i)->getInstitution();
            courseName = courses.at(i)->getCourseName();
            qDebug() << courseSchool << ", " << courseName << endl;
        }
    }

    return "";
}

bool CourseList::courseExist(QString name){
    for(int i = 0; i < courses.size() ; i ++){
        if(courses.at(i)->getCourseName() == name){
            return true;
        }
    }
    return false;
}

Course* CourseList::getCourse(QString name, QString id){
    for(int i = 0; i < courses.size() ; i ++){
        if(courses.at(i)->getCourseName() == name && courses.at(i)->getCourseID() == id){
            return courses.at(i);
        }
    }
    return NULL;
}

void CourseList::addCourse(Course* course){
    courses.append(course);
}

