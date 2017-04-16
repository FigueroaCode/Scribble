/********************************************************************************
** Form generated from reading UI file 'potentialdiffwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POTENTIALDIFFWIDGET_H
#define UI_POTENTIALDIFFWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PotentialDiffWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *mergeDiffButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *changeTextLabel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *PotentialDiffWidget)
    {
        if (PotentialDiffWidget->objectName().isEmpty())
            PotentialDiffWidget->setObjectName(QStringLiteral("PotentialDiffWidget"));
        PotentialDiffWidget->resize(447, 93);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PotentialDiffWidget->sizePolicy().hasHeightForWidth());
        PotentialDiffWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(PotentialDiffWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mergeDiffButton = new QPushButton(PotentialDiffWidget);
        mergeDiffButton->setObjectName(QStringLiteral("mergeDiffButton"));

        horizontalLayout->addWidget(mergeDiffButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        changeTextLabel = new QLabel(PotentialDiffWidget);
        changeTextLabel->setObjectName(QStringLiteral("changeTextLabel"));

        horizontalLayout->addWidget(changeTextLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        retranslateUi(PotentialDiffWidget);

        QMetaObject::connectSlotsByName(PotentialDiffWidget);
    } // setupUi

    void retranslateUi(QWidget *PotentialDiffWidget)
    {
        PotentialDiffWidget->setWindowTitle(QApplication::translate("PotentialDiffWidget", "Form", Q_NULLPTR));
        mergeDiffButton->setText(QApplication::translate("PotentialDiffWidget", "Merge Difference", Q_NULLPTR));
        changeTextLabel->setText(QApplication::translate("PotentialDiffWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PotentialDiffWidget: public Ui_PotentialDiffWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POTENTIALDIFFWIDGET_H
