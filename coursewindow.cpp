#include "coursewindow.h"
#include "ui_coursewindow.h"

CourseWindow::CourseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseWindow)
{
    ui->setupUi(this);
}

CourseWindow::~CourseWindow()
{
    delete ui;
}
