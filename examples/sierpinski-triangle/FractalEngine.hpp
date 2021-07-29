//
// Created by kerstop on 7/12/21.
//

#ifndef ITERATIVE_DATA_FRAMEWORK_FRACTAL_H
#define ITERATIVE_DATA_FRAMEWORK_FRACTAL_H

#include <vector>
#include <utility>
#include <random>
#include "IterativeDataEngine.hpp"


enum class FRACTAL_SHAPE {TRIANGLE};

class FractalEngine: public IterativeDataEngine {
private:

    int iteration;
    int x_cord;
    int y_cord;

    std::vector<std::pair<int,int>> vertices;
    std::vector<std::vector<pixel>> point_data;
    std::default_random_engine num_generator;

    /* function to vertices value of this class
     * will only be called by the constructor.
     */
    void setShape(FRACTAL_SHAPE);

public:

    FractalEngine(int width, int height, FRACTAL_SHAPE);

    void calculate() override;
    std::vector<std::vector<pixel>> getData() override;
    bool needsRedraw() override;

};


#endif //ITERATIVE_DATA_FRAMEWORK_FRACTAL_H
