/********************************************************************************
** Form generated from reading UI file 'editdb.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDB_H
#define UI_EDITDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EditDb
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *EditDb)
    {
        if (EditDb->objectName().isEmpty())
            EditDb->setObjectName(QStringLiteral("EditDb"));
        EditDb->resize(752, 584);
        label = new QLabel(EditDb);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 551, 101));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(EditDb);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 310, 341, 161));

        retranslateUi(EditDb);

        QMetaObject::connectSlotsByName(EditDb);
    } // setupUi

    void retranslateUi(QDialog *EditDb)
    {
        EditDb->setWindowTitle(QApplication::translate("EditDb", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("EditDb", "EDIT DB!!!!", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditDb", "Nope", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditDb: public Ui_EditDb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDB_H
