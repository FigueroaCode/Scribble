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

Note* Chapter::getMainNote()
{
    return mainNote;
}

void Chapter::findDifferences(Note* note)
{
    QVector<QVector<QString>> mainNoteSentences = getMainNote()->getEditedSentences();
    QVector<QVector<QString>> newNoteSentences = note->getEditedSentences();
    QVector<QString> originalMainNoteSentences = getMainNote()->getOriginalSentences();
    QVector<QString> originalNewNoteSentences = getMainNote()->getOriginalSentences();
    QVector<QString> sentenceGroup;
    QVector<QVector<QString>> similarSentences;

    const int UPPERTHRESHOLD = 95;
    const int LOWERTHRESHOLD = 30;

}

int Chapter::compareSentences(QVector<QString> sentence1, QVector<QString> sentence2)
{
    return 0;
}

bool Chapter::isSynonym(QString word1, QString word2)
{
    QString thesaurus = "";
    QFile thesaurusFile(":/resources/thesaurus.txt");
    QTextStream in(&thesaurusFile);

    thesaurusFile.open(QIODevice::ReadOnly);

    thesaurus = in.readAll();

    thesaurusFile.close();

    return false;
}

//void Chapter::mergeNotes(Note* note)
//{

//}
