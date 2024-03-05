#include "mainwindow.h"

#include <QApplication>
#include "menu_bar.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Menu_bar window;
    window.resize(800, 150);
    window.setWindowTitle("Server");

    window.show();
    return app.exec();
}
