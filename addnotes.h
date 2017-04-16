#ifndef ADDNOTES_H
#define ADDNOTES_H

#include <QDialog>
#include "note.h"

namespace Ui {
class AddNotes;
}

class AddNotes : public QDialog
{
    Q_OBJECT

public:
    explicit AddNotes(QWidget *parent = 0);
    void setNote(QString filepath);
    void setFilePath(QString path);
    ~AddNotes();

private slots:
    void on_saveChangesBtn_clicked();

private:
    Ui::AddNotes *ui;
    Note* note;
};

#endif // ADDNOTES_H
