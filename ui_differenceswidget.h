/********************************************************************************
** Form generated from reading UI file 'differenceswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFERENCESWIDGET_H
#define UI_DIFFERENCESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DifferencesWidget
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QScrollArea *DifferencesWidget)
    {
        if (DifferencesWidget->objectName().isEmpty())
            DifferencesWidget->setObjectName(QStringLiteral("DifferencesWidget"));
        DifferencesWidget->resize(400, 300);
        DifferencesWidget->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 298));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        DifferencesWidget->setWidget(scrollAreaWidgetContents);

        retranslateUi(DifferencesWidget);

        QMetaObject::connectSlotsByName(DifferencesWidget);
    } // setupUi

    void retranslateUi(QScrollArea *DifferencesWidget)
    {
        DifferencesWidget->setWindowTitle(QApplication::translate("DifferencesWidget", "ScrollArea", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DifferencesWidget: public Ui_DifferencesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFERENCESWIDGET_H
