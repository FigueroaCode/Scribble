#include "textbook.h"

Textbook::Textbook()
{
    textbookName = "";
}

QString Textbook::getTextbookName(){
    return textbookName;
}

bool Textbook::chapterExists(Chapter *chapter){
    return chapters.contains(chapter);
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

int Textbook::findIndex(QString chapter){
    for(int i = 0; i < chapters.size(); i++){
        if(chapters.at(i)->getChapterName() == chapter){
            return i;
        }
    }
    return -1;
}
