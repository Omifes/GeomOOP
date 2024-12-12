#include "Shape.h"

std::ostream& operator<<(ostream& os, const Shape& shape) {
    shape.print(os); // Вызов виртуальной функции print
    return os;
}