#ifndef SHAPE_H
#define SHAPE_H


#include "FrameRectangle.h"
#include "Ellipse.h"
#include <iostream>
#include <memory>

class Shape {
public:
	virtual double getArea() const = 0;
	virtual FrameRectangle getFrameRectangle() const = 0;
	virtual void moveToPoint(Point pos) = 0;
	virtual void moveToPoint(double k) = 0;
	virtual void scale(double k) = 0;
	virtual Shape* clone() const = 0;
	virtual string getName() const = 0;
};

#endif // SHAPE_H