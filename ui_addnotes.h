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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNotes
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *addFileBtn;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddNotes)
    {
        if (AddNotes->objectName().isEmpty())
            AddNotes->setObjectName(QStringLiteral("AddNotes"));
        AddNotes->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddNotes);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addFileBtn = new QPushButton(AddNotes);
        addFileBtn->setObjectName(QStringLiteral("addFileBtn"));

        verticalLayout->addWidget(addFileBtn);

        textEdit = new QTextEdit(AddNotes);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(AddNotes);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddNotes);

        QMetaObject::connectSlotsByName(AddNotes);
    } // setupUi

    void retranslateUi(QDialog *AddNotes)
    {
        AddNotes->setWindowTitle(QApplication::translate("AddNotes", "Note", Q_NULLPTR));
        addFileBtn->setText(QApplication::translate("AddNotes", "Add File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNotes: public Ui_AddNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTES_H
