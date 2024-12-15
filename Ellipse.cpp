#include "Ellipse.h"

const double PI = 3.14159265358979323846;

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

void Ellipse::moveToPoint(double x, double y) {
    pos_.setX(pos_.getX() + x);
    pos_.setY(pos_.getY() + y);
}

void Ellipse::scale(double k) {
    if (k <= 0) {
        throw invalid_argument("Коэффициент должен быть больше 0");
    }
    radiusVert_ *= k;
    radiusHor_ *= k;
}

Shape* Ellipse::clone() const {
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
