#ifndef FRAMERECTANGLE_H
#define FRAMERECTANGLE_H

#include "Point.h"

class FrameRectangle {
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

#endif // FRAMERECTANGLE_H