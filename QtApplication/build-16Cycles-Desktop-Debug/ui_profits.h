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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profits
{
public:
    QGroupBox *groupBox;
    QPushButton *goBackButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *profitsTableView;
    QLabel *profitsSumLabel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *profitsFilterShop;
    QComboBox *profitsShopComboBox;

    void setupUi(QDialog *Profits)
    {
        if (Profits->objectName().isEmpty())
            Profits->setObjectName(QStringLiteral("Profits"));
        Profits->resize(961, 699);
        groupBox = new QGroupBox(Profits);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 921, 681));
        goBackButton = new QPushButton(groupBox);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(20, 260, 92, 36));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(240, 10, 681, 220));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        profitsTableView = new QTableView(widget);
        profitsTableView->setObjectName(QStringLiteral("profitsTableView"));

        verticalLayout->addWidget(profitsTableView);

        profitsSumLabel = new QLabel(widget);
        profitsSumLabel->setObjectName(QStringLiteral("profitsSumLabel"));

        verticalLayout->addWidget(profitsSumLabel);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 30, 222, 38));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        profitsFilterShop = new QLabel(widget1);
        profitsFilterShop->setObjectName(QStringLiteral("profitsFilterShop"));

        horizontalLayout->addWidget(profitsFilterShop);

        profitsShopComboBox = new QComboBox(widget1);
        profitsShopComboBox->setObjectName(QStringLiteral("profitsShopComboBox"));

        horizontalLayout->addWidget(profitsShopComboBox);


        retranslateUi(Profits);

        QMetaObject::connectSlotsByName(Profits);
    } // setupUi

    void retranslateUi(QDialog *Profits)
    {
        Profits->setWindowTitle(QApplication::translate("Profits", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Profits", "Profits", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("Profits", "Go Back", Q_NULLPTR));
        profitsSumLabel->setText(QApplication::translate("Profits", "Sum : ", Q_NULLPTR));
        profitsFilterShop->setText(QApplication::translate("Profits", "Filter By Shop ID", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Profits: public Ui_Profits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFITS_H
