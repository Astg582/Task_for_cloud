#include "mainwindow.h"
#include <QApplication>
#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
    void exept() const {
        throw std::invalid_argument("invalid argument");
    }
    virtual ~Shape() = default;
};

class Circul : public Shape{
private:
    double radius;

public:
    inline Circul(double r) : radius(r) {
        if (radius <= 0) {
            exept();
        }
    }


    void set_radius(double r){if(r > 0){this->radius = r;}else {exept();}}
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
        exept();
    }
}

void set_length(double l) {if(l > 0 ) {this->length = l;} else {exept();}}

inline double get_length() const {
    return length;
}

void set_width(double w) {if(w > 0) { this->width = w; } else {exept();}}

inline double get_width() const {
    return width;
}

inline double area() const {
    return length * width;
}
};

void Area (Shape* ptr){
    std::cout << ptr->area()<< std::endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Circul circ(6);
    Rectangle re(3, 7);

    re.set_length(4);
    std::cout << circ.get_radius() << std::endl;
    std::cout << re.get_length() << "  " << re.get_width() << std::endl;
    Circul* ptr = &circ;
    Rectangle* pR = &re;
    Area(ptr);
    Area(pR);

    w.show();
    return a.exec();
}
