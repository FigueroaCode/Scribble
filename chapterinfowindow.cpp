#include "chapterinfowindow.h"
#include "ui_chapterinfowindow.h"

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
        //reset input
        ui->noteNameInput->setText("");
    }
}
