//
// Created by kerstop on 7/12/21.
//

#ifndef ITERATIVE_DATA_FRAMEWORK_ITERATIVEDATADISPLAY_H
#define ITERATIVE_DATA_FRAMEWORK_ITERATIVEDATADISPLAY_H

#include "ConsoleHandler.hpp"
#include "IterativeDataEngine.hpp"
#include <memory>
#include <thread>
#include <queue>
#include <string>
#include <SDL.h>

class IterativeDataDisplay{
private:

    bool running;
    bool paused;

    int width;
    int height;
    IterativeDataEngine* data;
    std::vector<std::vector<pixel>> data_buffer;
    CommunicationChannel sharedMem;
    ConsoleHandler console;

    SDL_Window* window{};
    SDL_Renderer* renderer{};

    static void shell(IterativeDataDisplay *ptr);

    void redrawData();
    void handleEvent(SDL_Event*);
    void handleKeyEvent(SDL_Event*);
    void handleMessage(Message);


    void togglePause();

public:

    IterativeDataDisplay(IterativeDataEngine*);
    ~IterativeDataDisplay();

    int execute();

};

#endif //ITERATIVE_DATA_FRAMEWORK_ITERATIVEDATADISPLAY_H
