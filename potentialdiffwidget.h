#ifndef POTENTIALDIFFWIDGET_H
#define POTENTIALDIFFWIDGET_H

#include "change.h"
#include "chapter.h"
#include <QWidget>

namespace Ui {
class PotentialDiffWidget;
}

class PotentialDiffWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PotentialDiffWidget(QWidget *parent = 0);
    explicit PotentialDiffWidget(QWidget *parent = 0, Change* change = 0, Chapter* chpt = 0);
    ~PotentialDiffWidget();

private slots:
    void on_mergeDiffButton_clicked();

private:
    Ui::PotentialDiffWidget *ui;
    Change* change;
    Chapter* chapter;
};

#endif // POTENTIALDIFFWIDGET_H
