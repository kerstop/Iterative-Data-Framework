//
// Created by kerstop on 8/16/21.
//

#ifndef ITERATIVE_DATA_FRAMEWORK_CONSOLEHANDLER_HPP
#define ITERATIVE_DATA_FRAMEWORK_CONSOLEHANDLER_HPP

#include "CommunicationChannel.hpp"
#include <queue>
#include <string>
#include <thread>
#include <vector>
#include <mutex>


class ConsoleHandler {
private:

    std::thread t;
    CommunicationChannel* sharedMem;

    bool running;

    void interpretCommand(std::string);
    std::vector<std::string> split(const std::string&);
    void handleMessage(Message);

    void help();

public:
    ConsoleHandler(CommunicationChannel *);
    ~ConsoleHandler();
    static void ThreadEntry(ConsoleHandler* self);
    void shell();


};


#endif //ITERATIVE_DATA_FRAMEWORK_CONSOLEHANDLER_HPP
