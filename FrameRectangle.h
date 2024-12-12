#ifndef FRAMERECTANGLE_H
#define FRAMERECTANGLE_H

#include "Point.h"

class FrameRectangle {
private:
    Point pos_;
    double height_, width_;

public:
    FrameRectangle() : pos_(0, 0), height_(0), width_(0) {}
    FrameRectangle(double x, double y, double h, double w) : pos_(x, y), height_(h), width_(w) {}

    void setPos(double x, double y) { pos_.setX(x); pos_.setY(y); }
    void setHeight(double h) { height_ = h; }
    void setWidth(double w) { width_ = w; }

    Point getPos() const { return pos_; }
    double getWidth() const { return width_; }
    double getHeight() const { return height_; }

    Point getBottomLeft() const {
        return Point(pos_.getX() - width_ / 2, pos_.getY() - height_ / 2);
    }
    Point getTopRight() const {
        return Point(pos_.getX() + width_ / 2, pos_.getY() + height_ / 2);
    }
};

#endif // FRAMERECTANGLE_H
