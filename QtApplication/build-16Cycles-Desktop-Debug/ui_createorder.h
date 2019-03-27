/********************************************************************************
** Form generated from reading UI file 'createorder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDER_H
#define UI_CREATEORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateOrder
{
public:
    QGroupBox *groupBox;
    QPushButton *goBackButton;

    void setupUi(QDialog *CreateOrder)
    {
        if (CreateOrder->objectName().isEmpty())
            CreateOrder->setObjectName(QStringLiteral("CreateOrder"));
        CreateOrder->resize(838, 572);
        groupBox = new QGroupBox(CreateOrder);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 781, 471));
        goBackButton = new QPushButton(groupBox);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(100, 110, 92, 36));

        retranslateUi(CreateOrder);

        QMetaObject::connectSlotsByName(CreateOrder);
    } // setupUi

    void retranslateUi(QDialog *CreateOrder)
    {
        CreateOrder->setWindowTitle(QApplication::translate("CreateOrder", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CreateOrder", "Create Order", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("CreateOrder", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateOrder: public Ui_CreateOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDER_H
