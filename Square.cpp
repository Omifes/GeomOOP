#include "Square.h"
#include <cmath>

Square::Square() : pos_(0.0, 0.0), side_(0.0) {}

Square::Square(double x, double y, double s) : pos_(x, y), side_(s) {}

void Square::setPos(double x, double y) {
    pos_.setX(x);
    pos_.setY(y);
}

void Square::setSide(double v) {
    side_ = v;
}

Point Square::getPos() const {
    return pos_;
}

double Square::getSide() const {
    return side_;
}

double Square::getArea() const {
    return pow(side_, 2);
}

FrameRectangle Square::getFrameRectangle() const {
    return FrameRectangle(pos_.getX(), pos_.getY(), side_, side_);
}

void Square::moveToPoint(Point pos) {
    pos_.setX(pos.getX());
    pos_.setY(pos.getY());
}

void Square::moveToPoint(double k) {
    pos_.setX(pos_.getX() + k);
    pos_.setY(pos_.getY() + k);
}

void Square::scale(double k) {
    side_ *= k;
}

Shape* Square::clone() const {
    return new Square(*this);
}

string Square::getName() const {
    return "SQUARE";
}

istream& operator>>(istream& stream, Square& element) {
    double x, y, s;
    stream >> x >> y >> s;
    element.setPos(x, y);
    element.setSide(s);
    return stream;
}

ostream& operator<<(ostream& stream, const Square& element) {
    stream << element.getName() << " " << fixed << setprecision(1) << element.getArea() << " "
        << element.getFrameRectangle().getBottomLeft().getX() << " "
        << element.getFrameRectangle().getBottomLeft().getY() << " "
        << element.getFrameRectangle().getTopRight().getX() << " "
        << element.getFrameRectangle().getTopRight().getY();
    return stream;
}

