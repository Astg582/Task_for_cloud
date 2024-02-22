#include "mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int i = 65;
    char c = 'c';
    int* ptrI = &i;
    char& refC = c;
    refC = 'R';
    *ptrI = 76;
    double D = 456.4;
    double* ptrD = &D;
    char ch = 'T';
    int intch = static_cast<int>(ch);
    int* ptrch = &intch;


    QString outputText = QString("this ptr int: %1\nthis referanc char %2\n double ptrD %3\nint ptr D %4")\
            .arg(*ptrI)
            .arg(refC)
            .arg(*ptrD)
            .arg(*ptrch);



     QLabel label(outputText);
     QVBoxLayout layout;
     layout.addWidget(&label);
     QWidget mainWindow;
     mainWindow.setLayout(&layout);
     mainWindow.show();
    return a.exec();
}
