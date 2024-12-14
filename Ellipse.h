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
    Ellipse() : pos_(0.0, 0.0), radiusVert_(0.0), radiusHor_(0.0) {}
    Ellipse(double x, double y, double v, double h) : pos_(x, y), radiusVert_(v), radiusHor_(h) {}

    void setPos(double x, double y) { pos_.setX(x); pos_.setY(y); }
    void setRadVert(double v) { radiusVert_ = v; }
    void setRadHor(double h) { radiusHor_ = h; }

    Point getPos() const { return pos_;  }
    double getRadVert() const { return radiusVert_; }
    double getRadHor() const { return radiusHor_; }

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

#endif // ELLIPSE_H
