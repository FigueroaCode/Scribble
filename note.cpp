#include "note.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Note::Note(){}

Note::Note(QString filename)
{
    QFile file(filename);

    // Check if file didnt open in read only
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    // loop through text file
    while(!in.atEnd()){
        QString line = in.readLine();
        text += line + "\n";
    }

    file.close();

    //initialize sentence vector
    findSentences();
}

QString Note::getText(){
    return text;
}

void Note::showNote(){

}
void Note::findSentences(){
    QString currentWord = "";
    QString currentSentence = "";
    for(int i = 0; i < text.size(); i++){
        if(text.at(i) == ' '){
            currentWord = "";
        }else{
            currentWord += text.at(i);
        }
        if(isPunctuation(text.at(i)) && !isTitle(currentWord)){
            // ---Doesnt add the period to the sentence---
            sentences.append(currentSentence);
            currentSentence = "";
        }else{
            currentSentence += text.at(i);
        }
    }
}
bool Note::isTitle(QString word){
    QString titles[4] = {
        "mr","ms","dr","ex",
    };

    for(int i = 0; i < 4; i++){
        if(word == titles[i])
            return true;
    }

    return false;
}
bool Note::isPunctuation(QChar p){
    char punct[3] = {
        '.','?','!'
    };
    for(int i = 0; i < 3; i++){
        if(p == punct[i])
            return true;
    }

    return false;
}
QVector<QString> Note::getSentences(){
     return sentences;
 }
