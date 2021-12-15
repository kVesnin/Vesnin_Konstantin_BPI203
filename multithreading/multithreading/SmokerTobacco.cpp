#include "Smoker.cpp"
#pragma once
/// <summary>
/// Class of Smoker who makes tobacco.
/// </summary>
class SmokerTobacco : public Smoker {
public:
    SmokerTobacco(ConsoleWriter* cw) {
        this->cw = cw;
        semaphoreTobacco = new std::binary_semaphore(1);
        semaphorePaper = new std::binary_semaphore(1);
        semaphoreMatches = new std::binary_semaphore(1);
        tobaccoCount = 0;
        paperCount = 0;
        matchesCount = 0;
    }
    void doMoreStaff() override {
        changeTobacco(1);
    }
    void getStaff() override {
        changePaper(1);
        changeMatches(1);
        report("I get paper and matches from Broker!");
        smoke();
    }
    std::string getName() override {
        return "SmokerTobacco";
    }
    ~SmokerTobacco() {
    }
};