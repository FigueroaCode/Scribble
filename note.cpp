#include "note.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Note::Note(){}

Note::Note(QString filename)
{
    QFile file(filename);
    editedText = "";
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

    //remove articles and symbols that arent needed
    removeSymbolsArticles();
    //initialize sentence vector
    findSentences();
}

QString Note::getText(){
    return text;
}
QString Note::getEditedText(){
    return editedText;
}

void Note::showNote(){

}
void Note::findSentences(){
    QString currentWord = "";
    QString currentSentence = "";
    QVector<QString> wordSentence;

    for(int i = 0; i < editedText.size(); i++){
        if(editedText.at(i) == ' '){
            if(!isArticle(currentWord) && !currentWord.isEmpty()){
                wordSentence.append(currentWord);
            }
            currentWord = "";
        }else{
            currentWord += editedText.at(i);
        }
        if(isPunctuation(editedText.at(i)) && !isTitle(currentWord)){
            // ---Doesnt add the period to the sentence---
            words.append(wordSentence);
            sentences.append(currentSentence);
            currentSentence = "";
            currentWord = "";
        }else{
            currentSentence += editedText.at(i);
        }
    }
}
void Note::removeSymbolsArticles(){
    for(int i = 0; i < text.size(); i++){
        if(!isSymbol(text.at(i))){
            //not a symbol
            //add to edited text
            editedText += text.at(i);
        }
    }
}
bool Note::isArticle(QString article){
    QString articles[3] = {
        "the","a","an",
    };

    for(int i = 0; i < 3;i++){
        if(article.toLower() == articles[i])
            return true;
    }

    return false;
}
bool Note::isSymbol(QChar symbol){
    //take care fo exceptions first
    if(isPunctuation(symbol))
        return false;
    if(symbol == '%' || symbol == '@' || symbol == '$' || symbol == ' ' || symbol == '\'')
        return false;
    else if(symbol >= 48 && symbol <= 57)//its a number in this case
        return false;
    else if(!(symbol >= 65 && symbol <= 90) //not uppercase letter
            && !(symbol >= 97 && symbol <= 122))//not lower case letter
    {
        return true;
    }

    return false;
}
bool Note::isTitle(QString word){
    QString titles[4] = {
        "mr","ms","dr","ex",
    };

    for(int i = 0; i < 4; i++){
        if(word.toLower() == titles[i])
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
QVector<QVector<QString>> Note::getWords(){
    return words;
}
