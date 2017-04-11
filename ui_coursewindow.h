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
    QPushButton *noteOneBtn;
    QPushButton *notTwoBtn;
    QPushButton *diffButton;

    void setupUi(QDialog *CourseWindow)
    {
        if (CourseWindow->objectName().isEmpty())
            CourseWindow->setObjectName(QStringLiteral("CourseWindow"));
        CourseWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(CourseWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        noteOneBtn = new QPushButton(CourseWindow);
        noteOneBtn->setObjectName(QStringLiteral("noteOneBtn"));

        verticalLayout->addWidget(noteOneBtn);

        notTwoBtn = new QPushButton(CourseWindow);
        notTwoBtn->setObjectName(QStringLiteral("notTwoBtn"));

        verticalLayout->addWidget(notTwoBtn);

        diffButton = new QPushButton(CourseWindow);
        diffButton->setObjectName(QStringLiteral("diffButton"));

        verticalLayout->addWidget(diffButton);


        retranslateUi(CourseWindow);

        QMetaObject::connectSlotsByName(CourseWindow);
    } // setupUi

    void retranslateUi(QDialog *CourseWindow)
    {
        CourseWindow->setWindowTitle(QApplication::translate("CourseWindow", "Dialog", Q_NULLPTR));
        noteOneBtn->setText(QApplication::translate("CourseWindow", "makeNote1", Q_NULLPTR));
        notTwoBtn->setText(QApplication::translate("CourseWindow", "makeNote2", Q_NULLPTR));
        diffButton->setText(QApplication::translate("CourseWindow", "difference", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CourseWindow: public Ui_CourseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEWINDOW_H
