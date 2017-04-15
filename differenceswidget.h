#ifndef DIFFERENCESWIDGET_H
#define DIFFERENCESWIDGET_H

#include <QScrollArea>
#include <QVector>
#include <QCheckBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "change.h"
#include "chapter.h"
#include "potentialdiffwidget.h"

namespace Ui {
class DifferencesWidget;
}

class DifferencesWidget : public QScrollArea
{
    Q_OBJECT

public:
    explicit DifferencesWidget(QWidget *parent = 0);
    void addDifferences(QVector<Change*> changes, Chapter* chapter);
    ~DifferencesWidget();
private:
    Ui::DifferencesWidget *ui;
    QWidget *central;
    QVBoxLayout *diffBox;
    QVector<PotentialDiffWidget*> differenceWidgets;

};

#endif // DIFFERENCESWIDGET_H
