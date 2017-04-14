#include "additemwindow.h"
#include "ui_additemwindow.h"

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
        //noteName = name;
        mainWidget->addChild(mainWidget->getCurrentItem(),name);
        //----------------TODO------------------------------
        //----------------------Make a txt file with this name in the right
        //file directory----------------------------------------------------
        //reset input
        ui->nameInput->setText("");
    }
}
