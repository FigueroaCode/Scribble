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

Note* Chapter::getMainNote()
{
    return mainNote;
}

void Chapter::callVote()
{
    //To-Do:
    //Implement a UI which allows the user to pick a date and time
    //at which the vote will end.
}

void Chapter::findDifferences(Note* note)
{
    QVector<QVector<QString>> mainNoteSentences = getMainNote()->getWords();
    QVector<QVector<QString>> newNoteSentences = note->getWords();
    QVector<QVector<QString>> sentenceGroup;
    QVector<QVector<QVector<QString>>> similarSentences;

    //Compare sentences of the current Main Note to the newly submitted Note.
    for(int i = 0; i < newNoteSentences.size(); i++)
    {
        for(int j = 0; j < mainNoteSentences.size(); j++)
        {
            QVector<QString> newSentence = newNoteSentences.at(i);
            QVector<QString> mainSentence = mainNoteSentences.at(j);

            int sentenceSimilarity = compareSentences(newSentence, mainSentence);

            //If two sentences are similar above a 60% degree of similarity
            //Add these two to a temporary group, and add this group to a
            //Vector of sentences grouped by similarity.
            if(sentenceSimilarity >= 60)
            {
                sentenceGroup.push_back(mainSentence);
                sentenceGroup.push_back(newSentence);
                similarSentences.push_back(sentenceGroup);
                sentenceGroup.clear();
            }
        }
    }

    //Create a Change object for each sentence group.
    for(int i = 0; i < similarSentences.size(); i++)
    {

    }
}

int Chapter::compareSentences(QVector<QString> sentence1, QVector<QString> sentence2)
{
    int percentSimilarity;
    int similarWords = 0;
    int totalWords;

    //Compare words across both sentences to one another.
    for(int i = 0; i < sentence1.size(); i++)
    {
        for(int j = 0; j < sentence2.size(); j++)
        {
            QString word1 = sentence1.at(i);
            QString word2 = sentence2.at(j);

            //NOTE THIS NEEDS TO LATER ACCOUNT FOR SYNONYMS AS WELL.
            if(word1 == word2)
            {
                similarWords++;
            }
        }
    }

    //Total words should actually equal the word count of the longest sentence.
    if(sentence1.size() > sentence2.size())
    {
        totalWords = sentence1.size();
    }else{
        totalWords = sentence2.size();
    }

    percentSimilarity = (similarWords/totalWords) * 100;

    return percentSimilarity;
}

//bool Chapter::isSynonym()
//{

//}

//void Chapter::mergeNotes(UserBranchNote* note)
//{

//}
