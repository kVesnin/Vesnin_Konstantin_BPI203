#include "Triangle.h"



void initTriangle(FILE* fp, Triangle& tr) {
    int color;
    fscanf_s(fp, "%d", &tr.xfirst);
    fscanf_s(fp, "%d", &tr.yfirst);
    fscanf_s(fp, "%d", &tr.xsecond);
    fscanf_s(fp, "%d", &tr.ysecond);
    fscanf_s(fp, "%d", &tr.xthird);
    fscanf_s(fp, "%d", &tr.ythird);
    fscanf_s(fp, "%d", &color);
    tr.color = (Color)color;
}

double getTrianglePerimetr(Triangle triangle) {
    double firstSide = getDistance(triangle.xfirst, triangle.yfirst, triangle.xsecond, triangle.ysecond);
    double secondSide = getDistance(triangle.xfirst, triangle.yfirst, triangle.xthird, triangle.ythird);
    double thirdSide = getDistance(triangle.xthird, triangle.ythird, triangle.xsecond, triangle.ysecond);
    return firstSide + secondSide + thirdSide;
}

void printTriangle(Triangle triangle, std::ofstream& ofst) {
    ofst << "Triangle: first(" << triangle.xfirst << ", " << triangle.yfirst <<
        ") | second(" << triangle.xsecond << ", " << triangle.ysecond <<
        ") | third(" << triangle.xthird << ", " << triangle.ythird << ") | " << getColorName(triangle.color) <<
        " | perimetr = " << getTrianglePerimetr(triangle) << std::endl;
}

Triangle createRandomTriangle() {
    Triangle triangle;
    double sideOne, sideTwo, sideThree;
    //do {
    createRandomPoint(triangle.xfirst, triangle.yfirst);
    createRandomPoint(triangle.xsecond, triangle.ysecond);
    createRandomPoint(triangle.xthird, triangle.ythird);
    sideOne = getDistance(triangle.xfirst, triangle.yfirst, triangle.xsecond, triangle.ysecond);
    sideTwo = getDistance(triangle.xfirst, triangle.yfirst, triangle.xthird, triangle.ythird);
    sideThree = getDistance(triangle.xthird, triangle.ythird, triangle.xsecond, triangle.ysecond);
    //} while (!(sideOne + sideTwo > sideThree && sideTwo + sideThree > sideOne && sideOne + sideThree > sideTwo));
    triangle.color = (Color)(rand() % 7);
    return triangle;
}