#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QDialog>

namespace Ui {
class CourseWindow;
}

class CourseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CourseWindow(QWidget *parent = 0);
    ~CourseWindow();

private:
    Ui::CourseWindow *ui;
};

#endif // COURSEWINDOW_H
