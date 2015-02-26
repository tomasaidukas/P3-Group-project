#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    system("./run.sh &");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
