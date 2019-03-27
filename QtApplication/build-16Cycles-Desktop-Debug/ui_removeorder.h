/********************************************************************************
** Form generated from reading UI file 'removeorder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEORDER_H
#define UI_REMOVEORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RemoveOrder
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *RemoveOrder)
    {
        if (RemoveOrder->objectName().isEmpty())
            RemoveOrder->setObjectName(QStringLiteral("RemoveOrder"));
        RemoveOrder->resize(984, 721);
        goBackButton = new QPushButton(RemoveOrder);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(190, 140, 92, 36));

        retranslateUi(RemoveOrder);

        QMetaObject::connectSlotsByName(RemoveOrder);
    } // setupUi

    void retranslateUi(QDialog *RemoveOrder)
    {
        RemoveOrder->setWindowTitle(QApplication::translate("RemoveOrder", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("RemoveOrder", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RemoveOrder: public Ui_RemoveOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEORDER_H
