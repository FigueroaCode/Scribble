#include "addnotes.h"
#include "ui_addnotes.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QDebug>

AddNotes::AddNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNotes)
{
    ui->setupUi(this);
    note = NULL;
}

void AddNotes::setNote(QString filepath){
    note = new Note(filepath);
    ui->textEdit->setText(note->getText());
}

AddNotes::~AddNotes()
{
    delete ui;
}

void AddNotes::on_saveChangesBtn_clicked()
{
    QString filepath = note->getFilePath();
    QFile file(filepath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
    }else{
        qDebug() << "File didnt open";
    }
    file.close();
}
