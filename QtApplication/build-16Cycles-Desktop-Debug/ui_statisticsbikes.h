/********************************************************************************
** Form generated from reading UI file 'statisticsbikes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSBIKES_H
#define UI_STATISTICSBIKES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StatisticsBikes
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *StatisticsBikes)
    {
        if (StatisticsBikes->objectName().isEmpty())
            StatisticsBikes->setObjectName(QStringLiteral("StatisticsBikes"));
        StatisticsBikes->resize(990, 715);
        goBackButton = new QPushButton(StatisticsBikes);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(160, 190, 92, 36));

        retranslateUi(StatisticsBikes);

        QMetaObject::connectSlotsByName(StatisticsBikes);
    } // setupUi

    void retranslateUi(QDialog *StatisticsBikes)
    {
        StatisticsBikes->setWindowTitle(QApplication::translate("StatisticsBikes", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("StatisticsBikes", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatisticsBikes: public Ui_StatisticsBikes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSBIKES_H
