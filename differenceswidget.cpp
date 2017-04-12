#include "differenceswidget.h"
#include "ui_differenceswidget.h"
#include "change.h"
#include "note.h"
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

void DifferencesWidget::addDifferences(QVector<Change*> changes){
    //put in here the text you want displayed
        const QString labelText = "Original Sentence: " + changes.at(0)->getOriginalSentence() +
               "\nProposed Sentence: " + changes.at(0)->getProposedSentence();
        QLabel *label = new QLabel(labelText);
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
