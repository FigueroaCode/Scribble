#include "change.h"

Change::Change()
{
    //This shouldn't ever run.
}

Change::Change(QString originalSentence, QString proposedSentence)
{
    this->originalSentence = originalSentence;
    this->proposedSentence = proposedSentence;
    this->isConfirmed = false;
    this->voteCount = 0;
}

void Change::upVote()
{
    voteCount++;
}

void Change::downVote()
{
    voteCount--;
}

int Change::getVoteCount()
{
    return voteCount;
}

QString Change::getOriginalSentence()
{
    return originalSentence;
}

QString Change::getProposedSentence()
{
    return proposedSentence;
}
