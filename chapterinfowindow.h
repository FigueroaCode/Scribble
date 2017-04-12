#ifndef CHAPTERINFOWINDOW_H
#define CHAPTERINFOWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ChapterInfoWindow;
}

class ChapterInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChapterInfoWindow(QWidget *parent = 0);
    void setMainWidget(MainWindow *window);
    ~ChapterInfoWindow();

private slots:
    void on_addNoteBtn_clicked();

private:
    Ui::ChapterInfoWindow *ui;
    MainWindow *mainWidget;
};

#endif // CHAPTERINFOWINDOW_H
