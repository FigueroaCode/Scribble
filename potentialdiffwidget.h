#ifndef POTENTIALDIFFWIDGET_H
#define POTENTIALDIFFWIDGET_H

#include <QWidget>

namespace Ui {
class PotentialDiffWidget;
}

class PotentialDiffWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PotentialDiffWidget(QWidget *parent = 0);
    ~PotentialDiffWidget();

private:
    Ui::PotentialDiffWidget *ui;
};

#endif // POTENTIALDIFFWIDGET_H
