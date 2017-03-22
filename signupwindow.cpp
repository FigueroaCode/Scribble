#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "addnotes.h"

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
    AddNotes myNote;
    myNote.setModal(true);
    myNote.exec();
}
