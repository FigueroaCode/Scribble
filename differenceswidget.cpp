#include "differenceswidget.h"
#include "ui_differenceswidget.h"

DifferencesWidget::DifferencesWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::DifferencesWidget)
{
    ui->setupUi(this);
    //Make container for widgets
    central = new QWidget;

    //set the scroll container's widget to the container widget
    this->setWidget(central);

}

QVector<Change*> DifferencesWidget::addDifference(QVector<Change*> changes){
    //put in here the text you want displayed
    QLabel *label = new QLabel("");
    label->setSizePolicy(QSizePolicy::QSizePolicy::Maximum,QSizePolicy::Maximum);
    //creating checkbox widget
    QCheckBox *check = new QCheckBox();

    //add these widgets to the box container
    diffBox->addWidget(check);
    diffBox->addWidget(label);
}

DifferencesWidget::~DifferencesWidget()
{
    delete ui;
}
