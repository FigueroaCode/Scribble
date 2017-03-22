#ifndef USERBRANCHNOTE_H
#define USERBRANCHNOTE_H

#include "note.h"
#include <QString>

class UserBranchNote: public Note
{
private:
    Note* note;
public:
    UserBranchNote();
    UserBranchNote(QString filename);
    // ----change to vector----
    //Change[] compareToMain();
};

#endif // USERBRANCHNOTE_H
