/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *left;
    QLineEdit *left_2;
    QLabel *right;
    QLineEdit *right_2;
    QLabel *argument;
    QLineEdit *argument_2;
    QLabel *accurate;
    QLineEdit *epsilon;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *resN;
    QLabel *label_2;
    QLabel *resB;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(546, 423);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(10, 6, 111, 351));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(12, 32, 87, 104));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(127, 12, 411, 341));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 30, 181, 254));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        left = new QLabel(groupBox_3);
        left->setObjectName(QStringLiteral("left"));

        verticalLayout_2->addWidget(left);

        left_2 = new QLineEdit(groupBox_3);
        left_2->setObjectName(QStringLiteral("left_2"));

        verticalLayout_2->addWidget(left_2);

        right = new QLabel(groupBox_3);
        right->setObjectName(QStringLiteral("right"));

        verticalLayout_2->addWidget(right);

        right_2 = new QLineEdit(groupBox_3);
        right_2->setObjectName(QStringLiteral("right_2"));

        verticalLayout_2->addWidget(right_2);

        argument = new QLabel(groupBox_3);
        argument->setObjectName(QStringLiteral("argument"));

        verticalLayout_2->addWidget(argument);

        argument_2 = new QLineEdit(groupBox_3);
        argument_2->setObjectName(QStringLiteral("argument_2"));

        verticalLayout_2->addWidget(argument_2);

        accurate = new QLabel(groupBox_3);
        accurate->setObjectName(QStringLiteral("accurate"));

        verticalLayout_2->addWidget(accurate);

        epsilon = new QLineEdit(groupBox_3);
        epsilon->setObjectName(QStringLiteral("epsilon"));

        verticalLayout_2->addWidget(epsilon);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(210, 30, 201, 251));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        resN = new QLabel(groupBox_4);
        resN->setObjectName(QStringLiteral("resN"));
        QFont font;
        font.setUnderline(true);
        resN->setFont(font);

        verticalLayout_3->addWidget(resN);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        resB = new QLabel(groupBox_4);
        resB->setObjectName(QStringLiteral("resB"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        resB->setFont(font1);
        resB->setFrameShape(QFrame::Box);
        resB->setFrameShadow(QFrame::Plain);
        resB->setLineWidth(0);

        verticalLayout_3->addWidget(resB);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 22));
        MainWindow->setMenuBar(menuBar);
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
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\221\320\270\321\201\320\265\320\272\321\206\320\270\320\265\320\271", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\235\321\214\321\216\321\202\320\276\320\275\320\276\320\274", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "x^5+x+a=0", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 ", Q_NULLPTR));
        left->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260", Q_NULLPTR));
        left_2->setText(QApplication::translate("MainWindow", "-2", Q_NULLPTR));
        right->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260", Q_NULLPTR));
        right_2->setInputMask(QString());
        right_2->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        argument->setText(QApplication::translate("MainWindow", "\320\220\321\200\320\263\321\203\320\274\320\265\320\275\321\202 ( a )", Q_NULLPTR));
        argument_2->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        accurate->setText(QApplication::translate("MainWindow", "\320\255\320\277\321\201\320\270\320\273\320\276\320\275 \320\276\320\272\321\200\320\265\321\201\321\202\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        epsilon->setText(QApplication::translate("MainWindow", "0.0001", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276 \320\235\321\214\321\216\321\202\320\276\320\275\321\203:", Q_NULLPTR));
        resN->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276 \320\221\320\270\321\201\320\265\320\272\321\206\320\270\320\270:", Q_NULLPTR));
        resB->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
