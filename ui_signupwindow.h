/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameInput;
    QLabel *emailLabel;
    QLineEdit *emailInput;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *signUpBtn;
    QLabel *orLabel;
    QPushButton *signInBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName(QStringLiteral("SignUpWindow"));
        SignUpWindow->resize(400, 342);
        centralWidget = new QWidget(SignUpWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        usernameLabel = new QLabel(centralWidget);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usernameLabel);

        usernameInput = new QLineEdit(centralWidget);
        usernameInput->setObjectName(QStringLiteral("usernameInput"));

        verticalLayout->addWidget(usernameInput);

        emailLabel = new QLabel(centralWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(emailLabel);

        emailInput = new QLineEdit(centralWidget);
        emailInput->setObjectName(QStringLiteral("emailInput"));

        verticalLayout->addWidget(emailInput);

        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(passwordLabel);

        passwordInput = new QLineEdit(centralWidget);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));

        verticalLayout->addWidget(passwordInput);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        signUpBtn = new QPushButton(centralWidget);
        signUpBtn->setObjectName(QStringLiteral("signUpBtn"));

        horizontalLayout->addWidget(signUpBtn);

        orLabel = new QLabel(centralWidget);
        orLabel->setObjectName(QStringLiteral("orLabel"));
        orLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(orLabel);

        signInBtn = new QPushButton(centralWidget);
        signInBtn->setObjectName(QStringLiteral("signInBtn"));

        horizontalLayout->addWidget(signInBtn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        SignUpWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SignUpWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        SignUpWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SignUpWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SignUpWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SignUpWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SignUpWindow->setStatusBar(statusBar);

        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QApplication::translate("SignUpWindow", "SignUpWindow", Q_NULLPTR));
        usernameLabel->setText(QApplication::translate("SignUpWindow", "Username", Q_NULLPTR));
        emailLabel->setText(QApplication::translate("SignUpWindow", "Email", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("SignUpWindow", "Password", Q_NULLPTR));
        signUpBtn->setText(QApplication::translate("SignUpWindow", "Sign Up", Q_NULLPTR));
        orLabel->setText(QApplication::translate("SignUpWindow", "or", Q_NULLPTR));
        signInBtn->setText(QApplication::translate("SignUpWindow", "Sign In", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
