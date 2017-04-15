#include "potentialdiffwidget.h"
#include "ui_potentialdiffwidget.h"

PotentialDiffWidget::PotentialDiffWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PotentialDiffWidget)
{
    ui->setupUi(this);
}

PotentialDiffWidget::PotentialDiffWidget(QWidget *parent, Change* chng, Chapter* chpt) :
    QWidget(parent),
    ui(new Ui::PotentialDiffWidget)
{
    //Set values for obj.
    this->change = chng;
    this->chapter = chpt;

    //Obtain sentences to display to user.
    const QString labelText = "Original Sentence: " + change->getOriginalSentence() +
           "\nProposed Sentence: " + change->getProposedSentence();

    ui->setupUi(this);
    ui->changeTextLabel->setText(labelText);
}

PotentialDiffWidget::~PotentialDiffWidget()
{
    delete ui;
}

void PotentialDiffWidget::on_mergeDiffButton_clicked()
{

}
