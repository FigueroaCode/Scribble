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
    ~AddNotes();

private slots:

    void on_addFileBtn_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddNotes *ui;
    QString os;
};

#endif // ADDNOTES_H
