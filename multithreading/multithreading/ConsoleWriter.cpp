#include <semaphore>
#include <iostream>
#pragma once
class ConsoleWriter {
private:
    std::binary_semaphore* a;
public:
    ConsoleWriter() {
        a = new std::binary_semaphore(1);
    }
    void print(std::string msg) {
        a->acquire();
        std::cout << msg << std::endl;
        a->release();
    }
    ~ConsoleWriter() {}
};