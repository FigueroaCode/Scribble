#include "coursewindow.h"
#include "ui_coursewindow.h"
#include <QFileDialog>
#include <QDir>
#include "differenceswidget.h"
#include "change.h"
#include <QDebug>

CourseWindow::CourseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseWindow)
{
    ui->setupUi(this);
    mergeNote = NULL;
    chapter = NULL;
    differences = new DifferencesWidget();
    ui->verticalLayout->addWidget(differences);
}

CourseWindow::~CourseWindow()
{
    delete ui;
}

void CourseWindow::setChapter(Chapter* chapter){
    this->chapter = chapter;
}

void CourseWindow::setMergeNote(Note *note){
    mergeNote = note;
}

void CourseWindow::displayDifferences(){
    if(chapter != NULL  && mergeNote != NULL
         && !(mergeNote->getText().isEmpty())
            ){
        mergeNote->clearChangeLog();
        chapter->findDifferences(mergeNote);
        QVector<Change*> changeLog = mergeNote->getChangeLog();
        differences->addDifferences(changeLog, chapter);
        mergeNote->clearChangeLog();
    }
}
