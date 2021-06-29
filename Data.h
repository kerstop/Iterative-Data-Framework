//
// Created by kerstop on 6/28/21.
//

#ifndef FRACTAL_V2_DATA_H
#define FRACTAL_V2_DATA_H

#include <vector>
#include <utility>
#include <random>

enum class VertexShape { TRIANGLE };

class Data {
private:

    int width;
    int height;

    int pointer_x;
    int pointer_y;
    int updatesSinceRender;

    //vertexes to choose from
    std::vector<std::pair<int,int>>     vertices;
    //information that has been calculated
    std::vector<std::vector<u_int8_t>>      point_data;
    //number generator
    std::default_random_engine          numGenerator;

    void setShape(VertexShape);

public:

    Data() {};

    Data(int width, int height, VertexShape shape);

    void calculateCycle();

    std::vector<std::vector<u_int8_t>> getData();

    int getUpdates();
    void resetUpdates();


};


#endif //FRACTAL_V2_DATA_H
