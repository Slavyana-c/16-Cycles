/********************************************************************************
** Form generated from reading UI file 'removebikes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEBIKES_H
#define UI_REMOVEBIKES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RemoveBikes
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *RemoveBikes)
    {
        if (RemoveBikes->objectName().isEmpty())
            RemoveBikes->setObjectName(QStringLiteral("RemoveBikes"));
        RemoveBikes->resize(1004, 724);
        goBackButton = new QPushButton(RemoveBikes);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(200, 150, 92, 36));

        retranslateUi(RemoveBikes);

        QMetaObject::connectSlotsByName(RemoveBikes);
    } // setupUi

    void retranslateUi(QDialog *RemoveBikes)
    {
        RemoveBikes->setWindowTitle(QApplication::translate("RemoveBikes", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("RemoveBikes", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RemoveBikes: public Ui_RemoveBikes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEBIKES_H
