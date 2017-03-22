#include "note.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
        fileText += line + "\n";
    }

    file.close();
}

QString Note::getFileText(){
    return fileText;
}
