#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//default header files
#include <QMainWindow>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButtonLoad_clicked();

    void on_pushButtonRun_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
