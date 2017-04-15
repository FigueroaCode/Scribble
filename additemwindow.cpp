#include "additemwindow.h"
#include "ui_additemwindow.h"
#include "textbook.h"
#include "chapter.h"
#include "courselist.h"
#include <QDebug>

AddItemWindow::AddItemWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemWindow)
{
    ui->setupUi(this);
}

AddItemWindow::~AddItemWindow()
{
    delete ui;
}

void AddItemWindow::setMainWidget(MainWindow* window){
    mainWidget = window;
}

void AddItemWindow::setLabelName(QString name){
    ui->titleLabel->setText("Add New "+name);
}

void AddItemWindow::setButtonName(QString name){
    ui->createBtn->setText("Create New "+name);
}
void AddItemWindow::on_createBtn_clicked()
{
    QString name = ui->nameInput->text();
    if(!name.isEmpty()){ 
        //if parent is null then its a course
        //otherwise keep searching for the parent and then add appropriately
        if(mainWidget->getCurrentItem()->parent() != NULL){
            //adding a chapter
            int courseIndex = mainWidget->getCourseList().CourseIndex(mainWidget->getCurrentItem()->parent()->text(0));
            if(courseIndex >= 0){
                int textbookIndex = mainWidget->getCourseList().getCourse(courseIndex)->findIndex(mainWidget->getCurrentItem()->text(0));
                if(textbookIndex >= 0){//make sure that the textbook exists
                    Chapter* chapter = new Chapter(name);
                    mainWidget->getCourseList().getCourse(courseIndex)->getTextbook(textbookIndex)->addChapter(chapter);
                    //add to treewidget
                     mainWidget->addChild(mainWidget->getCurrentItem(),name);
                     //make directory for it
                     QString path = mainWidget->getProjectPath() + +"/"+ mainWidget->getParentNames(mainWidget->getCurrentItem()) + "/";

                     QDir dir(path);
                     if(!dir.exists(name)){
                         dir.mkdir(name);
                     }else{
                         qDebug() << "Dir Doesnt exist "  << path;
                     }
                }
            }
        }else{
            //adding a textbook
            int courseIndex = mainWidget->getCourseList().CourseIndex(mainWidget->getCurrentItem()->text(0));
            if(courseIndex >= 0){
                Textbook* temp = new Textbook();
                temp->setTextbookName(name);
                mainWidget->getCourseList().getCourse(courseIndex)->addTextbook(temp);
                //add to treewidget
                 mainWidget->addChild(mainWidget->getCurrentItem(),name);
                 //make directory for it
                 QString path = mainWidget->getProjectPath() + +"/"+ mainWidget->getParentNames(mainWidget->getCurrentItem()) + "/";

                 QDir dir(path);
                 if(!dir.exists(name)){
                     dir.mkdir(name);
                 }else{
                     qDebug() << "Dir Doesnt exist "  << path;
                 }

            }
        }

        //reset input
        ui->nameInput->setText("");
    }
}
