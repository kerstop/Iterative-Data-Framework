//
// Created by kerstop on 7/15/21.
//

#include "LogisticMapEngine.hpp"
#include "IterativeDataDisplay.hpp"

#include <iostream>

int main(){

    LogisticMapEngine engine(800,800);

    IterativeDataDisplay display(&engine);

    display.execute();
}

LogisticMapEngine::LogisticMapEngine(int width, int height): IterativeDataEngine(width, height) {
    points = std::vector<float>(width*pixelSubdivisions, 0.5);

    display = std::vector<std::vector<pixel>>(width, std::vector<pixel>(height, BLACK_PIXEL));
}

void LogisticMapEngine::calculate() {

    //value to dim pixels by.
    const int dec_val = 8;
    // dim all the pixels in the display
    for(auto& row : display){
        for(auto& pix : row){
            if(pix.r > 0 && pix.r - dec_val > 0){pix.r -= dec_val;} else {pix.r = 0;}
            if(pix.g > 0 && pix.g - dec_val > 0){pix.g -= dec_val;} else {pix.g = 0;}
            if(pix.b > 0 && pix.b - dec_val > 0){pix.b -= dec_val;} else {pix.b = 0;}
            if(pix.a > 0 && pix.a - dec_val > 0){pix.a -= dec_val;} else {pix.a = 0;}
        }
    }

    // draw points to the display
    float maxHeight = getHeight();
    float maxWidth = getWidth();
    for(size_t i = 0; i < points.size(); i++){
        int height = maxHeight * points[i];
        float relativeWidth = static_cast<float>(i)/ static_cast<float>(points.size());
        display[relativeWidth*maxWidth][height] = WHITE_PIXEL;
    }

    int width = getWidth();
    float rate;

    //call the logistic map function on the points
    for(size_t i = 0; i < points.size(); i++){
        rate = static_cast<float>(i) / static_cast<float>(points.size());
        rate *= maxValue;
        points[i] = F(points[i], rate);
    }

}

std::vector<std::vector<pixel>> LogisticMapEngine::getData() {
    std::vector<pixel> ret(getWidth() * getHeight(), pixel{0,0,0,0});
    for(size_t i = 0; i < getWidth(); i++){
        int y_pos = points[i] * getHeight();

        //make sure the point doesn't get drawn off the screen
        while(y_pos >= getHeight()){y_pos--;}

        ret[y_pos * getWidth() + i] = pixel{255,255,255,0};
    }
    return display;
}

bool LogisticMapEngine::needsRedraw() {
    return true;
}

// The logistic map function
float LogisticMapEngine::F(float pop, float rate) {
    return rate * pop * (1 - pop);
}
