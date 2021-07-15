//
// Created by kerstop on 7/12/21.
//

#ifndef FRACTAL_V2_FRACTAL_H
#define FRACTAL_V2_FRACTAL_H

#include <vector>
#include <utility>
#include <random>
#include "IterativeDataEngine.h"


enum class FRACTAL_SHAPE {TRIANGLE};

class FractalEngine: public IterativeDataEngine {
private:

    int iteration;
    int x_cord;
    int y_cord;

    std::vector<std::pair<int,int>> vertices;
    std::vector<pixel> point_data;
    std::default_random_engine num_generator;

    /* function to vertices value of this class
     * will only be called by the constructor.
     */
    void setShape(FRACTAL_SHAPE);

public:

    FractalEngine(int width, int height, FRACTAL_SHAPE);

    void                calculate()     override;
    std::vector<pixel>  getData()       override;
    bool                needsUpdate()   override;

};


#endif //FRACTAL_V2_FRACTAL_H
