#include "addcoursewindow.h"
#include "ui_addcoursewindow.h"
#include <QMessageBox>

AddCourseWindow::AddCourseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCourseWindow)
{
    ui->setupUi(this);
}

AddCourseWindow::~AddCourseWindow()
{
    delete ui;
}

void AddCourseWindow::on_buttonBox_accepted()
{
    QString course = ui->courseInput->text();
    QString textbook = ui->textbookInput->text();
    QString chapter = ui->chapterInput->text();

    if(!course.isEmpty() && !textbook.isEmpty() && !chapter.isEmpty()){
        //save the names inputed
        courseName = course;
        textbookName = textbook;
        chapterName = chapter;
    }else{
        QMessageBox::warning(this,"Warning","No Course,Textbook, or Chapter Entered.");
    }
}

void AddCourseWindow::on_buttonBox_rejected()
{

}

QString AddCourseWindow::getCourseName(){
    return courseName;
}

QString AddCourseWindow::getTextbookName(){
    return textbookName;
}

QString AddCourseWindow::getChapterName(){
    return chapterName;
}
