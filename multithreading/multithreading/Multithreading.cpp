// multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <thread>
#include "ConsoleWriter.cpp"
#include "SmokerTobacco.cpp"
#include "SmokerPaper.cpp"
#include "SmokerMatches.cpp"
#include "Broker.cpp"
#include "Man.cpp"
#include <iostream>
int main()
{
    ConsoleWriter* cw = new ConsoleWriter();
    SmokerTobacco* smokerTobacco = new SmokerTobacco(cw);
    SmokerPaper* smokerPaper = new SmokerPaper(cw);
    SmokerMatches* smokerMatches = new SmokerMatches(cw);
    Broker* broker = new Broker(cw, smokerTobacco, smokerPaper, smokerMatches);

    std::cout << "Press any key and Enter to start the program." << std::endl;
    std::cout << "And then press any key and Enter to finish the program.\n" << std::endl;
    char startAndQuit;
    std::cin >> startAndQuit;

    std::thread smokerTobaccoThread([smokerTobacco]() {smokerTobacco->doInThread(); });
    //std::this_thread::sleep_for(std::chrono::seconds(4));
    std::thread smokerPaperThread([smokerPaper]() {smokerPaper->doInThread(); });
    //std::this_thread::sleep_for(std::chrono::seconds(4));
    std::thread smokerMatchesThread([smokerMatches]() {smokerMatches->doInThread(); });
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread brokerThread([broker]() {broker->doInThread(); });

    /// <summary>
    /// All threads stop when main finishes. It happens when the user enter any key.
    /// </summary>
    /// <returns></returns>
    smokerTobaccoThread.detach();
    smokerPaperThread.detach();
    smokerMatchesThread.detach();
    brokerThread.detach();

    std::cin >> startAndQuit;
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
