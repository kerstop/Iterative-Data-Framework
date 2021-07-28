//
// Created by kerstop on 7/15/21.
//

#ifndef ITERATIVE_DATA_FRAMEWORK_LOGISTICMAPENGINE_H
#define ITERATIVE_DATA_FRAMEWORK_LOGISTICMAPENGINE_H

#include "IterativeDataEngine.h"
#include <vector>

const pixel WHITE_PIXEL = pixel{255,255,255,255};
const pixel BLACK_PIXEL = pixel{0,0,0,0};

class LogisticMapEngine : public IterativeDataEngine {
private:

    std::vector<float> points;
    std::vector<std::vector<pixel>> display;

    static float F(float pop, float rate);

public:
    LogisticMapEngine(int width, int height);

    void calculate() override;
    std::vector<std::vector<pixel>> getData() override;
    bool needsRedraw() override;
};


#endif //ITERATIVE_DATA_FRAMEWORK_LOGISTICMAPENGINE_H
