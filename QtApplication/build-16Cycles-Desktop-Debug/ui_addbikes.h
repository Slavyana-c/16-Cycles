/********************************************************************************
** Form generated from reading UI file 'addbikes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBIKES_H
#define UI_ADDBIKES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddBikes
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *AddBikes)
    {
        if (AddBikes->objectName().isEmpty())
            AddBikes->setObjectName(QStringLiteral("AddBikes"));
        AddBikes->resize(907, 682);
        goBackButton = new QPushButton(AddBikes);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(40, 280, 92, 36));

        retranslateUi(AddBikes);

        QMetaObject::connectSlotsByName(AddBikes);
    } // setupUi

    void retranslateUi(QDialog *AddBikes)
    {
        AddBikes->setWindowTitle(QApplication::translate("AddBikes", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("AddBikes", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddBikes: public Ui_AddBikes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBIKES_H
