#include "BinarySort.h"


int binarySearch(Shape* figures, Shape itemSearchFor, int left, int right) {

    int mid = (left + right) / 2;
    if (mid == left) {
        if (getPerimetr(itemSearchFor) < getPerimetr(figures[left])) {
            return left;
        }
        else {
            return left + 1;
        }
    }
    if (getPerimetr(itemSearchFor) < getPerimetr(figures[mid])) {
        return binarySearch(figures, itemSearchFor, left, mid);
    }
    else if (getPerimetr(itemSearchFor) == getPerimetr(figures[mid])) {
        return mid + 1;
    }
    else {
        return binarySearch(figures, itemSearchFor, mid, right);
    }
}

void binarySortArr(Shape* figures, int length) {
    if (length <= 1 || length > 10000) return;
    for (int i = 1; i < length; i++) {
        int ind = binarySearch(figures, figures[i], 0, i);
        Shape selected = figures[i];
        for (int j = i; j > ind; j--) {
            figures[j] = figures[j - 1];
        }
        figures[ind] = selected;
    }
}