/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *registerBtn;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QStringLiteral("RegisterWindow"));
        RegisterWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(RegisterWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleLabel = new QLabel(RegisterWindow);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        titleLabel->setWordWrap(false);

        verticalLayout->addWidget(titleLabel);

        registerBtn = new QPushButton(RegisterWindow);
        registerBtn->setObjectName(QStringLiteral("registerBtn"));

        verticalLayout->addWidget(registerBtn);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Dialog", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("RegisterWindow", "<h2>Register</h2>", Q_NULLPTR));
        registerBtn->setText(QApplication::translate("RegisterWindow", "Register", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
