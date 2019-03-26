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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *adminLogOutButton;
    QPushButton *resetPasswordButton;
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *staffGroupBox;
    QPushButton *staffUpdateButton;
    QPushButton *staffAddButton;
    QPushButton *staffRemoveButton;
    QPushButton *staffViewButton;
    QGroupBox *bikesGroupBox;
    QPushButton *bikesUpdateButton;
    QPushButton *bikesAddButton;
    QPushButton *BikesRemoveButton;
    QPushButton *bikesViewButton;
    QGroupBox *ordersGroupBox;
    QPushButton *ordersUpdateButton;
    QPushButton *ordersCreateButton;
    QPushButton *ordersRemoveButton;
    QPushButton *ordersViewButton;

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
        layoutWidget = new QWidget(welcomeGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 390, 376, 59));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        adminLogOutButton = new QPushButton(layoutWidget);
        adminLogOutButton->setObjectName(QStringLiteral("adminLogOutButton"));

        horizontalLayout_5->addWidget(adminLogOutButton);

        resetPasswordButton = new QPushButton(layoutWidget);
        resetPasswordButton->setObjectName(QStringLiteral("resetPasswordButton"));

        horizontalLayout_5->addWidget(resetPasswordButton);

        groupBox = new QGroupBox(welcomeGroupBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 220, 461, 71));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 20, 184, 39));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        staffGroupBox = new QGroupBox(welcomeGroupBox);
        staffGroupBox->setObjectName(QStringLiteral("staffGroupBox"));
        staffGroupBox->setGeometry(QRect(0, 20, 479, 71));
        staffUpdateButton = new QPushButton(staffGroupBox);
        staffUpdateButton->setObjectName(QStringLiteral("staffUpdateButton"));
        staffUpdateButton->setGeometry(QRect(1, 21, 88, 37));
        staffAddButton = new QPushButton(staffGroupBox);
        staffAddButton->setObjectName(QStringLiteral("staffAddButton"));
        staffAddButton->setGeometry(QRect(112, 21, 88, 37));
        staffRemoveButton = new QPushButton(staffGroupBox);
        staffRemoveButton->setObjectName(QStringLiteral("staffRemoveButton"));
        staffRemoveButton->setGeometry(QRect(224, 21, 88, 37));
        staffViewButton = new QPushButton(staffGroupBox);
        staffViewButton->setObjectName(QStringLiteral("staffViewButton"));
        staffViewButton->setGeometry(QRect(335, 21, 88, 37));
        bikesGroupBox = new QGroupBox(welcomeGroupBox);
        bikesGroupBox->setObjectName(QStringLiteral("bikesGroupBox"));
        bikesGroupBox->setGeometry(QRect(0, 90, 479, 71));
        bikesUpdateButton = new QPushButton(bikesGroupBox);
        bikesUpdateButton->setObjectName(QStringLiteral("bikesUpdateButton"));
        bikesUpdateButton->setGeometry(QRect(1, 21, 88, 37));
        bikesAddButton = new QPushButton(bikesGroupBox);
        bikesAddButton->setObjectName(QStringLiteral("bikesAddButton"));
        bikesAddButton->setGeometry(QRect(112, 21, 88, 37));
        BikesRemoveButton = new QPushButton(bikesGroupBox);
        BikesRemoveButton->setObjectName(QStringLiteral("BikesRemoveButton"));
        BikesRemoveButton->setGeometry(QRect(224, 21, 88, 37));
        bikesViewButton = new QPushButton(bikesGroupBox);
        bikesViewButton->setObjectName(QStringLiteral("bikesViewButton"));
        bikesViewButton->setGeometry(QRect(335, 21, 88, 37));
        ordersGroupBox = new QGroupBox(welcomeGroupBox);
        ordersGroupBox->setObjectName(QStringLiteral("ordersGroupBox"));
        ordersGroupBox->setGeometry(QRect(0, 160, 479, 71));
        ordersUpdateButton = new QPushButton(ordersGroupBox);
        ordersUpdateButton->setObjectName(QStringLiteral("ordersUpdateButton"));
        ordersUpdateButton->setGeometry(QRect(1, 21, 88, 37));
        ordersCreateButton = new QPushButton(ordersGroupBox);
        ordersCreateButton->setObjectName(QStringLiteral("ordersCreateButton"));
        ordersCreateButton->setGeometry(QRect(117, 21, 88, 37));
        ordersRemoveButton = new QPushButton(ordersGroupBox);
        ordersRemoveButton->setObjectName(QStringLiteral("ordersRemoveButton"));
        ordersRemoveButton->setGeometry(QRect(234, 21, 88, 37));
        ordersViewButton = new QPushButton(ordersGroupBox);
        ordersViewButton->setObjectName(QStringLiteral("ordersViewButton"));
        ordersViewButton->setGeometry(QRect(350, 21, 88, 37));

        retranslateUi(AdminHome);

        QMetaObject::connectSlotsByName(AdminHome);
    } // setupUi

    void retranslateUi(QDialog *AdminHome)
    {
        AdminHome->setWindowTitle(QApplication::translate("AdminHome", "Dialog", Q_NULLPTR));
        welcomeGroupBox->setTitle(QApplication::translate("AdminHome", "Welcome", Q_NULLPTR));
        adminLogOutButton->setText(QApplication::translate("AdminHome", "Log Out", Q_NULLPTR));
        resetPasswordButton->setText(QApplication::translate("AdminHome", "Reset Password", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AdminHome", "Statistics", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AdminHome", "Profits", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AdminHome", "Bikes", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class AdminHome: public Ui_AdminHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOME_H
