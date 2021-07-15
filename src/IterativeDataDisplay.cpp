//
// Created by kerstop on 7/12/21.
//

#include "IterativeDataDisplay.h"
#include <stdexcept>


IterativeDataDisplay::IterativeDataDisplay(IterativeDataEngine* engine) {

    data = engine;
    width = data->getWidth();
    height = data->getHeight();

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

    running = true;
    paused = false;

}

IterativeDataDisplay::~IterativeDataDisplay() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void IterativeDataDisplay::redrawData() {
    std::vector<pixel> pixelData = data->getData();

    if(pixelData.size() != width*height){
        throw std::length_error("The size of the pixel vector returned by the data engine was "
                                + std::to_string(pixelData.size()) + " however a vector of size "
                                + std::to_string(width * height) +"was expected");
    }


    pixel* p;
    for( size_t i = 0; i < pixelData.size(); i++){
        p = &pixelData[i];
        SDL_SetRenderDrawColor(renderer,p->r, p->g, p->b, p->a);
        SDL_RenderDrawPoint(renderer, i % width, i / width);
    }

    SDL_RenderPresent(renderer);

}

int IterativeDataDisplay::execute() {

    /*
     * a place holder that we can use to get events from sdl
     * and then process them
     */
    SDL_Event event;

    redrawData();

    while(running){

        while(SDL_PollEvent(&event)){
            handleEvent(&event);
        }

        if (paused){
            SDL_Delay(10);
            SDL_RenderPresent(renderer);
        } else {

            data->calculate();

            if (data->needsRedraw()) {
                redrawData();
            }
        }

    }

    return 0;
}

void IterativeDataDisplay::handleEvent(SDL_Event *event) {
    switch(event->type){
        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
        case SDL_KEYUP:
            handleKeyEvent(event);
            break;
    }
}

void IterativeDataDisplay::handleKeyEvent(SDL_Event *event) {
    if(event->type == SDL_KEYDOWN){
        switch (event->key.keysym.sym) {
            case SDLK_SPACE:
                //flip the value of paused
                paused = !paused;
                break;
        }
    }
}