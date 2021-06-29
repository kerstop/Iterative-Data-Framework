//
// Created by kerstop on 6/24/21.
//

#ifndef FRACTAL_V2_APP_H
#define FRACTAL_V2_APP_H

#include <SDL2/SDL.h>
#include <vector>
#include <utility>
#include "Data.h"

class App{
private:
    bool running;

    int width;
    int height;

    Data data;

    SDL_Renderer* renderer;
    SDL_Window* window;

public:

    App(int width, int height);
    ~App();

    int onExecute();
    void onEvent(SDL_Event* event);
    void onLoop();
    void onRender();

};


#endif //FRACTAL_V2_APP_H
