#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "JsonInterraction.h"

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
    void on_pushButton_clicked();

    void on_WindowsButton_clicked();

    void on_PS4Button_clicked();

    void on_XboxButton_clicked();

private:
    Ui::MainWindow *ui;
    JsonInterraction data;
};
#endif // MAINWINDOW_H
