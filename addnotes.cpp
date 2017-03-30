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
                  QDir::homePath(),
                  "All Files (*.*);; Text File (*.txt)"
                  );

    Note myNote(filename);
    //Display file text
    ui->textEdit->setText(myNote.getText());

//    //This is for testing getWords
//    QString text = "";
//    for(int i = 0; i < myNote.getWords().size(); i++){
//        for(int j = 0; j < myNote.getWords().at(i).size(); j++){
//            text += myNote.getWords().at(i).at(j) + " ";
//        }
//        text += "\n";
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
