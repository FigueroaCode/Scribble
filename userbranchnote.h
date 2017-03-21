#ifndef USERBRANCHNOTE_H
#define USERBRANCHNOTE_H

#include "note.h"

class UserBranchNote: public Note
{
private:
    Note* note;
public:
    UserBranchNote();
};

#endif // USERBRANCHNOTE_H
