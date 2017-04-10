/********************************************************************************
** Form generated from reading UI file 'getdirectorywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDIRECTORYWINDOW_H
#define UI_GETDIRECTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetDirectoryWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *dirNameInput;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filePathInput;
    QPushButton *dirBtn;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelBtn;
    QPushButton *nextBtn;

    void setupUi(QDialog *GetDirectoryWindow)
    {
        if (GetDirectoryWindow->objectName().isEmpty())
            GetDirectoryWindow->setObjectName(QStringLiteral("GetDirectoryWindow"));
        GetDirectoryWindow->resize(400, 300);
        layoutWidget = new QWidget(GetDirectoryWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 272, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dirNameInput = new QLineEdit(layoutWidget);
        dirNameInput->setObjectName(QStringLiteral("dirNameInput"));

        horizontalLayout_2->addWidget(dirNameInput);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget = new QWidget(GetDirectoryWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 100, 272, 59));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(false);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filePathInput = new QLineEdit(widget);
        filePathInput->setObjectName(QStringLiteral("filePathInput"));

        horizontalLayout->addWidget(filePathInput);

        dirBtn = new QPushButton(widget);
        dirBtn->setObjectName(QStringLiteral("dirBtn"));

        horizontalLayout->addWidget(dirBtn);


        verticalLayout->addLayout(horizontalLayout);

        widget1 = new QWidget(GetDirectoryWindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(150, 260, 228, 32));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cancelBtn = new QPushButton(widget1);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout_3->addWidget(cancelBtn);

        nextBtn = new QPushButton(widget1);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));

        horizontalLayout_3->addWidget(nextBtn);


        retranslateUi(GetDirectoryWindow);

        QMetaObject::connectSlotsByName(GetDirectoryWindow);
    } // setupUi

    void retranslateUi(QDialog *GetDirectoryWindow)
    {
        GetDirectoryWindow->setWindowTitle(QApplication::translate("GetDirectoryWindow", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("GetDirectoryWindow", "Name your Directory", Q_NULLPTR));
        label->setText(QApplication::translate("GetDirectoryWindow", "Where do you want your notes to be stored?", Q_NULLPTR));
        dirBtn->setText(QApplication::translate("GetDirectoryWindow", "Search", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("GetDirectoryWindow", "Cancel", Q_NULLPTR));
        nextBtn->setText(QApplication::translate("GetDirectoryWindow", "Next", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GetDirectoryWindow: public Ui_GetDirectoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDIRECTORYWINDOW_H
