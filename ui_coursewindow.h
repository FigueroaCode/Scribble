/********************************************************************************
** Form generated from reading UI file 'coursewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEWINDOW_H
#define UI_COURSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CourseWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *confirmBtn;

    void setupUi(QDialog *CourseWindow)
    {
        if (CourseWindow->objectName().isEmpty())
            CourseWindow->setObjectName(QStringLiteral("CourseWindow"));
        CourseWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(CourseWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        confirmBtn = new QPushButton(CourseWindow);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));

        verticalLayout->addWidget(confirmBtn);


        retranslateUi(CourseWindow);

        QMetaObject::connectSlotsByName(CourseWindow);
    } // setupUi

    void retranslateUi(QDialog *CourseWindow)
    {
        CourseWindow->setWindowTitle(QApplication::translate("CourseWindow", "Dialog", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("CourseWindow", "Confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CourseWindow: public Ui_CourseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEWINDOW_H
