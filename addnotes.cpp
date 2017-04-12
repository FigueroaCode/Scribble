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
    ui->textEdit->setReadOnly(true);
}

AddNotes::~AddNotes()
{
    delete ui;
}

//void AddNotes::on_addFileBtn_clicked()
//{
//    //------ Open File explorer so user can select the file, then save path in string
//      QString filename = QFileDialog::getOpenFileName(
//                  this,
//                  "Open File",
//                  QDir::homePath(),
//                  "All Files (*.*);; Text File (*.txt)"
//                  );

//    Note myNote(filename);
//    //Display file text
//    ui->textEdit->setText(myNote.getText());

//}


