#ifndef CHAPTER_H
#define CHAPTER_H

#include <QString>
#include <QDateTime>
#include "note.h"

class Chapter
{
public:
    Chapter();
    Chapter(QString ChapterName);
    Chapter(QString ChapterName, Note* note);
    void findDifferences(Note* note);
    bool isSynonym(QString word1, QString word2);
    void mergeNotes(Note* note);
    Note* getMainNote();
    int compareSentences(QVector<QString> sentence1, QVector<QString> sentence2);
private:
    QString chapterName;
    Note* mainNote;
};

#endif // CHAPTER_H
