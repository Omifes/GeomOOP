#include "CompositeShape.h"
#include <limits>

void CompositeShape::addShape(Shape* shape) {
	if (shapes_.size() < maxSize_) {
		shapes_.push_back(shape);
	}
	else {
		throw overflow_error("Достигнуто максимальное количество фигур.");
	}
}

FrameRectangle CompositeShape::getFrameRectangle() const {
	if (shapes_.empty()) {
		return FrameRectangle(0.0, 0.0, 0.0, 0.0);
	}

	double lowestBottomLeftX = numeric_limits<double>::max();
	double lowestBottomLeftY = numeric_limits<double>::max();
	double greatestTopRightX = numeric_limits<double>::min();
	double greatestTopRightY = numeric_limits<double>::min();

	for (Shape* shape : shapes_) {
		if (shape->getFrameRectangle().getBottomLeft().getX() < lowestBottomLeftX) {
			lowestBottomLeftX = shape->getFrameRectangle().getBottomLeft().getX();
		}
		if (shape->getFrameRectangle().getBottomLeft().getY() < lowestBottomLeftY) {
			lowestBottomLeftY = shape->getFrameRectangle().getBottomLeft().getY();
		}
		if (shape->getFrameRectangle().getTopRight().getX() > greatestTopRightX) {
			greatestTopRightX = shape->getFrameRectangle().getTopRight().getX();
		}
		if (shape->getFrameRectangle().getTopRight().getY() > greatestTopRightY) {
			greatestTopRightY = shape->getFrameRectangle().getTopRight().getY();
		}
	}
	double width = greatestTopRightX - lowestBottomLeftX;
	double height = greatestTopRightY - lowestBottomLeftY;

	Point centre(greatestTopRightX - (width / 2), greatestTopRightY - (height / 2));

	return FrameRectangle(centre.getX(), centre.getY(), height, width);
} 

void CompositeShape::moveToPoint(double x, double y) {
	for (Shape* shape : shapes_) {
		shape->moveToPoint(x, y);
	}
}

void CompositeShape::moveToPoint(Point dot) {
	Point oldPos = getFrameRectangle().getPos();

	double xMovement = dot.getX() - oldPos.getX();
	double yMovement = dot.getY() - oldPos.getY();

	for (Shape* shape : shapes_) {
		shape->moveToPoint(xMovement, yMovement);
	}
}

double CompositeShape::getArea() const {
	return getFrameRectangle().getHeight() * getFrameRectangle().getWidth();
}

string CompositeShape::getName() const{
	return "COMPOSITESHAPE";
}

void CompositeShape::scale(double k) {
	Point oldPos = getFrameRectangle().getPos();

	moveToPoint(Point(0.0, 0.0));

	for (Shape* shape : shapes_) {
		shape->scale(k);
	}

	moveToPoint(oldPos);
}

ostream& operator<<(ostream& stream, const CompositeShape& obj) {
	stream << fixed << setprecision(1) << obj.getName() << " " << obj.getArea() << " " << obj.getFrameRectangle().getBottomLeft().getX() << " "
		<< obj.getFrameRectangle().getBottomLeft().getY() << " " << obj.getFrameRectangle().getTopRight().getX() << " "
		<< obj.getFrameRectangle().getTopRight().getY() << '\n\n';
	stream << "\nСодержащиеся фигуры\n";
	for (Shape* shape : obj.getShapes()) {
		stream << *shape << '\n';
	}
	return stream;
}