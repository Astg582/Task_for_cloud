#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow mainWindow;


       QLabel *label = new QLabel("Hello World!");

       mainWindow.setCentralWidget(label);

       mainWindow.show();
    return a.exec();
}
