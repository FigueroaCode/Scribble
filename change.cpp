#include "change.h"

Change::Change()
{
    //This shouldn't ever run.
}

Change::Change(QString originalSentence, QString proposedSentence, int index)
{
    this->originalSentence = originalSentence;
    this->proposedSentence = proposedSentence;
    this->isConfirmed = false;
    this->indexOfChange = index;
}

void Change::setSimilarity(int sim)
{
    similarity = sim;
}

int Change::getSimilarity()
{
    return similarity;
}

QString Change::getOriginalSentence()
{
    return originalSentence;
}

QString Change::getProposedSentence()
{
    return proposedSentence;
}

int Change::getIndexOfChange()
{
    return indexOfChange;
}
