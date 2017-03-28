#ifndef CHAPTER_H
#define CHAPTER_H

#include <QString>
#include <QDateTime>

class Chapter
{
public:
    Chapter();
    Chapter(string ChapterName);
    Chapter(string ChapterName);
    void callVote();
    void findDifferences(Note note);
    bool isSynonym(string word);
    void mergeNotes(UserBranchNote note);
private:
    QString ChapterName;
    Note mainNote;
};

#endif // CHAPTER_H
