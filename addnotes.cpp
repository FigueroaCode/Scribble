#include "addnotes.h"
#include "ui_addnotes.h"
//#include <QtGlobal> // ----For Macros
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
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
//    //How to Check Operating System
//    //Windows
//    #ifdef Q_OS_WIN64
//    os = "windows"; // change to path
//    #endif
//    //Mac
//    #ifdef Q_OS_MACOS
//    os = "mac";
//    #endif
//    //Linux
//    #ifdef Q_OS_LINUX
//    os = "linux";
//    #endif

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
