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

void AddNotes::on_addFileBtn_clicked()
{
    //------ Open File explorer so user can select the file, then save path in string
      QString filename = QFileDialog::getOpenFileName(
                  this,
                  "Open File",
                  QDir::currentPath(),
                  "All Files (*.*);; Text File (*.txt)"
                  );

    Note myNote(filename);
    //Display file text
    ui->textEdit->setText(myNote.getText());

    //This is for testing getSentences
//    QString text = "";
//    for(int i = 0; i < myNote.getSentences().size(); i++){
//        text += myNote.getSentences().at(i) + "\n";
//    }

//    ui->textEdit->setText(text);
}

void AddNotes::on_buttonBox_accepted()
{
    //TODO:Make a file with contents and add it to chapter directory

    //closes window
    close();
}

void AddNotes::on_buttonBox_rejected()
{
    close();
}
