#ifndef NOTE_H
#define NOTE_H

#include <QString>
class Note
{
private:
    QString fileText;
public:
    Note(QString filename);
    QString getFileText();
};

#endif // NOTE_H
