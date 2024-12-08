#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x_, y_;

public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) {}

    int getX() const { return x_; }
    int getY() const { return y_; }

    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }
};

#endif // POINT_H
