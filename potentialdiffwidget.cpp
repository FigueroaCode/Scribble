#include "potentialdiffwidget.h"
#include "ui_potentialdiffwidget.h"

PotentialDiffWidget::PotentialDiffWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PotentialDiffWidget)
{
    ui->setupUi(this);
}

PotentialDiffWidget::~PotentialDiffWidget()
{
    delete ui;
}
