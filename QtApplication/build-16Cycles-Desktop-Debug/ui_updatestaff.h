/********************************************************************************
** Form generated from reading UI file 'updatestaff.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATESTAFF_H
#define UI_UPDATESTAFF_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateStaff
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *currentIDLabel;
    QLabel *currentNameLabel;
    QLabel *currentEmailLabel;
    QLabel *currentContactNumberLabel;
    QLabel *currentAddressLabel;
    QLabel *currentShopLabel;
    QLabel *currentAdminRightsLabel;
    QGroupBox *groupBox_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *updatePersonalDetailsLineEdit;
    QComboBox *personalDetailsComboBox;
    QPushButton *updatePersonalDetailsButton;
    QGroupBox *groupBox_5;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *updateAdminComboBox;
    QPushButton *updateAdminButton;
    QPushButton *cancelButton;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QPushButton *findButton;

    void setupUi(QDialog *UpdateStaff)
    {
        if (UpdateStaff->objectName().isEmpty())
            UpdateStaff->setObjectName(QStringLiteral("UpdateStaff"));
        UpdateStaff->resize(989, 835);
        groupBox = new QGroupBox(UpdateStaff);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 931, 821));
        QFont font;
        font.setPointSize(24);
        groupBox->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1, 131, 929, 411));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 51, 881, 325));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        currentIDLabel = new QLabel(widget);
        currentIDLabel->setObjectName(QStringLiteral("currentIDLabel"));

        verticalLayout->addWidget(currentIDLabel);

        currentNameLabel = new QLabel(widget);
        currentNameLabel->setObjectName(QStringLiteral("currentNameLabel"));

        verticalLayout->addWidget(currentNameLabel);

        currentEmailLabel = new QLabel(widget);
        currentEmailLabel->setObjectName(QStringLiteral("currentEmailLabel"));

        verticalLayout->addWidget(currentEmailLabel);

        currentContactNumberLabel = new QLabel(widget);
        currentContactNumberLabel->setObjectName(QStringLiteral("currentContactNumberLabel"));

        verticalLayout->addWidget(currentContactNumberLabel);

        currentAddressLabel = new QLabel(widget);
        currentAddressLabel->setObjectName(QStringLiteral("currentAddressLabel"));

        verticalLayout->addWidget(currentAddressLabel);

        currentShopLabel = new QLabel(widget);
        currentShopLabel->setObjectName(QStringLiteral("currentShopLabel"));

        verticalLayout->addWidget(currentShopLabel);

        currentAdminRightsLabel = new QLabel(widget);
        currentAdminRightsLabel->setObjectName(QStringLiteral("currentAdminRightsLabel"));

        verticalLayout->addWidget(currentAdminRightsLabel);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(2, 521, 889, 121));
        widget1 = new QWidget(groupBox_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 50, 645, 59));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        updatePersonalDetailsLineEdit = new QLineEdit(widget1);
        updatePersonalDetailsLineEdit->setObjectName(QStringLiteral("updatePersonalDetailsLineEdit"));

        horizontalLayout_2->addWidget(updatePersonalDetailsLineEdit);

        personalDetailsComboBox = new QComboBox(widget1);
        personalDetailsComboBox->setObjectName(QStringLiteral("personalDetailsComboBox"));

        horizontalLayout_2->addWidget(personalDetailsComboBox);

        updatePersonalDetailsButton = new QPushButton(widget1);
        updatePersonalDetailsButton->setObjectName(QStringLiteral("updatePersonalDetailsButton"));

        horizontalLayout_2->addWidget(updatePersonalDetailsButton);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(2, 640, 889, 111));
        widget2 = new QWidget(groupBox_5);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 40, 248, 59));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        updateAdminComboBox = new QComboBox(widget2);
        updateAdminComboBox->setObjectName(QStringLiteral("updateAdminComboBox"));

        horizontalLayout_3->addWidget(updateAdminComboBox);

        updateAdminButton = new QPushButton(widget2);
        updateAdminButton->setObjectName(QStringLiteral("updateAdminButton"));

        horizontalLayout_3->addWidget(updateAdminButton);

        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(10, 750, 110, 57));
        widget3 = new QWidget(groupBox);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(12, 52, 451, 59));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        emailLabel = new QLabel(widget3);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        horizontalLayout->addWidget(emailLabel);

        emailLineEdit = new QLineEdit(widget3);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));

        horizontalLayout->addWidget(emailLineEdit);

        findButton = new QPushButton(widget3);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout->addWidget(findButton);


        retranslateUi(UpdateStaff);

        QMetaObject::connectSlotsByName(UpdateStaff);
    } // setupUi

    void retranslateUi(QDialog *UpdateStaff)
    {
        UpdateStaff->setWindowTitle(QApplication::translate("UpdateStaff", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UpdateStaff", "Update Staff", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("UpdateStaff", "Current Details", Q_NULLPTR));
        currentIDLabel->setText(QApplication::translate("UpdateStaff", "ID :", Q_NULLPTR));
        currentNameLabel->setText(QApplication::translate("UpdateStaff", "Name : ", Q_NULLPTR));
        currentEmailLabel->setText(QApplication::translate("UpdateStaff", "Email :", Q_NULLPTR));
        currentContactNumberLabel->setText(QApplication::translate("UpdateStaff", "Contact Number :", Q_NULLPTR));
        currentAddressLabel->setText(QApplication::translate("UpdateStaff", "Address :", Q_NULLPTR));
        currentShopLabel->setText(QApplication::translate("UpdateStaff", "Shop :", Q_NULLPTR));
        currentAdminRightsLabel->setText(QApplication::translate("UpdateStaff", "Admin Rights : ", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("UpdateStaff", "Update Personal Details", Q_NULLPTR));
        personalDetailsComboBox->clear();
        personalDetailsComboBox->insertItems(0, QStringList()
         << QApplication::translate("UpdateStaff", "Name", Q_NULLPTR)
         << QApplication::translate("UpdateStaff", "Email", Q_NULLPTR)
         << QApplication::translate("UpdateStaff", "Contact Number", Q_NULLPTR)
         << QApplication::translate("UpdateStaff", "Address", Q_NULLPTR)
        );
        updatePersonalDetailsButton->setText(QApplication::translate("UpdateStaff", "Update", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("UpdateStaff", "Update Admin", Q_NULLPTR));
        updateAdminComboBox->clear();
        updateAdminComboBox->insertItems(0, QStringList()
         << QApplication::translate("UpdateStaff", "Yes", Q_NULLPTR)
         << QApplication::translate("UpdateStaff", "No", Q_NULLPTR)
        );
        updateAdminButton->setText(QApplication::translate("UpdateStaff", "Update", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("UpdateStaff", "Cancel", Q_NULLPTR));
        emailLabel->setText(QApplication::translate("UpdateStaff", "Email", Q_NULLPTR));
        findButton->setText(QApplication::translate("UpdateStaff", "Find", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpdateStaff: public Ui_UpdateStaff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATESTAFF_H
