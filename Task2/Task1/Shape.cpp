#include "Color.cpp"
#include <string>

#pragma once

class Shape {
public:
    Color color;
    virtual double getPerimetr() { return 1.0; }
    virtual std::string toString() { return new char[1]; }
    static void binarySortArr(Shape* *figures, int length) {
        if (length <= 1 || length > 10000) return;
        for (int i = 1; i < length; i++) {
            int ind = binarySearch(figures, figures[i], 0, i);
            Shape* selected = figures[i];
            for (int j = i; j > ind; j--) {
                figures[j] = figures[j - 1];
            }
            figures[ind] = selected;
        }
    }
private:
    static int binarySearch(Shape* *figures, Shape* itemSearchFor, int left, int right) {

        int mid = (left + right) / 2;
        if (mid == left) {
            if (itemSearchFor->getPerimetr() < figures[left]->getPerimetr()) {
                return left;
            }
            else {
                return left + 1;
            }
        }
        if (itemSearchFor->getPerimetr() < figures[mid]->getPerimetr()) {
            return binarySearch(figures, itemSearchFor, left, mid);
        }
        else if (itemSearchFor->getPerimetr() == figures[mid]->getPerimetr()) {
            return mid + 1;
        }
        else {
            return binarySearch(figures, itemSearchFor, mid, right);
        }
    }
protected:
    Shape() {}
    static std::string getColorName(Color color) {
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
};
