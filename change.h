#ifndef CHANGE_H
#define CHANGE_H

#include <QVector>

class Change
{
public:
    Change();
    Change(QString originalSentence, QString proposedSentence);
    void upVote();
    void downVote();
    int getVoteCount();
private:
    QVector<QString> words;
    bool isConfirmed = false;
    int voteCount = 0;
};

#endif // CHANGE_H
