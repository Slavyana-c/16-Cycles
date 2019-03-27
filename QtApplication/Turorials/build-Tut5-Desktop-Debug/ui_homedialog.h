/********************************************************************************
** Form generated from reading UI file 'homedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEDIALOG_H
#define UI_HOMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HomeDialog
{
public:
    QLabel *labelWoohoo;

    void setupUi(QDialog *HomeDialog)
    {
        if (HomeDialog->objectName().isEmpty())
            HomeDialog->setObjectName(QStringLiteral("HomeDialog"));
        HomeDialog->resize(400, 300);
        labelWoohoo = new QLabel(HomeDialog);
        labelWoohoo->setObjectName(QStringLiteral("labelWoohoo"));
        labelWoohoo->setGeometry(QRect(120, 90, 181, 71));

        retranslateUi(HomeDialog);

        QMetaObject::connectSlotsByName(HomeDialog);
    } // setupUi

    void retranslateUi(QDialog *HomeDialog)
    {
        HomeDialog->setWindowTitle(QApplication::translate("HomeDialog", "Dialog", Q_NULLPTR));
        labelWoohoo->setText(QApplication::translate("HomeDialog", "Woohoo you made it", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomeDialog: public Ui_HomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEDIALOG_H
