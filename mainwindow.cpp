#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnotes.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // ----Open file adding window----
    AddNotes myNote;
    myNote.setModal(true);
    myNote.exec();
}
