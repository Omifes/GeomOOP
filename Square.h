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
    // ������������
    Square(); // ����������� �� ���������
    Square(double x, double y, double s); // ����������� � �����������

    // �������
    void setPos(double x, double y);
    void setSide(double v);

    // �������
    Point getPos() const;
    double getSide() const;

    // ���������������� ������ �� �������� ������ Shape
    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;

    void moveToPoint(Point pos) override;
    void moveToPoint(double k) override;
    void scale(double k) override;

    Shape* clone() const override; // �������� �� Shape*
    string getName() const override;

    void print(ostream& os) const override { // ���������� ������ print
        os << *this;
    }
};

#endif // SQUARE_H

