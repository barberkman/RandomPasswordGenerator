#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "passwordgenerator.h"

#include <QMainWindow>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generate_clicked();

    void on_clear_clicked();

public slots:
    void slotErrorMatch();

private:
    Ui::MainWindow *ui;

    PasswordGenerator *pass_generator = nullptr;
    QString password = "";
    QShortcut *enterShortcut = nullptr;
};
#endif // MAINWINDOW_H
