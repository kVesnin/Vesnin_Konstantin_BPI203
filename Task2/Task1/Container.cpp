#include "stdio.h"
#include "Point.cpp"
//#include "Shape.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Triangle.cpp"
#include <fstream>
#include <iostream>

#pragma once

class Container {
private:
    const int max_len = 10000;
    int len;
    Shape** cont;
    void initCircle(FILE* fp) {
        int xCenter, yCenter;
        int radius;
        int color;
        fscanf_s(fp, "%d", &xCenter);
        fscanf_s(fp, "%d", &yCenter);
        fscanf_s(fp, "%d", &radius);
        fscanf_s(fp, "%d", &color);
        Point* center = new Point(xCenter, yCenter);
        cont[len++] = new Circle(center, radius, (Color)color);
    }
    void initRectangle(FILE* fp) {
        int xleftUp, yleftUp;
        int xrightDown, yrightDown;
        int color;
        fscanf_s(fp, "%d", &xleftUp);
        fscanf_s(fp, "%d", &yleftUp);
        fscanf_s(fp, "%d", &xrightDown);
        fscanf_s(fp, "%d", &yrightDown);
        fscanf_s(fp, "%d", &color);
        Point* leftUp = new Point(xleftUp, yleftUp);
        Point* rightDown = new Point(xrightDown, yrightDown);
        cont[len++] = new Rectangle(leftUp, rightDown, (Color)color);
    }
    void initTriangle(FILE* fp) {
        int xfirst, yfirst;
        int xsecond, ysecond;
        int xthird, ythird;
        int color;
        fscanf_s(fp, "%d", &xfirst);
        fscanf_s(fp, "%d", &yfirst);
        fscanf_s(fp, "%d", &xsecond);
        fscanf_s(fp, "%d", &ysecond);
        fscanf_s(fp, "%d", &xthird);
        fscanf_s(fp, "%d", &ythird);
        fscanf_s(fp, "%d", &color);
        Point* first = new Point(xfirst, yfirst);
        Point* second = new Point(xsecond, ysecond);
        Point* third = new Point(xthird, ythird);
        cont[len++] = new Triangle(first, second, third, (Color)color);
    }
public:
    Container() {
        cont = new Shape*[max_len];
        len = 0;
    }
    bool pushFromFile(FILE* fp) {
        int count = 0;
        int typeOfFigure;
        while (!feof(fp)) {
            if (count > 10000) {
                printf("There are more than 10000 elements so the program ends!");
                return false;
            }
            fscanf_s(fp, "%d", &typeOfFigure);
            switch (typeOfFigure) {
            case 0:
                initCircle(fp);
                break;
            case 1:
                initRectangle(fp);
                break;
            case 2:
                initTriangle(fp);
                break;
            default:
                printf("File is incorrect so the program ends!");
                return false;
            }
            count++;
        }
        return true;
    }
    void writeResultToFile(std::ofstream &ofst) {
        //fwprintf(ofst, L"Container contains %d elements.\n", len);
        ofst << "Container contains " << std::to_string(len) << " elements." << std::endl;
        for (int i = 0; i < len; i++) {
            //fwprintf(ofst, L"%s\n", cont[i]->toString());
            ofst << cont[i]->toString() << std::endl;
        }
        ofst << std::endl;
    }
    void sort() { Shape::binarySortArr(cont, len); }

    static Container* createRandomContainer(int len) {
        Container* container = new Container();
        for (int i = 0; i < len; i++) {
           int type = rand() % 3;
           switch (type) {
           case 0:
               container->cont[i] = Circle::createRandomCircle();
               break;
           case 1:
               container->cont[i] = Rectangle::createRandomRectangle();
               break;
           case 2:
               container->cont[i] = Triangle::createRandomTriangle();
               break;
           }
        }
        container->len = len;
        return container;
    }
    ~Container() {
        for (int i = 0; i < len; i++) {
            delete cont[i];
        }
        delete[] cont;
    }
};