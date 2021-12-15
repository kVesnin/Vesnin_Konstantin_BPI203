#include "Man.cpp"
#include "Smoker.cpp"
#include "SmokerTobacco.cpp"
#include "SmokerPaper.cpp"
#include "SmokerMatches.cpp"
#include <string>
#include "Staff.cpp"
#include "ConsoleWriter.cpp"
#include <iostream>
#include <sstream>

#pragma once
class Broker : public Man {
private:
    SmokerTobacco* clientOne;
    SmokerPaper* clientTwo;
    SmokerMatches* clientThree;

    void createStaffForSmokers(Staff& staffOne, Staff& staffTwo) {
        int numberForFirstStaff = std::rand() % 3;
        int numberForSecondStaff = (std::rand() % 2 + numberForFirstStaff) % 3;
        staffOne = (Staff)numberForFirstStaff;
        staffTwo = (Staff)numberForSecondStaff;
        report("Staff was created!");
    }
    Staff findNeededStaff(Staff staffOne, Staff staffTwo) {
        if (Staff::TOBACCO != staffOne && Staff::TOBACCO != staffTwo) return Staff::TOBACCO;
        if (Staff::PAPER != staffOne && Staff::PAPER != staffTwo) return Staff::PAPER;
        if (Staff::MATCHES != staffOne && Staff::MATCHES != staffTwo) return Staff::MATCHES;
    }
public:
    Broker(ConsoleWriter* cw, SmokerTobacco* clientOne, SmokerPaper* clientTwo, SmokerMatches* clientThree) {
        this->cw = cw;
        this->clientOne = clientOne;
        this->clientTwo = clientTwo;
        this->clientThree = clientThree;
    }
    void doInThread() override {
        Staff staffOne, staffTwo;
        createStaffForSmokers(staffOne, staffTwo);
        Staff neededStaff = findNeededStaff(staffOne, staffTwo);
        if (neededStaff == Staff::TOBACCO) {
            clientOne->getStaff();
        }
        else if (neededStaff == Staff::PAPER) {
            clientTwo->getStaff();
        }
        else if (neededStaff == Staff::MATCHES) {
            clientThree->getStaff();
        }
        report("Staff was successfully sent!");
        // std::this_thread::sleep_for(std::chrono::second(16));
        doInThread();
    }
    void report(std::string msg) override {
        std::stringstream ss;
        ss << "Broker" << std::endl << msg << std::endl << std::endl;
        cw->print(ss.str());
    }
    ~Broker() {}
};