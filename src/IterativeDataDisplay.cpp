//
// Created by kerstop on 7/12/21.
//

#include "IterativeDataDisplay.hpp"
#include "ConsoleHandler.hpp"
#include <stdexcept>
#include <iostream>


IterativeDataDisplay::IterativeDataDisplay(IterativeDataEngine* engine):
    console(ConsoleHandler(&sharedMem)){

    data = engine;
    width = data->getWidth();
    height = data->getHeight();

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

    running = true;
    paused = false;

    sharedMem.registerChannel("Display");
}

IterativeDataDisplay::~IterativeDataDisplay() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    if(sharedMem.channelExists("Console")){
        sharedMem.sendMessage("Console", Message{"Exit"});
    }
}

void IterativeDataDisplay::redrawData() {
    std::vector<std::vector<pixel>> pixelData = data->getData();


    pixel* p;
    for(size_t x = 0; x < width; x++){
        for(size_t y = 0; y < height; y++) {
            p = &pixelData[x][y];

            SDL_SetRenderDrawColor(renderer, p->r, p->g, p->b, p->a);
            SDL_RenderDrawPoint(renderer, x, y);
        }
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
        while(sharedMem.hasMessage("Display")){
            handleMessage(sharedMem.getMessage("Display"));
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
                togglePause();
                break;
        }
    }
}

void IterativeDataDisplay::shell(IterativeDataDisplay* display) {
    while(display->running){
        std::string input;

        std::cout << ">>>";
        getline(std::cin, input, '\n');

        std::cout << input << '\n';

    }
}

void IterativeDataDisplay::togglePause() {
    paused = !paused;
}

void IterativeDataDisplay::handleMessage(Message m) {
    if(m.message == "Exit"){
        running = false;
    }
}
