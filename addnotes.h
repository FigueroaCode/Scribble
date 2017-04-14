#ifndef ADDNOTES_H
#define ADDNOTES_H

#include <QDialog>

namespace Ui {
class AddNotes;
}

class AddNotes : public QDialog
{
    Q_OBJECT

public:
    explicit AddNotes(QWidget *parent = 0);
    void setText(QString filepath);
    ~AddNotes();

private:
    Ui::AddNotes *ui;
};

#endif // ADDNOTES_H
