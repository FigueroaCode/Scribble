/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addCourseBtn;
    QTreeWidget *courseList;
    QPushButton *deleteBtn;
    QGroupBox *groupBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(641, 430);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 211, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addCourseBtn = new QPushButton(layoutWidget);
        addCourseBtn->setObjectName(QStringLiteral("addCourseBtn"));
        QFont font;
        font.setFamily(QStringLiteral("American Typewriter"));
        addCourseBtn->setFont(font);
        addCourseBtn->setAutoFillBackground(false);
        addCourseBtn->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(addCourseBtn);

        courseList = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setBackground(0, QColor(0, 0, 0));
        courseList->setHeaderItem(__qtreewidgetitem);
        courseList->setObjectName(QStringLiteral("courseList"));
        QFont font1;
        font1.setFamily(QStringLiteral("American Typewriter"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        courseList->setFont(font1);
        courseList->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(courseList);

        deleteBtn = new QPushButton(layoutWidget);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        QFont font2;
        font2.setFamily(QStringLiteral("American Typewriter"));
        font2.setKerning(false);
        deleteBtn->setFont(font2);

        verticalLayout->addWidget(deleteBtn);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(240, 50, 381, 321));
        QFont font3;
        font3.setFamily(QStringLiteral("Chalkboard"));
        font3.setPointSize(19);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox->setFont(font3);
        groupBox->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 641, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scribble", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        addCourseBtn->setText(QApplication::translate("MainWindow", "Add Course", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = courseList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "My Courses", Q_NULLPTR));
        deleteBtn->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Information", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
