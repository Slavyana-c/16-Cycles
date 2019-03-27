/********************************************************************************
** Form generated from reading UI file 'updateorders.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEORDERS_H
#define UI_UPDATEORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpdateOrders
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *UpdateOrders)
    {
        if (UpdateOrders->objectName().isEmpty())
            UpdateOrders->setObjectName(QStringLiteral("UpdateOrders"));
        UpdateOrders->resize(972, 712);
        goBackButton = new QPushButton(UpdateOrders);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(100, 180, 92, 36));

        retranslateUi(UpdateOrders);

        QMetaObject::connectSlotsByName(UpdateOrders);
    } // setupUi

    void retranslateUi(QDialog *UpdateOrders)
    {
        UpdateOrders->setWindowTitle(QApplication::translate("UpdateOrders", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("UpdateOrders", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpdateOrders: public Ui_UpdateOrders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEORDERS_H
