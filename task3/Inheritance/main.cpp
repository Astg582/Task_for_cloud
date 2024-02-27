#include "mainwindow.h"
#include <QWidget>
#include <QIcon>
#include <QApplication>
#include <QFileInfo>
#include <QDebug>
#include <QCoreApplication>
#include <iostream>
#include <cmath>


class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() {}
};

class Circule : public Shape {
    private:
        double radius;

    public:
        Circule(double r) : radius(r) {}
        double calculateArea() const override {
               return M_PI * radius * radius;
           }
};

class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h) : width(w), height(h){}
        double calculateArea() const override {
                return width * height;
            }
};



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;


    window.resize(350, 400);
    window.setWindowTitle("Hous");

    QString absolutePath =  QCoreApplication::applicationDirPath() + "/house.png";


    qDebug() << "Absolute path to icon: " << absolutePath;


    if (QFileInfo(absolutePath).exists()) {
        window.setWindowIcon(QIcon(absolutePath));
    } else {
        qDebug() << "Файл иконки не найден.";
    }

    Circule circle(5.0);
       Rectangle rectangle(4.0, 6.0);

       Shape* shape1 = &circle;
         Shape* shape2 = &rectangle;

         std::cout << "Area of Circle: " << shape1->calculateArea() << std::endl;
         std::cout << "Area of Rectangle: " << shape2->calculateArea() << std::endl;


    window.show();

    return app.exec();
}
