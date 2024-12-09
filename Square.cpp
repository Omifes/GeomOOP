#include "Square.h"

using namespace std;

const double PI = 3.14159265358979323846;

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

Square* Square::clone() const {
	return new Square(*this);
}

string Square::getName() const {
	cout << "Square\n";
}

istream& operator>>(istream& stream, Square& element) {
	double x, y, s;
	stream >> x >> y >> s;
	element.setPos(x, y);
	element.setSide(s);
	return stream;
}

ostream& operator<<(ostream& stream, Square& element) {
	stream << ""
}