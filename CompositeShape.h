#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H

#include "Ellipse.h"
#include "Square.h"
#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class CompositeShape {
	friend ostream& operator<<(ostream& stream, const CompositeShape& obj);

private:
	vector<Shape*> shapes_;
	size_t maxSize_;
public:
	CompositeShape(size_t m) : maxSize_(m) {}

	~CompositeShape() {
		for (Shape* shape : shapes_) {
			delete shape;
		}
	}
	vector<Shape*> getShapes() const { return shapes_; }

	void addShape(Shape* shape);
	void moveToPoint(Point dot);
	void moveToPoint(double x, double y);

	void scale(double k);

	FrameRectangle getFrameRectangle() const;
	Shape* clone() const;
	string getName() const;

	double getArea() const;
	void print(ostream& stream) const  {
		stream << *this;
	}
};

#endif // COMPOSITESHAPE_H
