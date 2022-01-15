#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

enum ShapeType {
    CIRCLE, RECTANGLE, TRIANGLE
};

struct Shape {
    // значения цветов для каждой из фигур
    ShapeType type; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        Circle c;
        Rectangle r;
        Triangle t;
    };
};

double getPerimetr(Shape shape);