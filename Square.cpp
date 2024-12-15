#include "Square.h"
#include <cmath>

double Square::getArea() const {
    return pow(side_, 2);
}

FrameRectangle Square::getFrameRectangle() const {
    return FrameRectangle(pos_.getX() + (side_ / 2), pos_.getY() + (side_ / 2), side_, side_);
}

void Square::moveToPoint(Point pos) {
    pos_.setX(pos.getX() - (side_ / 2));
    pos_.setY(pos.getY() - (side_ / 2));
}

void Square::moveToPoint(double x, double y) {
    pos_.setX(pos_.getX() + x);
    pos_.setY(pos_.getY() + y);
}

void Square::scale(double k) {
    if (k <= 0) {
        throw invalid_argument("Коэффициент должен быть больше 0");
    }
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

