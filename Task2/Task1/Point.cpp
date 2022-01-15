#include <math.h>
#include <stdlib.h>

#pragma once

class Point {
public:
    Point(int x, int y) {
        this->x = x; 
        this->y = y;
    }
    int x;
    int y;
    static double getDistance(Point* first, Point* second) {
        int x = second->x - first->x;
        int y = second->y - first->y;
        return sqrt(x * x + y * y);
    }
    static Point* createRandomPoint() {
        int x = rand() % 20;
        int y = rand() % 20;
        return new Point(x, y);
    }
    ~Point() {}
};