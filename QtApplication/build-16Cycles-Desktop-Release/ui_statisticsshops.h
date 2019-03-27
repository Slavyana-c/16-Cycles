/********************************************************************************
** Form generated from reading UI file 'statisticsshops.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSSHOPS_H
#define UI_STATISTICSSHOPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StatisticsShops
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *StatisticsShops)
    {
        if (StatisticsShops->objectName().isEmpty())
            StatisticsShops->setObjectName(QStringLiteral("StatisticsShops"));
        StatisticsShops->resize(946, 708);
        goBackButton = new QPushButton(StatisticsShops);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(240, 240, 92, 36));

        retranslateUi(StatisticsShops);

        QMetaObject::connectSlotsByName(StatisticsShops);
    } // setupUi

    void retranslateUi(QDialog *StatisticsShops)
    {
        StatisticsShops->setWindowTitle(QApplication::translate("StatisticsShops", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("StatisticsShops", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatisticsShops: public Ui_StatisticsShops {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSSHOPS_H
