//
// Created by kerstop on 6/30/21.
//

#ifndef FRACTAL_V2_ITERATIVEDATAENGINE_H
#define FRACTAL_V2_ITERATIVEDATAENGINE_H

#include <array>
#include <vector>
#include <cstdint>

struct pixel {
    //red
    uint8_t r;
    //green
    uint8_t g;
    //blue
    uint8_t b;
    //alpha
    uint8_t a;
};

class IterativeDataEngine {
private:
    int width;
    int height;

public:

    IterativeDataEngine(int width, int height){
        this->width = width;
        this->height = height;
    }

    // get the width of the data to display
    int getWidth(){
        return width;
    };

    // get the height of the data to display
    int getHeight(){
        return height;
    }

    // This function is called by GraphicalDataApp in the main loop.
    virtual void calculate() = 0;

    // GraphDataApp will only render the data when this function returns true.
    virtual bool needsUpdate() = 0;

    /*
     * Should return a std::vector<pixel> that is of size width * height
     *
     * This function will be called whenever the function needsUpdate returns true.
     */
    virtual std::vector<pixel> getData() = 0;
};

#endif //FRACTAL_V2_ITERATIVEDATAENGINE_H
