/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_app
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *hur;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *mybutton;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *app)
    {
        if (app->objectName().isEmpty())
            app->setObjectName(QString::fromUtf8("app"));
        app->resize(800, 600);
        app->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color:rgb(33, 33, 33);\n"
"color: white;\n"
"}"));
        centralwidget = new QWidget(app);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 401, 531));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel  {\n"
"background-color : rgb(33, 33, 33);\n"
"color: white;\n"
"}"));

        verticalLayout->addWidget(label);

        hur = new QComboBox(verticalLayoutWidget);
        hur->addItem(QString());
        hur->addItem(QString());
        hur->addItem(QString());
        hur->addItem(QString());
        hur->setObjectName(QString::fromUtf8("hur"));
        hur->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgb(21, 21, 19);\n"
"    color: white; /* text color */\n"
"}"));

        verticalLayout->addWidget(hur);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        mybutton = new QPushButton(verticalLayoutWidget);
        mybutton->setObjectName(QString::fromUtf8("mybutton"));

        horizontalLayout->addWidget(mybutton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(430, 70, 341, 271));
        app->setCentralWidget(centralwidget);
        menubar = new QMenuBar(app);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        app->setMenuBar(menubar);
        statusbar = new QStatusBar(app);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        app->setStatusBar(statusbar);

        retranslateUi(app);

        QMetaObject::connectSlotsByName(app);
    } // setupUi

    void retranslateUi(QMainWindow *app)
    {
        app->setWindowTitle(QCoreApplication::translate("app", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("app", "choose the huristc you wanna solve the problem:", nullptr));
        hur->setItemText(0, QCoreApplication::translate("app", "Hueristic 1", nullptr));
        hur->setItemText(1, QCoreApplication::translate("app", "Hueristic 2", nullptr));
        hur->setItemText(2, QCoreApplication::translate("app", "Hueristic 3", nullptr));
        hur->setItemText(3, QCoreApplication::translate("app", "Hueristic 4", nullptr));

        pushButton_2->setText(QCoreApplication::translate("app", "Fill Data", nullptr));
        mybutton->setText(QCoreApplication::translate("app", "Start algorithme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class app: public Ui_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
