#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <stdlib.h>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Password Generator");

    enterShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(enterShortcut, &QShortcut::activated,
            this, &MainWindow::on_generate_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generate_clicked()
{
    int password_lentgh = ui->lineEdit_passwordlength->text().toInt();
    int capitalLetter_length = ui->lineEdit_capitalletter->text().toInt();
    int number_length = ui->lineEdit_number->text().toInt();
    int character_length = ui->lineEdit_character->text().toInt();
    int smallLetter_length = 0;

    if (password_lentgh > (capitalLetter_length + number_length + character_length)){
        smallLetter_length = password_lentgh - (capitalLetter_length + number_length + character_length);
    } else {
        exit(EXIT_FAILURE);
    }

    pass_generator = new PasswordGenerator(password_lentgh, smallLetter_length, capitalLetter_length, number_length, character_length);

    password = pass_generator->convertPasswordMapToString();

//    ui->displaypassword->setText(password);
    ui->displaypassword->append(password);

    delete pass_generator;
}

void MainWindow::slotErrorMatch()
{
    qDebug() << "Slot Error Match";
}

void MainWindow::on_clear_clicked()
{
    ui->displaypassword->clear();
}
