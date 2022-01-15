// Task1C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include "Container.h"
#include "BinarySort.h"
#include <chrono>
#include <iostream>

int main(int argc, char* argv[])
{
    auto start = std::chrono::steady_clock::now();
    Container c;
    FILE* fp;
    if (argc != 4) {
        printf("Wrong commands when starting the program.");
        return 1;
    }
    if (!strcmp(argv[1], "-fromFile")) {
        fopen_s(&fp, argv[2], "r");
        if (!pushShapesToContainer(c, fp)) return 1;
        //printf("Container was filled!");
    }
    else if (!strcmp(argv[1], "-autoGen")) {
        srand(time(NULL));
        createRandomContainer(c, atoi(argv[2]));
        //printf("Random conteiner was created \n");
    }
    else {
        printf("Wrong command about openning file.");
        return 1;
    }
    std::ofstream ofst(argv[3]);
    printContainer(c, ofst);
    binarySortArr(c.shapeArr, c.len);
    ofst << "Container was sorted" << std::endl << std::endl;
    printContainer(c, ofst);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
    return 0;
}
