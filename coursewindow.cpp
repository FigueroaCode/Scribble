#include "coursewindow.h"
#include "ui_coursewindow.h"
#include <QFileDialog>
#include <QDir>

CourseWindow::CourseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseWindow)
{
    ui->setupUi(this);

}

CourseWindow::~CourseWindow()
{
    delete ui;
}

void CourseWindow::on_noteOneBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                "Choose Note",
                QDir::homePath(),
                "Text Files (*.txt)");

    noteOne = new Note(filename);

    // make chapter
    chapter = new Chapter("Chapter 1", noteOne);
}

void CourseWindow::on_notTwoBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                "Choose Note",
                QDir::homePath(),
                "Text Files (*.txt)");

    noteTwo = new Note(filename);
}

void CourseWindow::on_diffButton_clicked()
{
    if(chapter != NULL && noteOne != NULL && noteTwo != NULL){
        chapter->findDifferences(noteTwo);
    }
}
