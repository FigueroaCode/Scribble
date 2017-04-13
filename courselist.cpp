#include "courselist.h"
#include <QString>
#include <QDebug>
using namespace std;

CourseList::CourseList()
{

}

QString CourseList::sortName(QString name){
    QString courseName;
    for(int i = 0; i < courses.size() ; i ++){
        if (courses.at(i)->getCourseName() == name){
            courseName = courses.at(i)->getCourseName();

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

Course* CourseList::getCourse(QString name){
    for(int i = 0; i < courses.size() ; i ++){
        if(courses.at(i)->getCourseName() == name){
            return courses.at(i);
        }
    }
    return NULL;
}

void CourseList::addCourse(Course* course){
    courses.append(course);
}

