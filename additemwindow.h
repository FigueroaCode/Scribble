#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddItemWindow;
}

class AddItemWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemWindow(QWidget *parent = 0);
    void setMainWidget(MainWindow *window);
    void setLabelName(QString name);
    void setButtonName(QString name);
    ~AddItemWindow();

private slots:
    void on_createBtn_clicked();

private:
    Ui::AddItemWindow *ui;
    MainWindow* mainWidget;
};

#endif // ADDITEMWINDOW_H
