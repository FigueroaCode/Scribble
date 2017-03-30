#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include "change.h"
#include <QDateTime>
#include <QVector>

class Note
{
private:
    QString text;
    QString editedText;
    bool underVote;
    QVector<QString> sentences;
    QVector<Change> changeLog;
    QVector<Change> confirmedChanges;

public:
    Note();
    Note(QString filename);
    QString getText();
    void showNote();
    void allowVoting(QDateTime time);
    void editNote();
    QVector<QString> getSentences;
    QVector<Change> getChangeLog;
    QVector<Change> getConfirmedChanges;
};

#endif // NOTE_H
