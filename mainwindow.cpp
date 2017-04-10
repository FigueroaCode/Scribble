#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnotes.h"
#include "coursewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->courseList->addItem("Course 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_courseList_itemClicked(QListWidgetItem *item)
{
    CourseWindow window;
    window.setModal(true);
    window.exec();
}
