#include "differenceswidget.h"
#include "ui_differenceswidget.h"
#include "change.h"
#include "note.h"
#include "potentialdiffwidget.h"
#include <QDebug>

DifferencesWidget::DifferencesWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::DifferencesWidget)
{
    ui->setupUi(this);
    //Make container for widgets
    central = new QWidget;
    diffBox = new QVBoxLayout(central);

    //set the scroll container's widget to the container widget
    this->setWidget(central);

}

void DifferencesWidget::addDifferences(QVector<Change*> changes, Chapter* chapter)
{
    if(!diffBox->isEmpty())
    {
        for(int i = 0; i < differenceWidgets.size(); i++)
        {
            diffBox->removeWidget(differenceWidgets.at(i));
            delete differenceWidgets.at(i);
        }
    }

    differenceWidgets.clear();
    for(int i = 0; i < changes.size(); i++)
    {
        PotentialDiffWidget* newDiff = new PotentialDiffWidget(0, changes.at(i), chapter);
        differenceWidgets.append(newDiff);
        diffBox->addWidget(differenceWidgets.at(i));
    }
}

DifferencesWidget::~DifferencesWidget()
{
    delete ui;
}
