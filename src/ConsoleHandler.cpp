//
// Created by kerstop on 8/16/21.
//

#include "ConsoleHandler.hpp"
#include <iostream>
#include <string>
#include <sstream>

ConsoleHandler::ConsoleHandler(CommunicationChannel * mem) {
    t = std::thread(ThreadEntry, this);
    running = true;
    sharedMem = mem;
    sharedMem->registerChannel("Console");
};

ConsoleHandler::~ConsoleHandler() {
    t.join();
};

void ConsoleHandler::ThreadEntry(ConsoleHandler* self) {
    self->shell();
};

void ConsoleHandler::shell() {
    while(running){
        std::cout << ">>> ";
        std::string input;
        std::getline(std::cin, input);
        interpretCommand(input);
        while(sharedMem->hasMessage("Console")){
            handleMessage(sharedMem->getMessage("Console"));
        }

    }
}

void ConsoleHandler::interpretCommand(std::string text) {

    //make sure the text is not empty and split it
    std::vector<std::string> argList = split(text);
    if(argList.empty()){return;}

    //print help text
    if(std::string("h") == argList[0]){
        help();
    }

    //exit the program
    if(std::string("exit") == argList[0]){
        sharedMem->sendMessage("Display", Message{Message::EXIT});
        running = false;
    }

    //pause the running app
    if("p" == argList[0] || "pause" == argList[0]){
        sharedMem->sendMessage("Display", Message{Message::PAUSE});
    }

}

std::vector<std::string> ConsoleHandler::split(const std::string &s) {
    std::vector<std::string> result;
    std::istringstream commandText(s);
    std::string item;
    while(std::getline(commandText, item, ' ')){
        result.emplace_back(item);
    }

    return result;
}

void ConsoleHandler::handleMessage(Message m) {
    if(m.type == Message::EXIT){
        running = false;
    }
}

void ConsoleHandler::help() {
    std::cout << "Placeholder help text" << std::endl;
};


