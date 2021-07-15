//
// Created by kerstop on 7/12/21.
//

#include "IterativeDataEngine.h"
#include <memory>
#include <SDL2/SDL.h>

#ifndef ITERATIVE_DATA_FRAMEWORK_ITERATIVEDATADISPLAY_H
#define ITERATIVE_DATA_FRAMEWORK_ITERATIVEDATADISPLAY_H

class IterativeDataDisplay{
private:

    bool running;
    bool paused;

    IterativeDataEngine* data;
    int width;
    int height;

    SDL_Window* window{};
    SDL_Renderer* renderer{};

    void redrawData();
    void handleEvent(SDL_Event*);
    void handleKeyEvent(SDL_Event*);

public:

    IterativeDataDisplay(IterativeDataEngine*);
    ~IterativeDataDisplay();

    int execute();

};

#endif //ITERATIVE_DATA_FRAMEWORK_ITERATIVEDATADISPLAY_H
