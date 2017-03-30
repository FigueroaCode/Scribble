#include "chapter.h"

Chapter::Chapter()
{
    //This should never be called, and therefore does nothing.
}

Chapter::Chapter(QString name)
{
    //Creates a chapter with the dictated name.
    //No Note was provided, therefore an empty Note will be created for its mainNote.
    chapterName = name;
    mainNote = new Note();
}

Chapter::Chapter(QString name, Note* note)
{
    //Creates a chapter with the dictated name.
    //Designates the given note to be the main Note.
    chapterName = name;
    mainNote = note;
}

void Chapter::callVote()
{
    //To-Do:
    //Implement a UI which allows the user to pick a date and time
    //at which the vote will end.
}

void Chapter::findDifferences(Note* note)
{
//    mainNoteText = getMainNote().getEditedText();
//    newNoteText = note.getEditedText();


}

Note* Chapter::getMainNote()
{
    return mainNote;
}

//bool Chapter::isSynonym()
//{

//}

//void Chapter::mergeNotes(UserBranchNote* note)
//{

//}
