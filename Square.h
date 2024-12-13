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
    Square() : pos_(0.0, 0.0), side_(0.0) {}
    Square(double x, double y, double s) : pos_(x, y), side_(s) {}

    void setPos(double x, double y) { pos_.setX(x); pos_.setY(y); }
    void setSide(double v) { side_ = v; }

    Point getPos() const { return pos_; }
    double getSide() const { return side_; }

    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;

    void moveToPoint(Point pos) override;
    void moveToPoint(double k) override;
    void scale(double k) override;

    Shape* clone() const override;
    string getName() const override;

    void print(ostream& os) const override {
        os << *this;
    }
};

#endif // SQUARE_H

