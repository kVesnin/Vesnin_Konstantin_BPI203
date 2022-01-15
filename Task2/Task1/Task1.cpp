// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <stdio.h>
#include "Container.cpp"
#include <iostream>
#include <chrono>



int main(int argc, char* argv[])
{
    auto start = std::chrono::steady_clock::now();
    FILE* fp;
    Container* container;
    if (argc != 4) {
        printf("Wrong commands when starting the program.");
        return 1;
    }
    if(!strcmp(argv[1], "-fromFile")){
        fopen_s(&fp, argv[2], "r");
        container = new Container();
        if (!container->pushFromFile(fp)) return 1;
        //printf("Container was filled!");
    }
    else if(!strcmp(argv[1], "-autoGen")){
        container = Container::createRandomContainer(atoi(argv[2]));
        //printf("Random conteiner was created \n");
    }
    else {
        printf("Wrong command about openning file.");
        return 1;
    }
    std::ofstream ofst(argv[3]);
    container->writeResultToFile(ofst);
    //printf("Conteiner was writen to file \n");
    container->sort();
    //printf("Conteiner was sorted \n");
    ofst << "Container was sorted by Perimetr." << std::endl << std::endl;
    container->writeResultToFile(ofst);
    //printf("Sorted conteiner was writen to file \n");
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout<< std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
