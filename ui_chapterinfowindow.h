/********************************************************************************
** Form generated from reading UI file 'chapterinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAPTERINFOWINDOW_H
#define UI_CHAPTERINFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChapterInfoWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *addNewNoteBtn;

    void setupUi(QDialog *ChapterInfoWindow)
    {
        if (ChapterInfoWindow->objectName().isEmpty())
            ChapterInfoWindow->setObjectName(QStringLiteral("ChapterInfoWindow"));
        ChapterInfoWindow->resize(308, 131);
        verticalLayout = new QVBoxLayout(ChapterInfoWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ChapterInfoWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        addNewNoteBtn = new QPushButton(ChapterInfoWindow);
        addNewNoteBtn->setObjectName(QStringLiteral("addNewNoteBtn"));

        verticalLayout->addWidget(addNewNoteBtn);


        retranslateUi(ChapterInfoWindow);

        QMetaObject::connectSlotsByName(ChapterInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *ChapterInfoWindow)
    {
        ChapterInfoWindow->setWindowTitle(QApplication::translate("ChapterInfoWindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ChapterInfoWindow", "Choose a text file you wish to add.", Q_NULLPTR));
        addNewNoteBtn->setText(QApplication::translate("ChapterInfoWindow", "Add New Note", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChapterInfoWindow: public Ui_ChapterInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAPTERINFOWINDOW_H
