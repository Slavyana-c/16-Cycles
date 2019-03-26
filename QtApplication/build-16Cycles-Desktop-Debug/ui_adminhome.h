/********************************************************************************
** Form generated from reading UI file 'adminhome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINHOME_H
#define UI_ADMINHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminHome
{
public:
    QGroupBox *welcomeGroupBox;
    QTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *staffGroupBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *staffUpdateButton;
    QPushButton *staffAddButton;
    QPushButton *staffRemoveButton;
    QPushButton *staffViewButton;
    QGroupBox *bikesGroupBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bikesUpdateButton;
    QPushButton *bikesAddButton;
    QPushButton *BikesRemoveButton;
    QPushButton *bikesViewButton;
    QGroupBox *ordersGroupBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ordersUpdateButton;
    QPushButton *ordersCreateButton;
    QPushButton *ordersRemoveButton;
    QPushButton *ordersViewButton;
    QGroupBox *earningsGroupBox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *earningsViewButton;
    QComboBox *comboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *adminLogOutButton;
    QPushButton *resetPasswordButton;

    void setupUi(QDialog *AdminHome)
    {
        if (AdminHome->objectName().isEmpty())
            AdminHome->setObjectName(QStringLiteral("AdminHome"));
        AdminHome->resize(1575, 579);
        welcomeGroupBox = new QGroupBox(AdminHome);
        welcomeGroupBox->setObjectName(QStringLiteral("welcomeGroupBox"));
        welcomeGroupBox->setGeometry(QRect(10, 10, 1541, 561));
        QFont font;
        font.setPointSize(24);
        welcomeGroupBox->setFont(font);
        tableView = new QTableView(welcomeGroupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(520, 50, 991, 441));
        layoutWidget = new QWidget(welcomeGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 52, 481, 441));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        staffGroupBox = new QGroupBox(layoutWidget);
        staffGroupBox->setObjectName(QStringLiteral("staffGroupBox"));
        layoutWidget1 = new QWidget(staffGroupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 40, 441, 59));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        staffUpdateButton = new QPushButton(layoutWidget1);
        staffUpdateButton->setObjectName(QStringLiteral("staffUpdateButton"));

        horizontalLayout->addWidget(staffUpdateButton);

        staffAddButton = new QPushButton(layoutWidget1);
        staffAddButton->setObjectName(QStringLiteral("staffAddButton"));

        horizontalLayout->addWidget(staffAddButton);

        staffRemoveButton = new QPushButton(layoutWidget1);
        staffRemoveButton->setObjectName(QStringLiteral("staffRemoveButton"));

        horizontalLayout->addWidget(staffRemoveButton);

        staffViewButton = new QPushButton(layoutWidget1);
        staffViewButton->setObjectName(QStringLiteral("staffViewButton"));

        horizontalLayout->addWidget(staffViewButton);


        verticalLayout->addWidget(staffGroupBox);

        bikesGroupBox = new QGroupBox(layoutWidget);
        bikesGroupBox->setObjectName(QStringLiteral("bikesGroupBox"));
        layoutWidget2 = new QWidget(bikesGroupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 441, 59));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bikesUpdateButton = new QPushButton(layoutWidget2);
        bikesUpdateButton->setObjectName(QStringLiteral("bikesUpdateButton"));

        horizontalLayout_2->addWidget(bikesUpdateButton);

        bikesAddButton = new QPushButton(layoutWidget2);
        bikesAddButton->setObjectName(QStringLiteral("bikesAddButton"));

        horizontalLayout_2->addWidget(bikesAddButton);

        BikesRemoveButton = new QPushButton(layoutWidget2);
        BikesRemoveButton->setObjectName(QStringLiteral("BikesRemoveButton"));

        horizontalLayout_2->addWidget(BikesRemoveButton);

        bikesViewButton = new QPushButton(layoutWidget2);
        bikesViewButton->setObjectName(QStringLiteral("bikesViewButton"));

        horizontalLayout_2->addWidget(bikesViewButton);


        verticalLayout->addWidget(bikesGroupBox);

        ordersGroupBox = new QGroupBox(layoutWidget);
        ordersGroupBox->setObjectName(QStringLiteral("ordersGroupBox"));
        layoutWidget3 = new QWidget(ordersGroupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 40, 461, 59));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ordersUpdateButton = new QPushButton(layoutWidget3);
        ordersUpdateButton->setObjectName(QStringLiteral("ordersUpdateButton"));

        horizontalLayout_3->addWidget(ordersUpdateButton);

        ordersCreateButton = new QPushButton(layoutWidget3);
        ordersCreateButton->setObjectName(QStringLiteral("ordersCreateButton"));

        horizontalLayout_3->addWidget(ordersCreateButton);

        ordersRemoveButton = new QPushButton(layoutWidget3);
        ordersRemoveButton->setObjectName(QStringLiteral("ordersRemoveButton"));

        horizontalLayout_3->addWidget(ordersRemoveButton);

        ordersViewButton = new QPushButton(layoutWidget3);
        ordersViewButton->setObjectName(QStringLiteral("ordersViewButton"));

        horizontalLayout_3->addWidget(ordersViewButton);


        verticalLayout->addWidget(ordersGroupBox);

        earningsGroupBox = new QGroupBox(layoutWidget);
        earningsGroupBox->setObjectName(QStringLiteral("earningsGroupBox"));
        layoutWidget4 = new QWidget(earningsGroupBox);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 40, 368, 59));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        earningsViewButton = new QPushButton(layoutWidget4);
        earningsViewButton->setObjectName(QStringLiteral("earningsViewButton"));

        horizontalLayout_4->addWidget(earningsViewButton);

        comboBox = new QComboBox(layoutWidget4);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout->addWidget(earningsGroupBox);

        widget = new QWidget(welcomeGroupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 500, 376, 59));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        adminLogOutButton = new QPushButton(widget);
        adminLogOutButton->setObjectName(QStringLiteral("adminLogOutButton"));

        horizontalLayout_5->addWidget(adminLogOutButton);

        resetPasswordButton = new QPushButton(widget);
        resetPasswordButton->setObjectName(QStringLiteral("resetPasswordButton"));

        horizontalLayout_5->addWidget(resetPasswordButton);


        retranslateUi(AdminHome);

        QMetaObject::connectSlotsByName(AdminHome);
    } // setupUi

    void retranslateUi(QDialog *AdminHome)
    {
        AdminHome->setWindowTitle(QApplication::translate("AdminHome", "Dialog", Q_NULLPTR));
        welcomeGroupBox->setTitle(QApplication::translate("AdminHome", "Welcome", Q_NULLPTR));
        staffGroupBox->setTitle(QApplication::translate("AdminHome", "Staff", Q_NULLPTR));
        staffUpdateButton->setText(QApplication::translate("AdminHome", "Update", Q_NULLPTR));
        staffAddButton->setText(QApplication::translate("AdminHome", "Add", Q_NULLPTR));
        staffRemoveButton->setText(QApplication::translate("AdminHome", "Remove", Q_NULLPTR));
        staffViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        bikesGroupBox->setTitle(QApplication::translate("AdminHome", "Bikes", Q_NULLPTR));
        bikesUpdateButton->setText(QApplication::translate("AdminHome", "Update", Q_NULLPTR));
        bikesAddButton->setText(QApplication::translate("AdminHome", "Add", Q_NULLPTR));
        BikesRemoveButton->setText(QApplication::translate("AdminHome", "Remove", Q_NULLPTR));
        bikesViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        ordersGroupBox->setTitle(QApplication::translate("AdminHome", "Orders", Q_NULLPTR));
        ordersUpdateButton->setText(QApplication::translate("AdminHome", "Update", Q_NULLPTR));
        ordersCreateButton->setText(QApplication::translate("AdminHome", "Create", Q_NULLPTR));
        ordersRemoveButton->setText(QApplication::translate("AdminHome", "Remove", Q_NULLPTR));
        ordersViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        earningsGroupBox->setTitle(QApplication::translate("AdminHome", "Earnings", Q_NULLPTR));
        earningsViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AdminHome", "Last Week", Q_NULLPTR)
         << QApplication::translate("AdminHome", "Last Month", Q_NULLPTR)
         << QApplication::translate("AdminHome", "Last 6 Months", Q_NULLPTR)
         << QApplication::translate("AdminHome", "Last Year", Q_NULLPTR)
         << QApplication::translate("AdminHome", "Last 2 Years", Q_NULLPTR)
         << QApplication::translate("AdminHome", "All TIme", Q_NULLPTR)
        );
        adminLogOutButton->setText(QApplication::translate("AdminHome", "Log Out", Q_NULLPTR));
        resetPasswordButton->setText(QApplication::translate("AdminHome", "Reset Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdminHome: public Ui_AdminHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOME_H
