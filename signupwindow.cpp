#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "mainwindow.h"
#include "registerwindow.h"
#include <QDir>
#include <QMessageBox>
#include "getdirectorywindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);

//    QDir dir();
//    dir.mkdir("Textbook");
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}



void SignUpWindow::on_signInBtn_clicked()
{

    //TODO:Need to check if they already set their project directory using database
    // --Hide Window--
    hide();
    // ----Open Main Window if sign in successful----
    GetDirectoryWindow window;
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
