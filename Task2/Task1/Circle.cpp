#include "Point.cpp"
#include "Shape.cpp"
#include <corecrt_math_defines.h>
#include <sstream>
//#include <string>

#pragma once

using std::string;
using std::stringstream;

class Circle : public Shape {
public:
    Circle(Point* cent, int radius, Color color) {
        this->center = cent;
        this->radius = radius;
        this->color = color;
    }
    Point* center;
    int radius;
    double getPerimetr() override {
        return 2 * M_PI * radius; 
    }
    std::string toString() override {
        stringstream ss;
        ss << "Circle: center(" << center->x << ", " << center->y <<
            ") | radius = " << radius << " | " << getColorName(color) << 
            " | perimetr = " << getPerimetr();
        return ss.str();
    }
    static Circle* createRandomCircle() {
        Point* center = Point::createRandomPoint();
        int radius = rand() % 20 + 1;
        int color = rand() % 7;
        return new Circle(center, radius, (Color)color);
    }
    ~Circle() {
        delete center;
    }
};