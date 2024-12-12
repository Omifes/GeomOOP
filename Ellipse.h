#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Point.h"
#include "FrameRectangle.h"
#include "Shape.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Ellipse : public Shape {
    friend istream& operator>>(istream& stream, Ellipse& element);
    friend ostream& operator<<(ostream& stream, const Ellipse& element);

private:
    Point pos_;
    double radiusVert_, radiusHor_;

public:
    // Конструкторы
    Ellipse(); // Конструктор по умолчанию
    Ellipse(double x, double y, double v, double h); // Конструктор с параметрами

    // Сеттеры
    void setPos(double x, double y);
    void setRadVert(double v);
    void setRadHor(double h);

    // Геттеры
    Point getPos() const;
    double getRadVert() const;
    double getRadHor() const;

    // Переопределенные методы из базового класса Shape
    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;

    void moveToPoint(Point pos) override;
    void moveToPoint(double k) override;
    void scale(double k) override;

    Shape* clone() const override; // Изменено на Shape*
    string getName() const override;

    void print(ostream& os) const override { // Реализация метода print
        os << *this;
    }
};

#endif // ELLIPSE_H
