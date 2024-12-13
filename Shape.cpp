#include "Shape.h"

std::ostream& operator<<(ostream& os, const Shape& shape) {
    shape.print(os);
    return os;
}