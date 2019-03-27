/********************************************************************************
** Form generated from reading UI file 'addbiketypes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBIKETYPES_H
#define UI_ADDBIKETYPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddBikeTypes
{
public:
    QPushButton *goBackButtonn;

    void setupUi(QDialog *AddBikeTypes)
    {
        if (AddBikeTypes->objectName().isEmpty())
            AddBikeTypes->setObjectName(QStringLiteral("AddBikeTypes"));
        AddBikeTypes->resize(944, 694);
        goBackButtonn = new QPushButton(AddBikeTypes);
        goBackButtonn->setObjectName(QStringLiteral("goBackButtonn"));
        goBackButtonn->setGeometry(QRect(70, 80, 92, 36));

        retranslateUi(AddBikeTypes);

        QMetaObject::connectSlotsByName(AddBikeTypes);
    } // setupUi

    void retranslateUi(QDialog *AddBikeTypes)
    {
        AddBikeTypes->setWindowTitle(QApplication::translate("AddBikeTypes", "Dialog", Q_NULLPTR));
        goBackButtonn->setText(QApplication::translate("AddBikeTypes", "Go Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddBikeTypes: public Ui_AddBikeTypes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBIKETYPES_H
