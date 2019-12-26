/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_number;
    QLineEdit *lineEdit_capitalletter;
    QLabel *label_character;
    QLabel *label_number;
    QPushButton *generate;
    QLabel *label_passwordlength;
    QLabel *label_capitalletter;
    QTextBrowser *displaypassword;
    QLineEdit *lineEdit_passwordlength;
    QLineEdit *lineEdit_character;
    QPushButton *clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(579, 411);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_number = new QLineEdit(centralwidget);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));

        gridLayout->addWidget(lineEdit_number, 2, 2, 1, 1);

        lineEdit_capitalletter = new QLineEdit(centralwidget);
        lineEdit_capitalletter->setObjectName(QString::fromUtf8("lineEdit_capitalletter"));

        gridLayout->addWidget(lineEdit_capitalletter, 1, 2, 1, 1);

        label_character = new QLabel(centralwidget);
        label_character->setObjectName(QString::fromUtf8("label_character"));

        gridLayout->addWidget(label_character, 3, 0, 1, 1);

        label_number = new QLabel(centralwidget);
        label_number->setObjectName(QString::fromUtf8("label_number"));

        gridLayout->addWidget(label_number, 2, 0, 1, 1);

        generate = new QPushButton(centralwidget);
        generate->setObjectName(QString::fromUtf8("generate"));
        generate->setAutoDefault(false);

        gridLayout->addWidget(generate, 5, 0, 1, 3);

        label_passwordlength = new QLabel(centralwidget);
        label_passwordlength->setObjectName(QString::fromUtf8("label_passwordlength"));

        gridLayout->addWidget(label_passwordlength, 0, 0, 1, 2);

        label_capitalletter = new QLabel(centralwidget);
        label_capitalletter->setObjectName(QString::fromUtf8("label_capitalletter"));

        gridLayout->addWidget(label_capitalletter, 1, 0, 1, 2);

        displaypassword = new QTextBrowser(centralwidget);
        displaypassword->setObjectName(QString::fromUtf8("displaypassword"));

        gridLayout->addWidget(displaypassword, 4, 0, 1, 3);

        lineEdit_passwordlength = new QLineEdit(centralwidget);
        lineEdit_passwordlength->setObjectName(QString::fromUtf8("lineEdit_passwordlength"));
        lineEdit_passwordlength->setContextMenuPolicy(Qt::DefaultContextMenu);

        gridLayout->addWidget(lineEdit_passwordlength, 0, 2, 1, 1);

        lineEdit_character = new QLineEdit(centralwidget);
        lineEdit_character->setObjectName(QString::fromUtf8("lineEdit_character"));

        gridLayout->addWidget(lineEdit_character, 3, 2, 1, 1);

        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout->addWidget(clear, 6, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEdit_passwordlength, lineEdit_capitalletter);
        QWidget::setTabOrder(lineEdit_capitalletter, lineEdit_number);
        QWidget::setTabOrder(lineEdit_number, lineEdit_character);
        QWidget::setTabOrder(lineEdit_character, displaypassword);
        QWidget::setTabOrder(displaypassword, generate);
        QWidget::setTabOrder(generate, clear);

        retranslateUi(MainWindow);

        generate->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_number->setText(QApplication::translate("MainWindow", "0", nullptr));
        lineEdit_capitalletter->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_character->setText(QApplication::translate("MainWindow", "Character", nullptr));
        label_number->setText(QApplication::translate("MainWindow", "Number", nullptr));
        generate->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        label_passwordlength->setText(QApplication::translate("MainWindow", "Password Length", nullptr));
        label_capitalletter->setText(QApplication::translate("MainWindow", "Capital Letter", nullptr));
        lineEdit_character->setText(QApplication::translate("MainWindow", "0", nullptr));
        clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
