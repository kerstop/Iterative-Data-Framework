//
// Created by kerstop on 7/12/21.
//

#include "IterativeDataEngine.h"
#include <memory>
#include <SDL2/SDL.h>

#ifndef FRACTAL_V2_ITERATIVEDATADISPLAY_H
#define FRACTAL_V2_ITERATIVEDATADISPLAY_H

class IterativeDataDisplay{
private:

    bool running;

    IterativeDataEngine* data;
    int width;
    int height;

    SDL_Window* window{};
    SDL_Renderer* renderer{};

    void renderData();
    void handleEvent(SDL_Event*);

public:

    IterativeDataDisplay(IterativeDataEngine*);
    ~IterativeDataDisplay();

    int execute();

};

#endif //FRACTAL_V2_ITERATIVEDATADISPLAY_H