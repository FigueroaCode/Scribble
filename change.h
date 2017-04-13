#ifndef CHANGE_H
#define CHANGE_H

#include <QVector>

class Change
{
public:
    Change();
    Change(QString originalSentence, QString proposedSentence, int index);
    void setSimilarity(int sim);
    int getSimilarity();
    QString getOriginalSentence();
    QString getProposedSentence();
    int getIndexOfChange();
private:
    QString originalSentence;
    QString proposedSentence;
    bool isConfirmed;
    int similarity;
    int indexOfChange;
};

#endif // CHANGE_H
