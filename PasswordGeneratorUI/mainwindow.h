#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "evaluatorchance.h"
#include "passwordgenerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //Ui::MainWindow getMaintWindow();
    ~MainWindow();

private slots:
    void on_pushButtonFindPasswords_clicked();

    void on_action_triggered();

    void on_pushButtonClearListView_clicked();

private:
    Ui::MainWindow *ui;
    void findPasswords(
            const int &inputChancePower,
            const int &inputSpeed,
            const int &inputValidity,
            const int &inputCountPassword);

};

#endif // MAINWINDOW_H
