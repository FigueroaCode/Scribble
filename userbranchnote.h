#ifndef USERBRANCHNOTE_H
#define USERBRANCHNOTE_H

#include "note.h"
#include <QString>

class UserBranchNote: public Note
{
private:
    Note* note;
public:
    UserBranchNote(QString filename);
};

#endif // USERBRANCHNOTE_H
