/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *home;
    QGroupBox *singIn;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *quitButton;
    QPushButton *signInButton;
    QLineEdit *usernameLineEdit;
    QLabel *logo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1017, 597);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        home = new QGroupBox(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(10, 10, 981, 561));
        singIn = new QGroupBox(home);
        singIn->setObjectName(QStringLiteral("singIn"));
        singIn->setGeometry(QRect(290, 110, 701, 351));
        usernameLabel = new QLabel(singIn);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setGeometry(QRect(30, 112, 141, 41));
        QFont font;
        font.setPointSize(24);
        usernameLabel->setFont(font);
        usernameLabel->setTextFormat(Qt::AutoText);
        usernameLabel->setScaledContents(false);
        passwordLabel = new QLabel(singIn);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(30, 180, 141, 41));
        passwordLabel->setFont(font);
        passwordLineEdit = new QLineEdit(singIn);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(200, 170, 471, 51));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(singIn);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 121, 41));
        label->setFont(font);
        widget = new QWidget(singIn);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(390, 240, 281, 59));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setFont(font);

        horizontalLayout_3->addWidget(quitButton);

        signInButton = new QPushButton(widget);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        signInButton->setFont(font);

        horizontalLayout_3->addWidget(signInButton);

        usernameLineEdit = new QLineEdit(singIn);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(200, 106, 471, 51));
        usernameLineEdit->setFont(font);
        logo = new QLabel(home);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(20, 160, 201, 231));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        home->setTitle(QString());
        singIn->setTitle(QString());
        usernameLabel->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Sign In", Q_NULLPTR));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        signInButton->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
