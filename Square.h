#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "FrameRectangle.h" 
#include "Shape.h"
#include <string>
#include <iostream>

using namespace std;

class Square : public Shape {

	friend istream& operator>>(istream& stream, Square& element);
	friend ostream& operator<<(ostream& stream, Square& element);

private:
	Point pos_;
	double side_;
public:
	Square() : pos_(0, 0), side_(0) {}
	Square(double x, double y, double s) : pos_(x, y), side_(s) {}

	void setPos(double x, double y) { pos_.setX(x); pos_.setY(y); }
	void setSide(double v) { side_ = v; }

	Point getPos() { return pos_; }
	double getSide() { return side_; }

	double getArea() const override;
	FrameRectangle getFrameRectangle() const override;
	void moveToPoint(Point pos) override;
	void moveToPoint(double k) override;
	void scale(double k) override;
	Square* clone() const override;
	string getName() const override;

	
};

#endif // SQUARE_H