/********************************************************************************
** Form generated from reading UI file 'addcoursewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOURSEWINDOW_H
#define UI_ADDCOURSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCourseWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *titleLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *chapterLabel;
    QLineEdit *chapterInput;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *courseLabel;
    QLineEdit *courseInput;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *textbookLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *textbookInput;

    void setupUi(QDialog *AddCourseWindow)
    {
        if (AddCourseWindow->objectName().isEmpty())
            AddCourseWindow->setObjectName(QStringLiteral("AddCourseWindow"));
        AddCourseWindow->resize(417, 201);
        buttonBox = new QDialogButtonBox(AddCourseWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(60, 160, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        titleLabel = new QLabel(AddCourseWindow);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(60, 10, 311, 31));
        layoutWidget = new QWidget(AddCourseWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 120, 218, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        chapterLabel = new QLabel(layoutWidget);
        chapterLabel->setObjectName(QStringLiteral("chapterLabel"));

        horizontalLayout_3->addWidget(chapterLabel);

        chapterInput = new QLineEdit(layoutWidget);
        chapterInput->setObjectName(QStringLiteral("chapterInput"));

        horizontalLayout_3->addWidget(chapterInput);

        widget = new QWidget(AddCourseWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(69, 50, 218, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        courseLabel = new QLabel(widget);
        courseLabel->setObjectName(QStringLiteral("courseLabel"));

        horizontalLayout->addWidget(courseLabel);

        courseInput = new QLineEdit(widget);
        courseInput->setObjectName(QStringLiteral("courseInput"));

        horizontalLayout->addWidget(courseInput);

        widget1 = new QWidget(AddCourseWindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(75, 82, 211, 31));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        textbookLabel = new QLabel(widget1);
        textbookLabel->setObjectName(QStringLiteral("textbookLabel"));

        horizontalLayout_2->addWidget(textbookLabel);

        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        textbookInput = new QLineEdit(widget1);
        textbookInput->setObjectName(QStringLiteral("textbookInput"));

        horizontalLayout_2->addWidget(textbookInput);


        retranslateUi(AddCourseWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddCourseWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddCourseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddCourseWindow);
    } // setupUi

    void retranslateUi(QDialog *AddCourseWindow)
    {
        AddCourseWindow->setWindowTitle(QApplication::translate("AddCourseWindow", "Dialog", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("AddCourseWindow", "<h4>Enter the name of your course and its textbook</h4>", Q_NULLPTR));
        chapterLabel->setText(QApplication::translate("AddCourseWindow", "First Chapter", Q_NULLPTR));
        courseLabel->setText(QApplication::translate("AddCourseWindow", "Course Name", Q_NULLPTR));
        textbookLabel->setText(QApplication::translate("AddCourseWindow", "TextBook", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddCourseWindow: public Ui_AddCourseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOURSEWINDOW_H
