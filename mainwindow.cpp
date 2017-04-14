#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "getdirectorywindow.h"
#include "addcoursewindow.h"
#include "chapterinfowindow.h"
#include "addnotes.h"
#include "note.h"
#include <QFileInfo>
#include <QFile>
#include <QDirIterator>
#include <QDebug>

//having issues if i declate it in header
ChapterInfoWindow *infoWindow = NULL;
AddNotes *noteWindow = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentItem = NULL;
    groupBoxLayout = NULL;
    itemToDel = NULL;
    projectPath = "";

    initializeCourseList();
    loadCourseList();

}
bool MainWindow::initializeCourseList(){
    if(QFileInfo::exists(pathname)){
        QFile file(pathname);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            //file didnt open, ask user to set new directory
             GetDirectoryWindow window;
             window.setModal(true);
             window.exec();
         }

        projectPath = file.readAll();

        file.close();

        //go to project path and check for course dir

        traverseDir(projectPath);

        return true;
    }else{
        //ask user to set the project directory if it doesnt exist
        GetDirectoryWindow window;
        window.setModal(true);
        window.exec();

        return initializeCourseList();
    }
}
void MainWindow::traverseDir(QString path){
     QDir projectDir(path);
     QStringList dirs = projectDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
     //add all the directories to courses list
     if(dirs.size() > 0){
         for(int i = 0; i < dirs.size(); i++){
             //make course to add textbooks to
             Course *course = new Course();
             //set name
             course->setCourseName(dirs.at(i));
             //find all the textbooks and add it to the course
             projectDir.cd(path + "/" + dirs.at(i));
             QStringList bookDirs = projectDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
             for(int j = 0; j < bookDirs.size();j++){
                Textbook *temp = new Textbook();
                temp->setTextbookName(bookDirs.at(j));
                course->addTextbook(temp);
             }
             //find all the chapters and add them to the textbooks
             for(int j = 0; j < course->getTextbooks().size();j++){
                projectDir.cd(path + "/" + dirs.at(i) + "/"+ course->getTextbook(j)->getTextbookName());
                QStringList chapterDirs = projectDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
                for(int x = 0; x < chapterDirs.size();x++){
                    Chapter* temp = new Chapter(chapterDirs.at(x));
                    course->getTextbook(j)->addChapter(temp);

                     projectDir.cd(path + "/" + dirs.at(i) + "/"+ course->getTextbook(j)->getTextbookName()+"/"+temp->getChapterName());
                     QStringList fileList = projectDir.entryList(QDir::Files | QDir::NoDotAndDotDot);
                     for(int y = 0; y < fileList.size();y++){
                         //make a note object for the
                         Note *note = new Note(projectDir.path() + "/"+fileList.at(y));
                         //course->getTextbook(j)->getChapter(x)->
                     }
                }
             }
            //add this course to the list
             courses.addCourse(course);
         }

     }
}
//Add Course
QTreeWidgetItem* MainWindow::addRoot(QString name){
    //make treewidget item and set its parent to the treewidget
    QTreeWidgetItem *course = new QTreeWidgetItem(ui->courseList);
    //first parameter is the column number, the second is its name
    course->setText(0,name);

    return course;

}
//Add Textbook
QTreeWidgetItem* MainWindow::addChild(QTreeWidgetItem *parent, QString name){
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);

    parent->addChild(itm);

    return itm;
}

//Add the courses to the treewidget as roots
void MainWindow::loadCourseList(){
    for(int i = 0; i < courses.getSize(); i++){
        //get the courses
        QTreeWidgetItem* root = addRoot(courses.getCourse(i)->getCourseName());
        for(int j = 0; j < courses.getCourse(i)->getTextbooks().size(); j++){
            //get the textbooks
           QTreeWidgetItem* parent  = addChild(root,courses.getCourse(i)->getTextbook(j)->getTextbookName());
            for(int x = 0; x < courses.getCourse(i)->getTextbook(j)->getChaptersList().size(); x++){
                //get the chapters
                addChild(parent,courses.getCourse(i)->getTextbook(j)->getChapter(x)->getChapterName());
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



//adds course to the tree widget and creates a directory for it
void MainWindow::on_addCourseBtn_clicked()
{
    AddCourseWindow window;
    window.setModal(true);
    window.exec();

    //get course and textbook form dialog window
    QString course = window.getCourseName();
    QString textbook = window.getTextbookName();
    QString chapter = window.getChapterName();
    //make sure it isnt blank
    if(!course.isEmpty() && !textbook.isEmpty() && !chapter.isEmpty()){
        QTreeWidgetItem* courseRoot = addRoot(course);
        QTreeWidgetItem* textbookItem = addChild(courseRoot,textbook);
        addChild(textbookItem,chapter);
        Course *crs = new Course();
        Textbook *txtbook = new Textbook();
        Chapter *chapter1 = new Chapter();
        txtbook->addChapter(chapter1);
        crs->addTextbook(txtbook);
        courses.addCourse(crs);

    }

    //----------------TODO------------------------------
    //----------------------Make the directories for these in the
    //project folder----------------------------------------------------
}

void MainWindow::on_courseList_itemClicked(QTreeWidgetItem *item, int column)
{
    //change name of delete button
    ui->deleteBtn->setText("Delete " + item->text(column));
    itemToDel = item;
    if(item->parent() != NULL){
        int nestNum = countNest(item);
       if(nestNum == 2){
            currentItem = item;
           //its a chapter
            //set title of group box
            ui->groupBox->setTitle("Information of " + item->text(column));
            //hide the note window if its shown
           if(noteWindow != NULL)
               noteWindow->hide();
           if(infoWindow != NULL){
               infoWindow->show();
           }else{
               //make container for widgets
                groupBoxLayout = new QVBoxLayout();
                infoWindow = new ChapterInfoWindow();
                infoWindow->setMainWidget(this);
                groupBoxLayout->addWidget(infoWindow);

                ui->groupBox->setLayout(groupBoxLayout);
           }
       }else if(nestNum == 3){
           //its a note
           //set title of group box
           ui->groupBox->setTitle("Information of " + item->text(column));
           //check if infowindow is shown and hide it if it is
           if(infoWindow != NULL)
                infoWindow->hide();
           if(noteWindow != NULL){
               noteWindow->show();
           }else{
                noteWindow = new AddNotes();
                groupBoxLayout->addWidget(noteWindow);
           }

       }
    }
}

int MainWindow::countNest(QTreeWidgetItem *parent){
    int count  = 0;
   while(parent->parent() != NULL){
       count++;
       parent = parent->parent();
   }

   return count;
}

QTreeWidgetItem* MainWindow::getCurrentItem(){
    return currentItem;
}

void MainWindow::on_deleteBtn_clicked()
{
    if(itemToDel != NULL){
        //delete current item
        QTreeWidgetItem *temp = itemToDel;
        //hide the group box widgets if chapter or note is selected
            if(infoWindow != NULL){
                infoWindow->hide();
            }
            if(noteWindow != NULL){
                noteWindow->hide();
            }
        delete temp;
        itemToDel = NULL;
        ui->deleteBtn->setText("Delete");

        //-------------Delete the directories as well-----------//

    }
}
