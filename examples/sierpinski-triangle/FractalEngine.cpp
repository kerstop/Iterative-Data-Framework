//
// Created by kerstop on 7/12/21.
//

#include "FractalEngine.h"
#include "IterativeDataDisplay.h"
#include <memory>

int main(){

    /*
     * create a FractalEngine which is derived from the
     * IterativeDataEngine class that the IterativeDataDisplay
     * takes as an argument
     */
    FractalEngine engine(800, 800, FRACTAL_SHAPE::TRIANGLE);

    IterativeDataDisplay display(&engine);

    display.execute();


    return 0;
}

FractalEngine::FractalEngine(int width, int height, FRACTAL_SHAPE shape)
: IterativeDataEngine(width, height) {

    // set the coordinates to the middle of the screen
    x_cord = getWidth()/2;
    y_cord = getHeight()/2;

    // the engine has not been iterated yet
    iteration = 0;

    // initialize the coordinates to randomly choose from
    setShape(shape);

    //create an array of pixels to store our progress.
    point_data.assign(getWidth() * getHeight(), pixel{0,0,0,0});


}

void FractalEngine::calculate() {

    //pick a random vertex
    int vert = num_generator.operator()() % vertices.size();

    x_cord = (x_cord + vertices[vert].first) /2;
    y_cord = (y_cord + vertices[vert].second) /2;

    int x_offset = x_cord;
    int y_offset = getHeight() * y_cord;

    pixel* p = &point_data[x_offset + y_offset];
    if(p->g < 255){
        p->g += 255;
    }

    iteration++;
}

std::vector<pixel> FractalEngine::getData() {
    return point_data;
}

bool FractalEngine::needsRedraw() {
    return iteration % 1000 == 0;
}

void FractalEngine::setShape(FRACTAL_SHAPE shape) {
    vertices.clear();
    switch (shape) {
        case FRACTAL_SHAPE::TRIANGLE:
            vertices.emplace_back(std::pair<int,int>(getWidth()/2, 0));         // Top
            vertices.emplace_back(std::pair<int,int>(0, getHeight()));          // Bottom-left
            vertices.emplace_back(std::pair<int,int>(getWidth(), getHeight())); // Bottom-Right
            break;

    }
}
