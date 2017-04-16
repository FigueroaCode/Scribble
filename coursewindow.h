#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QDialog>
#include "note.h"
#include "chapter.h"
#include "differenceswidget.h"

namespace Ui {
class CourseWindow;
}

class CourseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CourseWindow(QWidget *parent = 0);
    void setChapter(Chapter* chapter);
    void setMergeNote(Note* note);
    Chapter* getChapter();
    void displayDifferences();
    ~CourseWindow();

private:
    Ui::CourseWindow *ui;
    Chapter* chapter;
    Note* mergeNote;
    DifferencesWidget *differences;

};

#endif // COURSEWINDOW_H
