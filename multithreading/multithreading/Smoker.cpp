#include "Man.cpp"
#include <string>
#include "Staff.cpp"
#include <semaphore>
#include <thread>
#include "ConsoleWriter.cpp"
#include <sstream>
#include <iostream>


#pragma once
/// <summary>
/// Abstract class but it has many functions which are the same for SmokerTobacco, SmokerMatches and SmokerPaper.
/// </summary>
class Smoker : public Man {
protected:
    /// <summary>
    /// Number of resources
    /// </summary>
    int tobaccoCount, paperCount, matchesCount;
    /// <summary>
    /// Semaphores to make each resource safe (Not allowing the different thread to change them at the same time.)
    /// </summary>
    std::binary_semaphore* semaphoreTobacco;
    std::binary_semaphore* semaphorePaper;
    std::binary_semaphore* semaphoreMatches;
    /// <summary>
    /// SmokerTobacco does tobacco, SmokerMatches does matches, SmokerPaper does paper.
    /// </summary>
    virtual void doMoreStaff() = 0;
    /// <summary>
    /// Smoke takes for 1 of each resources.
    /// </summary>
    void smoke() {
        if (tobaccoCount > 0 && paperCount > 0 && matchesCount > 0) {
            changeTobacco(-1);
            changePaper(-1);
            changeMatches(-1);
            report("I smoked and that was awesome!");
        }
        else
            report("I didn't smoke because I have not enough resources:(");
    }
public:
    /// <summary>
    /// Methods to make each resource safe
    /// </summary>
    /// <param name="dif"></param>
    void changeTobacco(int dif) {
        semaphoreTobacco->acquire();
        tobaccoCount += dif;
        semaphoreTobacco->release();
    }
    void changePaper(int dif) {
        semaphorePaper->acquire();
        paperCount += dif;
        semaphorePaper->release();
    }
    void changeMatches(int dif) {
        semaphoreMatches->acquire();
        matchesCount += dif;
        semaphoreMatches->release();
    }
    /// <summary>
    /// SmokerTobacco's name is SmokerTobacco etc.
    /// </summary>
    /// <returns></returns>
    virtual std::string getName() = 0;
    void doInThread() override {
        doMoreStaff();
        report("I've done some more resources");
        if (tobaccoCount > 0 && paperCount > 0 && matchesCount > 0)
            smoke();
        // std::this_thread::sleep_for(std::chrono::seconds(16));
        doInThread();
    }
    /// <summary>
    /// Shows all resources of the object.
    /// </summary>
    /// <returns></returns>
    std::string toString() {
        std::stringstream res;
        res << "Tobacco: " << std::to_string(tobaccoCount) << " Paper: " << std::to_string(paperCount);
        res << " Matches: " << std::to_string(matchesCount) << std::endl;
        return res.str();
    }
    void report(std::string msg) override {
        std::stringstream ss;
        ss << this->getName() << std::endl << msg << std::endl << this->toString() << std::endl;
        this->cw->print(ss.str());
    }
    /// <summary>
    /// Method which allows to get staff which broker gives. We don't need to know which stuff is it.
    /// If method is called by SmokerTobaco than staff is paper and matches (not tobacco) etc.
    /// </summary>
    virtual void getStaff() = 0; 
};