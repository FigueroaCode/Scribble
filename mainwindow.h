#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QDir>
#include <QVBoxLayout>
#include "courselist.h"
#include "course.h"
#include "textbook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int countNest(QTreeWidgetItem* parent);
    //adds a root to the treewidget
    QTreeWidgetItem* addRoot(QString name);
    //adds a child to the root given as the parent
    QTreeWidgetItem* addChild(QTreeWidgetItem *parent,QString name);
    QTreeWidgetItem* getCurrentItem();
    ~MainWindow();

private slots:

    void on_addCourseBtn_clicked();

    void on_courseList_itemClicked(QTreeWidgetItem *item, int column);

    void on_deleteBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    CourseList courses;
    QTreeWidgetItem *currentItem;
    QTreeWidgetItem *itemToDel;
    QVBoxLayout *groupBoxLayout;
    //path to file that has filepath to project folder
    QString projectPath;
    const QString pathname = QDir::homePath()+"/StateInfo/Directory_Path.txt";
    //initialize courselist
    void loadCourseList();
    bool initializeCourseList();
    void traverseDir(QString path);
};

#endif // MAINWINDOW_H
