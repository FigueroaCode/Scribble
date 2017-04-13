#include "getdirectorywindow.h"
#include "ui_getdirectorywindow.h"
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "mainwindow.h"
#include <QTextStream>
#include <QFile>

GetDirectoryWindow::GetDirectoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetDirectoryWindow)
{
    ui->setupUi(this);
}

GetDirectoryWindow::~GetDirectoryWindow()
{
    delete ui;
}

void GetDirectoryWindow::on_dirBtn_clicked()
{
    // -- Opens file explorer -- //
    QString filename = QFileDialog::getExistingDirectory(
                this,
                "Select Directory",
                QDir::homePath());

    ui->filePathInput->setText(filename);
}

void GetDirectoryWindow::on_nextBtn_clicked()
{
    QString dirName = ui->dirNameInput->text();
    QString filepath = ui->filePathInput->text();
    if(filepath.isEmpty()){
        QMessageBox::warning(this, "Information Missing", "Enter a directory please.");
    }else if(dirName.isEmpty()){
        QMessageBox::warning(this, "Information Missing", "Enter a directory name please.");
    }else{
        //make textbook directories and such
        QDir dir(filepath);
        if(!dir.exists()){
            dir.mkpath(".");
        }else{
            //Make Project Folder
            if(!dir.exists(dirName)){
                dir.mkdir(dirName);
            }

        }
        //make a text file to store directory path
        QString pathname = filepath + "/" + dirName;
        dir.cd(QDir::homePath());
        if(!dir.exists("StateInfo")){
            dir.mkdir("StateInfo");
        }
         //use this file path to get project dir
        QFile file(QDir::homePath()+"/StateInfo/Directory_Path.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&file);
            out << pathname;
        }
        file.close();

        close();
    }
}

void GetDirectoryWindow::on_cancelBtn_clicked()
{
    close();
}
