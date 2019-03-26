/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QLabel *label;
    QLabel *goToPageLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *EarningsButton;
    QPushButton *staffButton;
    QPushButton *UsageButton;
    QPushButton *editDBButton;
    QPushButton *logOutButton;

    void setupUi(QDialog *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QStringLiteral("home"));
        home->resize(755, 547);
        label = new QLabel(home);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 251, 81));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        goToPageLabel = new QLabel(home);
        goToPageLabel->setObjectName(QStringLiteral("goToPageLabel"));
        goToPageLabel->setGeometry(QRect(40, 120, 201, 51));
        goToPageLabel->setFont(font);
        widget = new QWidget(home);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(23, 193, 698, 59));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        EarningsButton = new QPushButton(widget);
        EarningsButton->setObjectName(QStringLiteral("EarningsButton"));
        EarningsButton->setFont(font);

        horizontalLayout->addWidget(EarningsButton);

        staffButton = new QPushButton(widget);
        staffButton->setObjectName(QStringLiteral("staffButton"));
        staffButton->setFont(font);

        horizontalLayout->addWidget(staffButton);

        UsageButton = new QPushButton(widget);
        UsageButton->setObjectName(QStringLiteral("UsageButton"));
        UsageButton->setFont(font);

        horizontalLayout->addWidget(UsageButton);

        editDBButton = new QPushButton(widget);
        editDBButton->setObjectName(QStringLiteral("editDBButton"));
        editDBButton->setFont(font);

        horizontalLayout->addWidget(editDBButton);

        logOutButton = new QPushButton(widget);
        logOutButton->setObjectName(QStringLiteral("logOutButton"));
        logOutButton->setFont(font);

        horizontalLayout->addWidget(logOutButton);


        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QDialog *home)
    {
        home->setWindowTitle(QApplication::translate("home", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("home", "YOU MADE IT!!!!!", Q_NULLPTR));
        goToPageLabel->setText(QApplication::translate("home", "Go To Page", Q_NULLPTR));
        EarningsButton->setText(QApplication::translate("home", "Earnings ", Q_NULLPTR));
        staffButton->setText(QApplication::translate("home", "Staff", Q_NULLPTR));
        UsageButton->setText(QApplication::translate("home", "Usage", Q_NULLPTR));
        editDBButton->setText(QApplication::translate("home", "Edit Database", Q_NULLPTR));
        logOutButton->setText(QApplication::translate("home", "Log Out", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
