/********************************************************************************
** Form generated from reading UI file 'profits.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFITS_H
#define UI_PROFITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Profits
{
public:

    void setupUi(QDialog *Profits)
    {
        if (Profits->objectName().isEmpty())
            Profits->setObjectName(QStringLiteral("Profits"));
        Profits->resize(400, 300);

        retranslateUi(Profits);

        QMetaObject::connectSlotsByName(Profits);
    } // setupUi

    void retranslateUi(QDialog *Profits)
    {
        Profits->setWindowTitle(QApplication::translate("Profits", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Profits: public Ui_Profits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFITS_H
