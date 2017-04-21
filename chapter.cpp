#include "chapter.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QResource>
#include <QIODevice>

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

void Chapter::setMainNote(Note* note)
{
    mainNote = note;
}

Note* Chapter::getMainNote()
{
    return mainNote;
}

QString Chapter::getChapterName(){return chapterName;}
void Chapter::findDifferences(Note* note)
{
    //eMNS stands for Edited Main Note Sentences
    //eNNS stands for Edited New Note Sentences
    QVector<QVector<QString>> eMNS = getMainNote()->getEditedSentences();
    QVector<QVector<QString>> eNNS = note->getEditedSentences();
    //oMNS stands for Original Main Note Sentences
    //oNNS stands for Original New Note Sentences
    //These variable names were too long, so I made them into acronyms. - Luis
    QVector<QString> oMNS = getMainNote()->getOriginalSentences();
    QVector<QString> oNNS = note->getOriginalSentences();

    int currentSimilarityPercent = 0;
    int largestSimilarityPercent = 0;
    int largestSimilarityIndex;
    int previousSimilarIndex = eMNS.size()-1;

    //Compare all sentences to each other.
    for(int newIndex = 0; newIndex < eNNS.size(); newIndex++)
    {
        QVector<QString> newSentence = eNNS.at(newIndex);

        for(int originalIndex = 0; originalIndex < eMNS.size(); originalIndex++)
        {
            QVector<QString> mainSentence = eMNS.at(originalIndex);

            //Account for all cases when comparing these sentences.
            currentSimilarityPercent = this->compareSentences(newSentence, mainSentence);

            if(currentSimilarityPercent >= largestSimilarityPercent)
            {
                largestSimilarityPercent = currentSimilarityPercent;
                largestSimilarityIndex = originalIndex;
            }
        }

        //Analyze similarity then proceed.
        if(largestSimilarityPercent <= 100)
        {
            if(largestSimilarityPercent >= 90){
                //These sentences are far too similar, and should not be considered for changes.

            }else if(largestSimilarityPercent < 90 && largestSimilarityPercent >= 30){
                //These sentences are in a good range of similarity, and should be considered for changes.
                QString originalSentence = oMNS.at(largestSimilarityIndex);
                QString newSentence = oNNS.at(newIndex);

                //Add these two sentences to a Change object and add that change object to the changeLog.
                Change* change = new Change(originalSentence, newSentence, largestSimilarityIndex);
                note->addChange(change);
            }else if(largestSimilarityPercent < 30){
                //These sentences are completely new, or too dissimilar from other sentences to be compared.
                //We must append them to the appropriate location within the original text.
                //In order to do this, we want to place it right after the sentence most similar to the sentence
                //prior to this unique sentence.
                QString newSentence = oNNS.at(newIndex);

                Change* change = new Change("This is a new entry.", newSentence, previousSimilarIndex+1);
                note->addChange(change);
            }
        }else{
            qDebug()<<"Some error ocurred. Similarity was above 100%";
        }

        //Set a previous similarity index in case the next sentence is an insertion. We can insert it after this index.
        previousSimilarIndex = largestSimilarityIndex;

        largestSimilarityPercent = 0;
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
            word1 = word1.toLower();
            word2 = word2.toLower();

            if(word1 == word2 || this->isSynonym(word1, word2) || this->isSynonym(word2, word1))
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

    percentSimilarity = (similarWords*100/totalWords);
    return percentSimilarity;
}

/*
 * Compares two words and determines if they are synonyms in the thesaurus reference file.
 * A word is not a synonym to itself.
 * */
bool Chapter::isSynonym(QString word1, QString word2)
{
    QString thesaurus = "";
    QFile thesaurusFile(":/resources/thesaurus.txt");
    QTextStream in(&thesaurusFile);

     thesaurusFile.open(QIODevice::ReadOnly);
     thesaurus = in.readAll();
     thesaurusFile.close();

     bool found = false;
     QStringList thesaurusList;
     QString synonyms;
     QString line; QString word;
     QRegExp rx("(\\,|\\:)");

     //checks that the word is in the thesaurus
     int word1Location = thesaurus.indexOf(word1 + "|");
     if(word1Location == -1)
     {
        return false;
     }

     //splits the thesaurus file line by line
     while(!thesaurusFile.atEnd())
     {
         line = in.readLine();
         thesaurusList.push_back(line);
     }

     //finds the line where word1 is located
     for (int i = 0; i < thesaurusList.length(); i++)
     {
         word = thesaurusList.at(i).mid(0, word1.length() + 1);
         if (word.compare(word1 + "|"))
         {
             synonyms = thesaurusList.at(i);
         }
     }

     //separates individual synonyms by commas and colons and trims whitespace from beginning and end of each word
     QStringList synList = synonyms.split(rx, QString::SkipEmptyParts);
     for (int i = 0; i < synList.length(); i++)
     {
         synList.replaceInStrings(synList.at(i), synList.at(i).trimmed());
     }

     for (int i = 0; i < synList.length(); i++)
     {
         //qDebug()<< synList.at(i) << endl;
         if (synList.at(i).compare(word2) == 0)
         {
             found = true;
         }
     }

     if (found)
     {
         //qDebug()<<word1 <<" and " << word2 << " are synonyms.";
     }
     else
     {
         //qDebug()<<word1 <<" and " << word2 << " are NOT synonyms.";
     }

     return found;
}

void Chapter::mergeNotes(Change* change)
{
    Note* mainNote = this->getMainNote();
    QVector<QString> originalSentences = mainNote->getOriginalSentences();
    QString noPrevSentence = "This is a new entry.";
    qDebug()<<mainNote->getOriginalSentences();
    //Replace the sentence or make an insertion in a QVector of sentences.
    if(change->getOriginalSentence() == noPrevSentence)
    {
        //This is an insertion.
        originalSentences.insert(change->getIndexOfChange(), change->getProposedSentence());
    }else{
        //This is a replacement.
        originalSentences.remove(change->getIndexOfChange());
        originalSentences.insert(change->getIndexOfChange(), change->getProposedSentence());
        //qDebug()<<change->getProposedSentence();
    }

    QString amendedText = "";
    for(int i = 0; i < originalSentences.size(); i++)
    {
        amendedText += originalSentences.at(i) + " ";
    }
           // qDebug()<<mainNote->getText();
    mainNote->editNote(amendedText);
    mainNote->setOriginalSentence(originalSentences);

}
