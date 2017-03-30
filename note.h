#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include "change.h"
#include <QDateTime>

class Note
{
private:
    QString text;
    QString editedText;
    bool underVote;
    // --- change into vectors ---
//    QString sentences[10];
//    Change changeLog[10];
//    Change confirmedChanges[10];


public:
    Note();
    Note(QString filename);
    QString getText();
    void showNote();
    void allowVoting(QDateTime time);
    QString removeArticles();
//    QString separateToSentences()[10];
//    QString separateToWords()[10];
    void editNote();
};

#endif // NOTE_H
