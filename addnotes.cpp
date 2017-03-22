#include "addnotes.h"
#include "ui_addnotes.h"
#include <QFileDialog>
#include <QDir>
#include "note.h"

AddNotes::AddNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNotes)
{
    ui->setupUi(this);
}

AddNotes::~AddNotes()
{
    delete ui;
}

void AddNotes::on_pushButton_clicked()
{
    //------ Open File explorer so user can select the file, then save path in string
      QString filename = QFileDialog::getOpenFileName(
                  this,
                  "Open File",
                  QDir::currentPath(),
                  "All Files (*.*);; Text File (*.txt)"
                  );

    Note myNote(filename);
    ui->textEdit->setText(myNote.getFileText());
}
