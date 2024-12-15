#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {


private:
    double x_, y_;

public:
    Point() : x_(0.0), y_(0.0) {}
    Point(double x, double y) : x_(x), y_(y) {}

    double getX() const { return x_; }
    double getY() const { return y_; }

    void setX(double x) { x_ = x; }
    void setY(double y) { y_ = y; }
};

#endif // POINT_H
