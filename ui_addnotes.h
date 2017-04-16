/********************************************************************************
** Form generated from reading UI file 'addnotes.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTES_H
#define UI_ADDNOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNotes
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *saveChangesBtn;
    QTextEdit *textEdit;

    void setupUi(QDialog *AddNotes)
    {
        if (AddNotes->objectName().isEmpty())
            AddNotes->setObjectName(QStringLiteral("AddNotes"));
        AddNotes->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddNotes);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        saveChangesBtn = new QPushButton(AddNotes);
        saveChangesBtn->setObjectName(QStringLiteral("saveChangesBtn"));

        verticalLayout->addWidget(saveChangesBtn);

        textEdit = new QTextEdit(AddNotes);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(AddNotes);

        QMetaObject::connectSlotsByName(AddNotes);
    } // setupUi

    void retranslateUi(QDialog *AddNotes)
    {
        AddNotes->setWindowTitle(QApplication::translate("AddNotes", "Note", Q_NULLPTR));
        saveChangesBtn->setText(QApplication::translate("AddNotes", "Save Changes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNotes: public Ui_AddNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTES_H
