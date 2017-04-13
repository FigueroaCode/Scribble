#include "textbook.h"

Textbook::Textbook()
{
    textbookName = "";
}

QString Textbook::getTextbookName(){
    return textbookName;
}

void Textbook::setTextbookName(QString name){
    textbookName = name;
}

QVector<Chapter*> Textbook::getChaptersList(){
    return chapters;
}

Chapter* Textbook::getChapter(int index){
    return chapters.at(index);
}

void Textbook::addChapter(Chapter* chapter){
    chapters.append(chapter);
}

void Textbook::removeChapter(int index){
    chapters.remove(index);
}
