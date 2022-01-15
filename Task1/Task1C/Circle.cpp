#include "Circle.h"

void initCircle(FILE* fp, Circle& circle) {
    int color;
    fscanf_s(fp, "%d", &circle.x);
    fscanf_s(fp, "%d", &circle.y);
    fscanf_s(fp, "%d", &circle.r);
    fscanf_s(fp, "%d", &color);
    circle.color = (Color)color;
}

double getCirclePerimetr(Circle circle) {
    return 2 * 3.1415926535 * circle.r;
}

void printCircle(Circle circle, std::ofstream& ofst) {
    ofst << "Circle: center(" << circle.x << ", " << circle.y <<
        ") | radius = " << circle.r << " | " << getColorName(circle.color) <<
        " | perimetr = " << getCirclePerimetr(circle) << std::endl;
}

Circle createRandomCircle() {
    Circle circle;
    createRandomPoint(circle.x, circle.y);
    circle.r = rand() % 20 + 1;
    circle.color = (Color)(rand() % 7);
    return circle;
}
