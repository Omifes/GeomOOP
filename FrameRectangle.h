#ifndef FRAMERECTANGLE_H
#define FRAMERECTANGLE_H

#include "Point.h"
#include <iostream>

using namespace std;

class FrameRectangle {

	friend ostream& operator<<(ostream& stream, const FrameRectangle element);

private:
	Point pos_;
	int hight_, wight_;
public:
	FrameRectangle() : pos_(0, 0), hight_(0), wight_(0) {}
	FrameRectangle(int x, int y, int h, int w) : pos_(x, y), hight_(h), wight_(w) {}

	void setPos(int x, int y) { pos_.setX(x); pos_.setY(y); }
	void setHight(int h) { hight_ = h; }
	void setWight(int w) { wight_ = w; }

	Point getPos() { return pos_; }
	double getWight() { return wight_; }
	double getHight() { return hight_; }
};

ostream& operator<<(ostream& stream, FrameRectangle element) {
	stream << "Ограничивающий прямоугольник:\n";
	stream << "Центр: (" << pos_.getX() << "," << pos_.getY() << ")\n" 
		   << "Ширина: " << element.getWight() << "\nВысота: " << element.getHight() << '\n';
	return stream;
}

#endif // FRAMERECTANGLE_H