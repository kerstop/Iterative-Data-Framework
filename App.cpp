//
// Created by kerstop on 6/24/21.
//

#include "App.h"
#include <SDL2/SDL.h>


App::App(int width, int height) {

    running = true;

    data = Data(width, height, VertexShape::TRIANGLE);

    this->width = width;
    this->height = height;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

}

App::~App() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int App::onExecute() {

    SDL_Event event;

    while(running){

        while(SDL_PollEvent(&event)){
            onEvent(&event);
        }

        //SDL_Delay(10);
        onLoop();
        onRender();

    }

    return 0;
}

void App::onEvent(SDL_Event *event) {
    if(event->type == SDL_QUIT){
        running = false;
    }
}

void App::onLoop() {

    data.calculateCycle();

}

void App::onRender() {

    if(data.getUpdates() > 1000){

        auto pixelData = data.getData();

        for(int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                SDL_SetRenderDrawColor(renderer,
                                       0,
                                       0,
                                       pixelData[x][y],
                                       0);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
        data.resetUpdates();
        SDL_RenderPresent(renderer);
    }
}
