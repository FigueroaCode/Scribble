#ifndef GETDIRECTORYWINDOW_H
#define GETDIRECTORYWINDOW_H

#include <QDialog>

namespace Ui {
class GetDirectoryWindow;
}

class GetDirectoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GetDirectoryWindow(QWidget *parent = 0);
    ~GetDirectoryWindow();

private slots:

    void on_dirBtn_clicked();


    void on_nextBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::GetDirectoryWindow *ui;
};

#endif // GETDIRECTORYWINDOW_H
