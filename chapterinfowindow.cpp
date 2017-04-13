#include "chapterinfowindow.h"
#include "ui_chapterinfowindow.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>

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

void ChapterInfoWindow::on_addNoteBtn_clicked()
{
    QString name = ui->noteNameInput->text();
    if(!name.isEmpty()){
        //noteName = name;
        mainWidget->addChild(mainWidget->getCurrentItem(),name);
        //----------------TODO------------------------------
        //----------------------Make a txt file with this name in the right
        //file directory----------------------------------------------------
        //reset input
        ui->noteNameInput->setText("");
    }
}

void ChapterInfoWindow::on_addNewNoteBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Choose your Note",QDir::homePath(),
                                                    "All Files (*.*);; Text File (*.txt)");
    int slashIndex = filename.lastIndexOf("/");
    int dotIndex = filename.lastIndexOf(".");
    //get just the name of the file
    QString name = filename.mid(slashIndex+1,(dotIndex-slashIndex)-1);

    if(!name.isEmpty()){
        mainWidget->addChild(mainWidget->getCurrentItem(),name);
    }

}
