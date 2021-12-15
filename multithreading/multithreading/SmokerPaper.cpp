#include "Smoker.cpp"
#pragma once
/// <summary>
/// Class of Smoker who makes paper.
/// </summary>
class SmokerPaper : public Smoker {
public:
    SmokerPaper(ConsoleWriter* cw) {
        this->cw = cw;
        semaphoreTobacco = new std::binary_semaphore(1);
        semaphorePaper = new std::binary_semaphore(1);
        semaphoreMatches = new std::binary_semaphore(1);
        tobaccoCount = 0;
        paperCount = 0;
        matchesCount = 0;
    }
    void doMoreStaff() override {
        changePaper(1);
    }
    void getStaff() override {
        changeMatches(1);
        changeTobacco(1);
        report("I get tobacco and matches from Broker!");
        smoke();
    }
    std::string getName() override {
        return "SmokerPaper";
    }
    ~SmokerPaper() {}
};