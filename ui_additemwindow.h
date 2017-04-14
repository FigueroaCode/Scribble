/********************************************************************************
** Form generated from reading UI file 'additemwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMWINDOW_H
#define UI_ADDITEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddItemWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLineEdit *nameInput;
    QPushButton *createBtn;

    void setupUi(QDialog *AddItemWindow)
    {
        if (AddItemWindow->objectName().isEmpty())
            AddItemWindow->setObjectName(QStringLiteral("AddItemWindow"));
        AddItemWindow->resize(400, 132);
        verticalLayout = new QVBoxLayout(AddItemWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleLabel = new QLabel(AddItemWindow);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        nameInput = new QLineEdit(AddItemWindow);
        nameInput->setObjectName(QStringLiteral("nameInput"));

        verticalLayout->addWidget(nameInput);

        createBtn = new QPushButton(AddItemWindow);
        createBtn->setObjectName(QStringLiteral("createBtn"));

        verticalLayout->addWidget(createBtn);


        retranslateUi(AddItemWindow);

        QMetaObject::connectSlotsByName(AddItemWindow);
    } // setupUi

    void retranslateUi(QDialog *AddItemWindow)
    {
        AddItemWindow->setWindowTitle(QApplication::translate("AddItemWindow", "Dialog", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("AddItemWindow", "Add New ", Q_NULLPTR));
        createBtn->setText(QApplication::translate("AddItemWindow", "Create New ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddItemWindow: public Ui_AddItemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMWINDOW_H
