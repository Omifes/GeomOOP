#include "Ellipse.h"
#include <cmath>

const double PI = 3.14159265358979323846;

Ellipse::Ellipse() : pos_(0.0, 0.0), radiusVert_(0.0), radiusHor_(0.0) {}

Ellipse::Ellipse(double x, double y, double v, double h) : pos_(x, y), radiusVert_(v), radiusHor_(h) {}

void Ellipse::setPos(double x, double y) {
    pos_.setX(x);
    pos_.setY(y);
}

void Ellipse::setRadVert(double v) {
    radiusVert_ = v;
}

void Ellipse::setRadHor(double h) {
    radiusHor_ = h;
}

Point Ellipse::getPos() const {
    return pos_;
}

double Ellipse::getRadVert() const {
    return radiusVert_;
}

double Ellipse::getRadHor() const {
    return radiusHor_;
}

double Ellipse::getArea() const {
    return PI * radiusVert_ * radiusHor_;
}

FrameRectangle Ellipse::getFrameRectangle() const {
    return FrameRectangle(pos_.getX(), pos_.getY(), radiusVert_ * 2, radiusHor_ * 2);
}

void Ellipse::moveToPoint(Point pos) {
    pos_.setX(pos.getX());
    pos_.setY(pos.getY());
}

void Ellipse::moveToPoint(double k) {
    pos_.setX(pos_.getX() + k);
    pos_.setY(pos_.getY() + k);
}

void Ellipse::scale(double k) {
    radiusVert_ *= k;
    radiusHor_ *= k;
}

Shape* Ellipse::clone() const { // Изменено на Shape*
    return new Ellipse(*this);
}

string Ellipse::getName() const {
    return "ELLIPSE";
}

istream& operator>>(istream& stream, Ellipse& element) {
    double x, y, v, h;
    stream >> x >> y >> v >> h;
    element.setPos(x, y);
    element.setRadVert(v);
    element.setRadHor(h);
    return stream;
}

ostream& operator<<(ostream& stream, const Ellipse& element) {
    stream << element.getName() << " " << fixed << setprecision(1) << element.getArea() << " "
        << element.getFrameRectangle().getBottomLeft().getX() << " "
        << element.getFrameRectangle().getBottomLeft().getY() << " "
        << element.getFrameRectangle().getTopRight().getX() << " "
        << element.getFrameRectangle().getTopRight().getY();
    return stream;
}
