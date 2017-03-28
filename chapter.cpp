#include "chapter.h"

Chapter::Chapter()
{
    //This should never be called, and therefore does nothing.
}

Chapter::Chapter(string name)
{
    //Creates a chapter with the dictated name.
    //No Note was provided, therefore an empty Note will be created for its mainNote.
    chapterName = name;
    mainNote = new Note();
}

Chapter::Chapter(string name, Note note)
{
    //Creates a chapter with the dictated name.
    //Designates the given note to be the main Note.
    chapterName = name;
    mainNote = note;
}

Chapter::callVote()
{
    //To-Do:
    //Implement a UI which allows the user to pick a date and time
    //at which the vote will end.
}

Chapter::findDifferences(Note note)
{

}

Chapter::isSynonym()
{

}

Chapter::mergeNotes(UserBranchNote note)
{

}
