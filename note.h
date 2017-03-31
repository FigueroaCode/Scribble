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
    QVector<QVector<QString>> words;
    QVector<Change> changeLog;
    QVector<Change> confirmedChanges;

public:
    Note();
    Note(QString filename);
    QString getText();
    QString getEditedText();
    void showNote();
    void allowVoting(QDateTime time);
    void editNote();
    void findSentences();
    void removeSymbols();
    bool isArticle(QString article);
    bool isSymbol(QChar symbol);
    bool isTitle(QString word);
    bool isPunctuation(QChar p);
    QVector<QString> getSentences();
    QVector<QVector<QString>> getWords();
    QVector<Change> getChangeLog();
    QVector<Change> getConfirmedChanges();
};

#endif // NOTE_H
