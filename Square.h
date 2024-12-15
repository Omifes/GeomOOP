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
    Point getCentre() const { return Point(pos_.getX() + side_ / 2, pos_.getX() + side_ / 2); }

    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;

    void moveToPoint(Point pos) override;
    void moveToPoint(double x, double y) override;
    void scale(double k) override;

    Shape* clone() const override;
    string getName() const override;

    void print(ostream& stream) const override {
        stream << *this;
    }
};

#endif // SQUARE_H

