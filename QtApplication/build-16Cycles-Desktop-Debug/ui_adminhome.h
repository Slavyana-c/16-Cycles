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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminHome
{
public:
    QGroupBox *welcomeGroupBox;
    QTableView *tableView;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *statisticsProfitsButton;
    QPushButton *statisticsBikesButton;
    QGroupBox *staffGroupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *staffUpdateButton;
    QPushButton *staffAddButton;
    QPushButton *staffRemoveButton;
    QPushButton *staffViewButton;
    QGroupBox *bikesGroupBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *bikesUpdateButton;
    QPushButton *bikesAddBikeButton;
    QPushButton *bikesAddTypeButton;
    QPushButton *BikesRemoveButton;
    QPushButton *bikesViewButton;
    QGroupBox *ordersGroupBox;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ordersUpdateButton;
    QPushButton *ordersCreateButton;
    QPushButton *ordersRemoveButton;
    QPushButton *ordersViewButton;
    QWidget *widget3;
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
        font.setPointSize(12);
        welcomeGroupBox->setFont(font);
        tableView = new QTableView(welcomeGroupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(520, 50, 991, 441));
        groupBox = new QGroupBox(welcomeGroupBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 230, 461, 71));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 184, 39));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        statisticsProfitsButton = new QPushButton(layoutWidget);
        statisticsProfitsButton->setObjectName(QStringLiteral("statisticsProfitsButton"));

        horizontalLayout_4->addWidget(statisticsProfitsButton);

        statisticsBikesButton = new QPushButton(layoutWidget);
        statisticsBikesButton->setObjectName(QStringLiteral("statisticsBikesButton"));

        horizontalLayout_4->addWidget(statisticsBikesButton);

        staffGroupBox = new QGroupBox(welcomeGroupBox);
        staffGroupBox->setObjectName(QStringLiteral("staffGroupBox"));
        staffGroupBox->setGeometry(QRect(0, 30, 479, 71));
        widget = new QWidget(staffGroupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 21, 372, 39));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        staffUpdateButton = new QPushButton(widget);
        staffUpdateButton->setObjectName(QStringLiteral("staffUpdateButton"));

        horizontalLayout_2->addWidget(staffUpdateButton);

        staffAddButton = new QPushButton(widget);
        staffAddButton->setObjectName(QStringLiteral("staffAddButton"));

        horizontalLayout_2->addWidget(staffAddButton);

        staffRemoveButton = new QPushButton(widget);
        staffRemoveButton->setObjectName(QStringLiteral("staffRemoveButton"));

        horizontalLayout_2->addWidget(staffRemoveButton);

        staffViewButton = new QPushButton(widget);
        staffViewButton->setObjectName(QStringLiteral("staffViewButton"));

        horizontalLayout_2->addWidget(staffViewButton);

        bikesGroupBox = new QGroupBox(welcomeGroupBox);
        bikesGroupBox->setObjectName(QStringLiteral("bikesGroupBox"));
        bikesGroupBox->setGeometry(QRect(0, 100, 479, 71));
        widget1 = new QWidget(bikesGroupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(1, 20, 466, 39));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bikesUpdateButton = new QPushButton(widget1);
        bikesUpdateButton->setObjectName(QStringLiteral("bikesUpdateButton"));

        horizontalLayout->addWidget(bikesUpdateButton);

        bikesAddBikeButton = new QPushButton(widget1);
        bikesAddBikeButton->setObjectName(QStringLiteral("bikesAddBikeButton"));

        horizontalLayout->addWidget(bikesAddBikeButton);

        bikesAddTypeButton = new QPushButton(widget1);
        bikesAddTypeButton->setObjectName(QStringLiteral("bikesAddTypeButton"));

        horizontalLayout->addWidget(bikesAddTypeButton);

        BikesRemoveButton = new QPushButton(widget1);
        BikesRemoveButton->setObjectName(QStringLiteral("BikesRemoveButton"));

        horizontalLayout->addWidget(BikesRemoveButton);

        bikesViewButton = new QPushButton(widget1);
        bikesViewButton->setObjectName(QStringLiteral("bikesViewButton"));

        horizontalLayout->addWidget(bikesViewButton);

        ordersGroupBox = new QGroupBox(welcomeGroupBox);
        ordersGroupBox->setObjectName(QStringLiteral("ordersGroupBox"));
        ordersGroupBox->setGeometry(QRect(0, 160, 479, 71));
        widget2 = new QWidget(ordersGroupBox);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(1, 21, 372, 39));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ordersUpdateButton = new QPushButton(widget2);
        ordersUpdateButton->setObjectName(QStringLiteral("ordersUpdateButton"));

        horizontalLayout_3->addWidget(ordersUpdateButton);

        ordersCreateButton = new QPushButton(widget2);
        ordersCreateButton->setObjectName(QStringLiteral("ordersCreateButton"));

        horizontalLayout_3->addWidget(ordersCreateButton);

        ordersRemoveButton = new QPushButton(widget2);
        ordersRemoveButton->setObjectName(QStringLiteral("ordersRemoveButton"));

        horizontalLayout_3->addWidget(ordersRemoveButton);

        ordersViewButton = new QPushButton(widget2);
        ordersViewButton->setObjectName(QStringLiteral("ordersViewButton"));

        horizontalLayout_3->addWidget(ordersViewButton);

        widget3 = new QWidget(welcomeGroupBox);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(1, 401, 223, 39));
        horizontalLayout_5 = new QHBoxLayout(widget3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        adminLogOutButton = new QPushButton(widget3);
        adminLogOutButton->setObjectName(QStringLiteral("adminLogOutButton"));

        horizontalLayout_5->addWidget(adminLogOutButton);

        resetPasswordButton = new QPushButton(widget3);
        resetPasswordButton->setObjectName(QStringLiteral("resetPasswordButton"));

        horizontalLayout_5->addWidget(resetPasswordButton);


        retranslateUi(AdminHome);

        QMetaObject::connectSlotsByName(AdminHome);
    } // setupUi

    void retranslateUi(QDialog *AdminHome)
    {
        AdminHome->setWindowTitle(QApplication::translate("AdminHome", "Dialog", Q_NULLPTR));
        welcomeGroupBox->setTitle(QApplication::translate("AdminHome", "Welcome", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AdminHome", "Statistics", Q_NULLPTR));
        statisticsProfitsButton->setText(QApplication::translate("AdminHome", "Profits", Q_NULLPTR));
        statisticsBikesButton->setText(QApplication::translate("AdminHome", "Bikes", Q_NULLPTR));
        staffGroupBox->setTitle(QApplication::translate("AdminHome", "Staff", Q_NULLPTR));
        staffUpdateButton->setText(QApplication::translate("AdminHome", "Update", Q_NULLPTR));
        staffAddButton->setText(QApplication::translate("AdminHome", "Add", Q_NULLPTR));
        staffRemoveButton->setText(QApplication::translate("AdminHome", "Remove", Q_NULLPTR));
        staffViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        bikesGroupBox->setTitle(QApplication::translate("AdminHome", "Bikes", Q_NULLPTR));
        bikesUpdateButton->setText(QApplication::translate("AdminHome", "Update", Q_NULLPTR));
        bikesAddBikeButton->setText(QApplication::translate("AdminHome", "Add Bike", Q_NULLPTR));
        bikesAddTypeButton->setText(QApplication::translate("AdminHome", "Add Type", Q_NULLPTR));
        BikesRemoveButton->setText(QApplication::translate("AdminHome", "Remove", Q_NULLPTR));
        bikesViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        ordersGroupBox->setTitle(QApplication::translate("AdminHome", "Orders", Q_NULLPTR));
        ordersUpdateButton->setText(QApplication::translate("AdminHome", "Update", Q_NULLPTR));
        ordersCreateButton->setText(QApplication::translate("AdminHome", "Create", Q_NULLPTR));
        ordersRemoveButton->setText(QApplication::translate("AdminHome", "Remove", Q_NULLPTR));
        ordersViewButton->setText(QApplication::translate("AdminHome", "View", Q_NULLPTR));
        adminLogOutButton->setText(QApplication::translate("AdminHome", "Log Out", Q_NULLPTR));
        resetPasswordButton->setText(QApplication::translate("AdminHome", "Reset Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdminHome: public Ui_AdminHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOME_H
