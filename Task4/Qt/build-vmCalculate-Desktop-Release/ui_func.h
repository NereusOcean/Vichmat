/********************************************************************************
** Form generated from reading UI file 'func.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNC_H
#define UI_FUNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Func
{
public:
    QLabel *outputGraph;

    void setupUi(QDialog *Func)
    {
        if (Func->objectName().isEmpty())
            Func->setObjectName(QStringLiteral("Func"));
        Func->resize(606, 448);
        outputGraph = new QLabel(Func);
        outputGraph->setObjectName(QStringLiteral("outputGraph"));
        outputGraph->setGeometry(QRect(16, 16, 571, 411));

        retranslateUi(Func);

        QMetaObject::connectSlotsByName(Func);
    } // setupUi

    void retranslateUi(QDialog *Func)
    {
        Func->setWindowTitle(QApplication::translate("Func", "Dialog", Q_NULLPTR));
        outputGraph->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Func: public Ui_Func {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNC_H
