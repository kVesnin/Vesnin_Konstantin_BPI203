#include "Smoker.cpp"
#include <string>
#pragma once
/// <summary>
/// Class of Smoker who makes matches.
/// </summary>
class SmokerMatches : public Smoker {
public:
    SmokerMatches(ConsoleWriter* cw) {
        this->cw = cw;
        semaphoreTobacco = new std::binary_semaphore(1);
        semaphorePaper = new std::binary_semaphore(1);
        semaphoreMatches = new std::binary_semaphore(1);
        tobaccoCount = 0;
        paperCount = 0;
        matchesCount = 0;
    }
    void doMoreStaff() override {
        changeMatches(1);
    }
    void getStaff() override {
        changePaper(1);
        changeTobacco(1);
        report("I get tobacco and paper from Broker!");
        smoke();
    }
    std::string getName() override {
        return "SmokerMatches";
    }
    ~SmokerMatches() {}
};