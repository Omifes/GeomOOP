#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "FrameRectangle.h"
#include "Shape.h"
#include <string>
#include <iostream>
#include <iomanip>

class Square : public Shape {
    friend istream& operator>>(istream& stream, Square& element);
    friend ostream& operator<<(ostream& stream, const Square& element);

private:
    Point pos_;
    double side_;

public:
    // Конструкторы
    Square(); // Конструктор по умолчанию
    Square(double x, double y, double s); // Конструктор с параметрами

    // Сеттеры
    void setPos(double x, double y);
    void setSide(double v);

    // Геттеры
    Point getPos() const;
    double getSide() const;

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

#endif // SQUARE_H

