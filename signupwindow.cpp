#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "mainwindow.h"
#include "registerwindow.h"
#include <QDir>
#include <QMessageBox>
#include "getdirectorywindow.h"
#include <QFileInfo>
#include <QFile>

SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    dirPath = "";
    QString pathname = QDir::homePath()+"/StateInfo/Directory_Path.txt";
    if(QFileInfo::exists(pathname)){
        QFile file(pathname);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

        dirPath = file.readAll();

        file.close();
    }else{
        GetDirectoryWindow window;
        window.setModal(true);
        window.exec();
    }
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_signInBtn_clicked()
{

    //TODO:Need to check if they already set their project directory using database
    // --close Window--
    close();
    // ----Open Main Window if sign in successful----
    MainWindow window;
    window.setModal(true);
    window.exec();
}

void SignUpWindow::on_signUpBtn_clicked()
{
    // --close Window--
    close();
    // ----Open Register Window----
    RegisterWindow window;
    window.setModal(true);
    window.exec();
}

