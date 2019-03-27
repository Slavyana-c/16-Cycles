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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName(QStringLiteral("Home"));
        Home->resize(851, 720);
        goBackButton = new QPushButton(Home);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(180, 230, 92, 36));

        retranslateUi(Home);

        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QDialog *Home)
    {
        Home->setWindowTitle(QApplication::translate("Home", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("Home", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
