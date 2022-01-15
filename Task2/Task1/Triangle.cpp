#include "Point.cpp"
#include "Shape.cpp"
#include <sstream>
//#include <string>

#pragma once

using std::string;
using std::stringstream;

class Triangle : public Shape {
public:
    Triangle(Point* first, Point* second, Point* third, Color color) {
        this->first = first;
        this->second = second;
        this->third = third;
        this->color = color;
    }
    Point* first, * second, * third;
    double getPerimetr() override {
        return Point::getDistance(first, second) +
            Point::getDistance(first, third) +
            Point::getDistance(third, second);
    }
    std::string toString() override {
        stringstream ss;
        ss << "Triangle: first(" << first->x << ", " << first->y <<
            ") | second(" << second->x << ", " << second->y << 
            ") | third(" << third->x << ", " << third->y << ") | " << getColorName(color) << 
            " | perimetr = " << getPerimetr();
        return ss.str();
    }
    static Triangle* createRandomTriangle() {
        Point* first, *second, *third;
        do {
            first = Point::createRandomPoint();
            second = Point::createRandomPoint();
            third = Point::createRandomPoint();
        } while (!isCorrect(first, second, third));
        int color = rand() % 7;
        return new Triangle(first, second, third, (Color)color);
    }

    static bool isCorrect(Point* first, Point* second, Point* third) {
        double sideOne = Point::getDistance(first, second);
        double sideTwo = Point::getDistance(second, third);
        double sideThree = Point::getDistance(first, third);
        return (sideOne + sideTwo > sideThree && sideTwo + sideThree > sideOne && sideOne + sideThree > sideTwo);
    }
    ~Triangle() {
        delete first;
        delete second;
        delete third;
    }
};