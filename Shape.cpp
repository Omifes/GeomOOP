#include "Shape.h"

ostream& operator<<(ostream& stream, const Shape& shape) {
    shape.print(stream);
    return stream;
}
