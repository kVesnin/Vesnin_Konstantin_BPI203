#include "ConsoleWriter.cpp"
#include <string>
#pragma once
// Base abstract class to make the program beautiful and logical.
class Man {
public:
    /// <summary>
    /// The action which man (derived objects) will do in thread in our program.
    /// Realized in Smoker.cpp and Broker.cpp
    /// </summary>
    virtual void doInThread() = 0;
protected:
    /// <summary>
    /// Method for printing something to console.
    /// Realized in Smoker.cpp and Broker.cpp
    /// </summary>
    /// <param name="msg"></param>
    virtual void report(std::string msg) = 0;
    /// <summary>
    /// Object which will print.
    /// </summary>
    ConsoleWriter* cw;

};