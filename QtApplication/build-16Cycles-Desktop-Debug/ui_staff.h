/********************************************************************************
** Form generated from reading UI file 'staff.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAFF_H
#define UI_STAFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_Staff
{
public:
    QGroupBox *groupBox;
    QPushButton *refreshButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTableView *staffTable;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *homeButton;
    QPushButton *addStaff;
    QPushButton *removeStaffButton;
    QPushButton *updateCurrentStaffButton;

    void setupUi(QDialog *Staff)
    {
        if (Staff->objectName().isEmpty())
            Staff->setObjectName(QStringLiteral("Staff"));
        Staff->resize(1066, 710);
        groupBox = new QGroupBox(Staff);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 1001, 631));
        QFont font;
        font.setPointSize(24);
        groupBox->setFont(font);
        refreshButton = new QPushButton(groupBox);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(430, 560, 151, 61));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 130, 981, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        staffTable = new QTableView(widget);
        staffTable->setObjectName(QStringLiteral("staffTable"));

        verticalLayout->addWidget(staffTable);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(12, 52, 779, 59));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        homeButton = new QPushButton(widget1);
        homeButton->setObjectName(QStringLiteral("homeButton"));
        homeButton->setFont(font);

        horizontalLayout->addWidget(homeButton);

        addStaff = new QPushButton(widget1);
        addStaff->setObjectName(QStringLiteral("addStaff"));
        addStaff->setFont(font);

        horizontalLayout->addWidget(addStaff);

        removeStaffButton = new QPushButton(widget1);
        removeStaffButton->setObjectName(QStringLiteral("removeStaffButton"));
        removeStaffButton->setFont(font);

        horizontalLayout->addWidget(removeStaffButton);

        updateCurrentStaffButton = new QPushButton(widget1);
        updateCurrentStaffButton->setObjectName(QStringLiteral("updateCurrentStaffButton"));

        horizontalLayout->addWidget(updateCurrentStaffButton);


        retranslateUi(Staff);

        QMetaObject::connectSlotsByName(Staff);
    } // setupUi

    void retranslateUi(QDialog *Staff)
    {
        Staff->setWindowTitle(QApplication::translate("Staff", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Staff", "Staff", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("Staff", "Refresh", Q_NULLPTR));
        label_2->setText(QApplication::translate("Staff", "Current Staff", Q_NULLPTR));
        homeButton->setText(QApplication::translate("Staff", "Home", Q_NULLPTR));
        addStaff->setText(QApplication::translate("Staff", "Add staff", Q_NULLPTR));
        removeStaffButton->setText(QApplication::translate("Staff", "Remove Staff", Q_NULLPTR));
        updateCurrentStaffButton->setText(QApplication::translate("Staff", "Update Current Staff", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Staff: public Ui_Staff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAFF_H
