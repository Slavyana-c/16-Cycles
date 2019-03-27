/********************************************************************************
** Form generated from reading UI file 'updatebikes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEBIKES_H
#define UI_UPDATEBIKES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpdateBikes
{
public:
    QPushButton *goBackButton;

    void setupUi(QDialog *UpdateBikes)
    {
        if (UpdateBikes->objectName().isEmpty())
            UpdateBikes->setObjectName(QStringLiteral("UpdateBikes"));
        UpdateBikes->resize(400, 300);
        goBackButton = new QPushButton(UpdateBikes);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));
        goBackButton->setGeometry(QRect(190, 160, 92, 36));

        retranslateUi(UpdateBikes);

        QMetaObject::connectSlotsByName(UpdateBikes);
    } // setupUi

    void retranslateUi(QDialog *UpdateBikes)
    {
        UpdateBikes->setWindowTitle(QApplication::translate("UpdateBikes", "Dialog", Q_NULLPTR));
        goBackButton->setText(QApplication::translate("UpdateBikes", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpdateBikes: public Ui_UpdateBikes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEBIKES_H
