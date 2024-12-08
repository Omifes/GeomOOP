#include "Ellipse.h"

using namespace std;

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

void Ellipse::moveToPoint(double k) {
	pos_.setX(pos_.getX() + k);
	pos_.setY(pos_.getY() + k);
}

void Ellipse::scale(double k) {
	radiusVert_ *= k;
	radiusHor_ *= k;
}

Ellipse* Ellipse::clone() const {
	return new Ellipse(*this);
}

string Ellipse::getName() const {
	cout << "Ellipse\n";
}