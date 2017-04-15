#include "chapterinfowindow.h"
#include "ui_chapterinfowindow.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QTreeWidgetItem>
#include <algorithm>

ChapterInfoWindow::ChapterInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChapterInfoWindow)
{
    ui->setupUi(this);
    ui->label->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Fixed);
}

void ChapterInfoWindow::setMainWidget(MainWindow *window){
    mainWidget = window;
}
ChapterInfoWindow::~ChapterInfoWindow()
{
    delete ui;
}

void ChapterInfoWindow::on_addNewNoteBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Choose your Note",QDir::homePath(),
                                                    "All Files (*.*);; Text File (*.txt)");
    int slashIndex = filename.lastIndexOf("/");
    //get just the name of the file
    QString name = filename.mid(slashIndex+1);
    int childAmount = mainWidget->getCurrentItem()->childCount();
    if(childAmount <= 0){
        //no child, so make a new note
        if(!name.isEmpty()){
            //add to courselist
            QString courseName = mainWidget->getCurrentItem()->parent()->parent()->text(0);
            QString textbookName = mainWidget->getCurrentItem()->parent()->text(0);
            int courseIndex = mainWidget->getCourseList().CourseIndex(courseName);
            if(courseIndex >= 0){
                int textbookIndex = mainWidget->getCourseList().getCourse(courseIndex)->findIndex(textbookName);
                if(textbookIndex >= 0){
                    int chapterIndex =mainWidget->getCourseList().getCourse(courseIndex)->
                            getTextbook(textbookIndex)->findIndex(mainWidget->getCurrentItem()->text(0));
                    //add the note to the chapter in the list
                    Note* note = new Note(name);
                    mainWidget->getCourseList().getCourse(courseIndex)->
                                                getTextbook(textbookIndex)
                            ->getChapter(chapterIndex)->setMainNote(note);
                    //add it to the treewidget
                    mainWidget->addChild(mainWidget->getCurrentItem(),name);
                    //current path to desired path
                    QString path = mainWidget->getProjectPath() +"/" + getParentNames(mainWidget->getCurrentItem()) + "/";
                    //qDebug() << path;
                    QDir dir(path);
                    if(dir.exists()){
                        QFile::copy(filename, path+name);
                    }
                }
            }
        }
    }else{
        //has a child, so merging
    }
}

QString ChapterInfoWindow::getParentNames(QTreeWidgetItem* parent){
    if(parent->parent() != NULL){
        //has a parent
        QString name = parent->text(0);
        parent = parent->parent();
        return getParentNames(parent) + "/" + name;
    }else{
        return parent->text(0);
    }
}

void ChapterInfoWindow::setButtonName(QString name){
    ui->addNewNoteBtn->setText(name);
}
