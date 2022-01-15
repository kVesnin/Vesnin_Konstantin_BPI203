#include "Container.h"


bool pushShapesToContainer(Container& cont, FILE* fp) {
    int typeOfFigure;
    int count = 0;
    while (!feof(fp)) {
        if (count > 10000) {
            printf("There are too many elements so the program ends.");
            return false;
        }
        fscanf_s(fp, "%d", &typeOfFigure);
        Shape newShape;
        switch (typeOfFigure) {
        case 0:
            newShape.type = CIRCLE;
            initCircle(fp, newShape.c);
            break;
        case 1:
            newShape.type = RECTANGLE;
            initRectangle(fp, newShape.r);
            break;
        case 2:
            newShape.type = TRIANGLE;
            initTriangle(fp, newShape.t);
            break;
        default:
            printf("File is incorrect so the program ends!");
            return false;
        }
        cont.shapeArr[cont.len++] = newShape;
        count++;
    }
    return true;
}


void printContainer(Container cont, std::ofstream& ofst) {
    ofst << "Container contains " << cont.len << std::endl;
    for (int i = 0; i < cont.len; i++) {
        switch (cont.shapeArr[i].type) {
        case CIRCLE:
            printCircle(cont.shapeArr[i].c, ofst);
            break;
        case RECTANGLE:
            printRectangle(cont.shapeArr[i].r, ofst);
            break;
        case TRIANGLE:
            printTriangle(cont.shapeArr[i].t, ofst);
            break;
        }
    }
    ofst << std::endl;
}

void createRandomContainer(Container& container, int len) {
    for (int i = 0; i < len; i++) {
        int type = rand() % 3;
        switch (type) {
        case 0:
            container.shapeArr[i].type = CIRCLE;
            container.shapeArr[i].c = createRandomCircle();
            break;
        case 1:
            container.shapeArr[i].type = RECTANGLE;
            container.shapeArr[i].r = createRandomRectangle();
            break;
        case 2:
            container.shapeArr[i].type = TRIANGLE;
            container.shapeArr[i].t = createRandomTriangle();
            break;
        }
    }
    container.len = len;
}