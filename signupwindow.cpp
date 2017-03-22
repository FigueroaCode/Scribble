#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "mainwindow.h"
#include "registerwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}



void SignUpWindow::on_signInBtn_clicked()
{
    // --Hide Window--
    hide();
    // ----Open Main Window if sign in successful----
    MainWindow window;
    window.setModal(true);
    window.exec();
}

void SignUpWindow::on_signUpBtn_clicked()
{
    // --Hide Window--
    hide();
    // ----Open Register Window----
    RegisterWindow window;
    window.setModal(true);
    window.exec();
}
