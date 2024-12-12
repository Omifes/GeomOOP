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
    // ������������
    Ellipse(); // ����������� �� ���������
    Ellipse(double x, double y, double v, double h); // ����������� � �����������

    // �������
    void setPos(double x, double y);
    void setRadVert(double v);
    void setRadHor(double h);

    // �������
    Point getPos() const;
    double getRadVert() const;
    double getRadHor() const;

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

#endif // ELLIPSE_H
