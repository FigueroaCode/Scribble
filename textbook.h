#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <QVector>
#include "student.h"
#include "chapter.h"

//QVector methods:
//QVector<type> name; to initialize
//name.push_back(value) insert a value of <type> to the end of the QVector.
//name.at(index) returns the element at that index.
//name.size() returns an unsigned integer equal to the size of the QVector.
//name.begin() reads through the QVector, beginning with index 0.
//name.insert( name.begin() + x, value) insert a value just before 'x' spaces after the first index.
//name.clear() erases all elements from the QVector.
//name.isEmpty() returns a boolean determining whether the QVector is empty or not.

class Textbook
{
public:
    Textbook();
    void createChapter(QString chapterName, Note mainNote);
    void createChapter(QString chapterName);
    void deleteChapter(Chapter chapter);
    void grantAdmin(Student student);
    bool isAdmin(Student student);
    void setOriginalAdmin(Student student);
    Student getOriginalAdmin();
private:
    Student originalAdmin;
    QVector<Student> admins;
};

#endif // TEXTBOOK_H
