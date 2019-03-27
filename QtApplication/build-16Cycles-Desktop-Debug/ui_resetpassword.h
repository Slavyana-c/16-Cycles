/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_ResetPassword
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *oldPasswordLabel;
    QLineEdit *oldPasswordLineEdit;
    QLabel *newPasswordLabel;
    QLineEdit *newPasswordLineEdit;
    QLabel *ConfirmNewPasswordLabel;
    QLineEdit *ConfirmNewPasswordLineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *ResetPassword)
    {
        if (ResetPassword->objectName().isEmpty())
            ResetPassword->setObjectName(QStringLiteral("ResetPassword"));
        ResetPassword->resize(1010, 726);
        groupBox = new QGroupBox(ResetPassword);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 971, 671));
        QFont font;
        font.setPointSize(24);
        groupBox->setFont(font);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 50, 911, 326));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        oldPasswordLabel = new QLabel(widget);
        oldPasswordLabel->setObjectName(QStringLiteral("oldPasswordLabel"));

        verticalLayout->addWidget(oldPasswordLabel);

        oldPasswordLineEdit = new QLineEdit(widget);
        oldPasswordLineEdit->setObjectName(QStringLiteral("oldPasswordLineEdit"));
        oldPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(oldPasswordLineEdit);

        newPasswordLabel = new QLabel(widget);
        newPasswordLabel->setObjectName(QStringLiteral("newPasswordLabel"));

        verticalLayout->addWidget(newPasswordLabel);

        newPasswordLineEdit = new QLineEdit(widget);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));
        newPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(newPasswordLineEdit);

        ConfirmNewPasswordLabel = new QLabel(widget);
        ConfirmNewPasswordLabel->setObjectName(QStringLiteral("ConfirmNewPasswordLabel"));

        verticalLayout->addWidget(ConfirmNewPasswordLabel);

        ConfirmNewPasswordLineEdit = new QLineEdit(widget);
        ConfirmNewPasswordLineEdit->setObjectName(QStringLiteral("ConfirmNewPasswordLineEdit"));
        ConfirmNewPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(ConfirmNewPasswordLineEdit);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 390, 255, 59));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        confirmButton = new QPushButton(widget1);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        horizontalLayout->addWidget(confirmButton);


        retranslateUi(ResetPassword);

        QMetaObject::connectSlotsByName(ResetPassword);
    } // setupUi

    void retranslateUi(QDialog *ResetPassword)
    {
        ResetPassword->setWindowTitle(QApplication::translate("ResetPassword", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ResetPassword", "Reset Password", Q_NULLPTR));
        oldPasswordLabel->setText(QApplication::translate("ResetPassword", "Old Password", Q_NULLPTR));
        newPasswordLabel->setText(QApplication::translate("ResetPassword", "New Password", Q_NULLPTR));
        ConfirmNewPasswordLabel->setText(QApplication::translate("ResetPassword", "Confirm New Password", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ResetPassword", "Cancel", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ResetPassword", "Confirm ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResetPassword: public Ui_ResetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
