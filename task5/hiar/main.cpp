#include "mainwindow.h"
#include <QApplication>
#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circul : public Shape{
private:
    double radius;

public:
    inline Circul(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }


    void set_radius(double r){if(r > 0){this->radius = r;}else {throw std::invalid_argument("Length and width must be positive");}}
    double get_radius() const{return radius;}

    double area() const override{return 3.14 * radius * radius;}

};

class Rectangle: public Shape {
private:
    double length;
    double width;

public:

inline Rectangle(double l, double w) : length(l), width(w) {
    if (length < 0 || width < 0) {
        throw std::invalid_argument("Length and width must be positive");
    }
}

void set_length(double l) {if(l > 0 ) {this->length = l;} else {throw std::invalid_argument("Length and width must be positive");} }

inline double get_length() const {
    return length;
}

void set_width(double w) {if(w > 0) { this->width = w; } else {throw std::invalid_argument("Length and width must be positive");}}

inline double get_width() const {
    return width;
}

inline double area() const {
    return length * width;
}
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Circul circ(6);
    Rectangle re(3, 7);

    re.set_length(4);
    std::cout << circ.get_radius() << std::endl;
    std::cout << re.get_length() << "  " << re.get_width() << std::endl;
    w.show();
    return a.exec();
}
