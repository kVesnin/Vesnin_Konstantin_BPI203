#include "Shape.h"

double getPerimetr(Shape shape) {
    switch (shape.type) {
    case CIRCLE:
        return getCirclePerimetr(shape.c);
    case RECTANGLE:
        return getRectanglePerimetr(shape.r);
    case TRIANGLE:
        return getTrianglePerimetr(shape.t);
    default:
        return -1;
    }
}