/********************************************************************************
** Form generated from reading UI file 'addstaff.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTAFF_H
#define UI_ADDSTAFF_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStaff
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *confirmPasswordLabel;
    QLineEdit *confirmPasswordLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *contactNumberLabel;
    QLineEdit *contactNumberLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *adressLabel;
    QLineEdit *AddressLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *adminButton;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *shopIDComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *addStaffButton;

    void setupUi(QDialog *AddStaff)
    {
        if (AddStaff->objectName().isEmpty())
            AddStaff->setObjectName(QStringLiteral("AddStaff"));
        AddStaff->resize(1050, 760);
        groupBox = new QGroupBox(AddStaff);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 1001, 721));
        QFont font;
        font.setPointSize(24);
        groupBox->setFont(font);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 50, 941, 571));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font);

        horizontalLayout_2->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout_2->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        emailLabel = new QLabel(widget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setFont(font);

        horizontalLayout_3->addWidget(emailLabel);

        emailLineEdit = new QLineEdit(widget);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));

        horizontalLayout_3->addWidget(emailLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        passwordLabel = new QLabel(widget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setFont(font);

        horizontalLayout_4->addWidget(passwordLabel);

        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));

        horizontalLayout_4->addWidget(passwordLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        confirmPasswordLabel = new QLabel(widget);
        confirmPasswordLabel->setObjectName(QStringLiteral("confirmPasswordLabel"));
        confirmPasswordLabel->setFont(font);

        horizontalLayout_5->addWidget(confirmPasswordLabel);

        confirmPasswordLineEdit = new QLineEdit(widget);
        confirmPasswordLineEdit->setObjectName(QStringLiteral("confirmPasswordLineEdit"));

        horizontalLayout_5->addWidget(confirmPasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        contactNumberLabel = new QLabel(widget);
        contactNumberLabel->setObjectName(QStringLiteral("contactNumberLabel"));
        contactNumberLabel->setFont(font);

        horizontalLayout_6->addWidget(contactNumberLabel);

        contactNumberLineEdit = new QLineEdit(widget);
        contactNumberLineEdit->setObjectName(QStringLiteral("contactNumberLineEdit"));

        horizontalLayout_6->addWidget(contactNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        adressLabel = new QLabel(widget);
        adressLabel->setObjectName(QStringLiteral("adressLabel"));

        horizontalLayout_7->addWidget(adressLabel);

        AddressLineEdit = new QLineEdit(widget);
        AddressLineEdit->setObjectName(QStringLiteral("AddressLineEdit"));

        horizontalLayout_7->addWidget(AddressLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        adminButton = new QRadioButton(widget);
        adminButton->setObjectName(QStringLiteral("adminButton"));

        horizontalLayout_8->addWidget(adminButton);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        shopIDComboBox = new QComboBox(widget);
        shopIDComboBox->setObjectName(QStringLiteral("shopIDComboBox"));

        horizontalLayout_9->addWidget(shopIDComboBox);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        addStaffButton = new QPushButton(widget);
        addStaffButton->setObjectName(QStringLiteral("addStaffButton"));

        horizontalLayout->addWidget(addStaffButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddStaff);

        QMetaObject::connectSlotsByName(AddStaff);
    } // setupUi

    void retranslateUi(QDialog *AddStaff)
    {
        AddStaff->setWindowTitle(QApplication::translate("AddStaff", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AddStaff", "Add Staff Form", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("AddStaff", "Name                      ", Q_NULLPTR));
        emailLabel->setText(QApplication::translate("AddStaff", "Email                       ", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("AddStaff", "Password                ", Q_NULLPTR));
        confirmPasswordLabel->setText(QApplication::translate("AddStaff", "Confirm Password  ", Q_NULLPTR));
        contactNumberLabel->setText(QApplication::translate("AddStaff", "Contact Number     ", Q_NULLPTR));
        adressLabel->setText(QApplication::translate("AddStaff", "Address                   ", Q_NULLPTR));
        adminButton->setText(QApplication::translate("AddStaff", "Admin", Q_NULLPTR));
        shopIDComboBox->clear();
        shopIDComboBox->insertItems(0, QStringList()
         << QApplication::translate("AddStaff", "Shop ID 1", Q_NULLPTR)
         << QApplication::translate("AddStaff", "Shop ID 2", Q_NULLPTR)
         << QApplication::translate("AddStaff", "Shop ID 3", Q_NULLPTR)
        );
        cancelButton->setText(QApplication::translate("AddStaff", "Cancel", Q_NULLPTR));
        addStaffButton->setText(QApplication::translate("AddStaff", "Add Staff", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddStaff: public Ui_AddStaff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTAFF_H
