#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <QVector>
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
private:
    QString textbookName;
    QVector<Chapter*> chapters;
public:
    Textbook();
    QString getTextbookName();
    bool chapterExists(Chapter* chapter);
    void setTextbookName(QString name);
    QVector<Chapter*> getChaptersList();
    Chapter* getChapter(int index);
    void addChapter(Chapter* chapter);
    void removeChapter(int index);
    int findIndex(QString chapter);
};

#endif // TEXTBOOK_H
