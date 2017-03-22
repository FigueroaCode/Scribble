#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerBtn_clicked()
{
    // -- hide window --
    hide();
    //Go to Main window if register is successful
    MainWindow window;
    window.setModal(true);
    window.exec();
}
