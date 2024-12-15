#ifndef SHAPE_H
#define SHAPE_H

#include "FrameRectangle.h"
#include <string>
#include <iostream>

using namespace std;

class Shape {
public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual FrameRectangle getFrameRectangle() const = 0;

    virtual void moveToPoint(Point pos) = 0;
    virtual void moveToPoint(double x, double y) = 0;
    virtual void scale(double k) = 0;

    virtual Shape* clone() const = 0;
    virtual string getName() const = 0;

    virtual void print(ostream& stream) const = 0;
};

ostream& operator<<(ostream& stream, const Shape& shape);

#endif // SHAPE_H