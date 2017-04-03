#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = 0);
    ~SignUpWindow();

private slots:
    void on_signInBtn_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::SignUpWindow *ui;
    QString dirPath;
};

#endif // SIGNUPWINDOW_H
