#include "Rectangle.h"


void initRectangle(FILE* fp, Rectangle& rect) {
    int color;
    fscanf_s(fp, "%d", &rect.xleft);
    fscanf_s(fp, "%d", &rect.yleft);
    fscanf_s(fp, "%d", &rect.xright);
    fscanf_s(fp, "%d", &rect.yright);
    fscanf_s(fp, "%d", &color);
    rect.color = (Color)color;
}

double getRectanglePerimetr(Rectangle rectangle) {
    int first = abs(rectangle.xright - rectangle.xleft);
    int second = abs(rectangle.yright - rectangle.yleft);
    return 2 * first + 2 * second;
}

void printRectangle(Rectangle rectangle, std::ofstream& ofst) {
    ofst << "Rectangle: leftUpper(" << rectangle.xleft << ", " << rectangle.yleft <<
        ") | rightDown(" << rectangle.xright << ", " << rectangle.yright << ") | " << getColorName(rectangle.color)
        << " | perimetr = " << getRectanglePerimetr(rectangle) << std::endl;
}

Rectangle createRandomRectangle() {
    Rectangle rectangle;
    createRandomPoint(rectangle.xleft, rectangle.yleft);
    createRandomPoint(rectangle.xright, rectangle.yright);
    if (rectangle.xright < rectangle.xleft) {
        int temp = rectangle.xleft;
        rectangle.xleft = rectangle.xright;
        rectangle.xright = temp;
    }
    if (rectangle.yright < rectangle.yleft) {
        int temp = rectangle.yleft;
        rectangle.yleft = rectangle.yright;
        rectangle.yright = temp;
    }
    rectangle.color = (Color)(rand() % 7);
    return rectangle;
}