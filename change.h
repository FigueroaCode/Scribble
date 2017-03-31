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
    QString getOriginalSentence();
    QString getProposedSentence();
private:
    QString originalSentence;
    QString proposedSentence;
    bool isConfirmed;
    int voteCount;
};

#endif // CHANGE_H
