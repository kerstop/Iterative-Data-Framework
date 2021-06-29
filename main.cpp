#include <iostream>
#include <SDL2/SDL.h>
#include "App.h"

int main() {

    App app(800,800);

    return app.onExecute();
}
