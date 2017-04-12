#ifndef ADDCOURSEWINDOW_H
#define ADDCOURSEWINDOW_H

#include <QDialog>

namespace Ui {
class AddCourseWindow;
}

class AddCourseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddCourseWindow(QWidget *parent = 0);
    QString getCourseName();
    QString getTextbookName();
    QString getChapterName();
    ~AddCourseWindow();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddCourseWindow *ui;
    QString courseName;
    QString textbookName;
    QString chapterName;
};

#endif // ADDCOURSEWINDOW_H
