#ifndef CHANGE_H
#define CHANGE_H

#include <vector>
#include <string>

class Change
{
public:
    Change();
    Change(string originalSentence, string proposedSentence);
    void upVote();
    void downVote();
    int getVoteCount();
private:
    vector<string> words;
    bool isConfirmed = false;
    int voteCount = 0;
};

#endif // CHANGE_H
