#include "ShapesProperties.h"

std::string getColorName(Color color) {
    switch ((int)color) {
    case 0:
        return "Red";
    case 1:
        return "Orange";
    case 2:
        return "Yellow";
    case 3:
        return "Green";
    case 4:
        return "Sky";
    case 5:
        return "Blue";
    case 6:
        return "Purple";
    default:
        return "Nothing";
    }
}

double getDistance(int xfirst, int yfirst, int xsecond, int ysecond) {
    int x = xsecond - xfirst;
    int y = ysecond - yfirst;
    return sqrt(x * x + y * y);
}

void createRandomPoint(int& x, int& y) {
    x = rand() % 20;
    y = rand() % 20;
}
