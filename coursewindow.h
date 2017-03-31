#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QDialog>
#include "note.h"
#include "chapter.h"

namespace Ui {
class CourseWindow;
}

class CourseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CourseWindow(QWidget *parent = 0);
    ~CourseWindow();

private slots:
    void on_noteOneBtn_clicked();

    void on_notTwoBtn_clicked();

    void on_diffButton_clicked();

private:
    Ui::CourseWindow *ui;
    Chapter* chapter;
    Note* noteOne;
    Note* noteTwo;

};

#endif // COURSEWINDOW_H
