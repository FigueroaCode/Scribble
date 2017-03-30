#include "getdirectorywindow.h"
#include "ui_getdirectorywindow.h"
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "mainwindow.h"
#include "signupwindow.h"

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
            //switch to project folder directory
            dir.cd(filepath + "/" + dirName);
            //Add textbook and other essentials
            if(!dir.exists("Courses")){
                dir.mkdir("Courses");
            }
            //
            dir.cd(filepath+"/"+ dirName + "/Courses" );
            //Add textbook and other essentials
            if(!dir.exists("Textbook")){
                dir.mkdir("Textbook");
            }
            //switch to textbook folder
            dir.cd(filepath+ "/"+ dirName + "/Courses/Textbook");
            if(!dir.exists("Chapter")){
                dir.mkdir("Chapter");
            }
            //switch to project folder dir
            dir.cd(filepath + "/" + dirName);
            if(!dir.exists("Logs")){
                dir.mkdir("Logs");
            }
        }
        //hide window
        hide();
        //then send to main window
        MainWindow main;
        main.setModal(true);
        main.exec();
    }
}

void GetDirectoryWindow::on_cancelBtn_clicked()
{
    hide();

    SignUpWindow *window = new SignUpWindow();
    window->show();
}