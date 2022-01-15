#include "Point.cpp"
#include "Shape.cpp"
#include <sstream>
//#include <string>

#pragma once

using std::string;
using std::stringstream;

class Rectangle : public Shape {
public:
    Rectangle(Point* first, Point* second, Color color) {
        leftUpper = first;
        rightDown = second;
        this->color = color;
    }
    Point* leftUpper;
    Point* rightDown;
    double getPerimetr() override {
        int first = abs(rightDown->x - leftUpper->x);
        int second = abs(rightDown->y - leftUpper->y);
        return 2 * first + 2 * second;
    }
    std::string toString() override {
        stringstream ss;
        ss << "Rectangle: leftUpper(" << leftUpper->x << ", " << leftUpper->y <<
            ") | rightDown(" << rightDown->x << ", " << rightDown->y << ") | " << getColorName(color)
            << " | perimetr = " << getPerimetr();
        return ss.str();
    }
    static Rectangle* createRandomRectangle() {
        Point* first = Point::createRandomPoint();
        Point* second = Point::createRandomPoint();
        if (second->x < first->x) {
            int temp = first->x;
            first->x = second->x;
            second->x = temp;
        }
        if (second->y < first->y) {
            int temp = first->y;
            first->y = second->y;
            second->y = temp;
        }
        int color = rand() % 7;
        return new Rectangle(first, second, (Color)color);
    }
    ~Rectangle() {
        delete leftUpper;
        delete rightDown;
    }
};