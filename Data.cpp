//
// Created by kerstop on 6/28/21.
//

#include "Data.h"
#include <random>

Data::Data(int _width, int _height, VertexShape shape){

    width = _width;
    height = _height;

    std::vector<u_int8_t> builder(height, 0);
    point_data.assign(width, builder);

    pointer_x = width / 2;
    pointer_y = height / 2;

    updatesSinceRender = 0;

    setShape(shape);

}

void Data::calculateCycle() {
    int vert_index = numGenerator.operator()() % vertices.size();

    pointer_x = (pointer_x + vertices[vert_index].first) / 2;
    pointer_y = (pointer_y + vertices[vert_index].second) / 2;

    if(point_data[pointer_x][pointer_y] < 255){
        point_data[pointer_x][pointer_y]+= 8;
        updatesSinceRender++;
    }
}

void Data::setShape(VertexShape shape) {
    vertices.clear();
    switch (shape) {
        case VertexShape::TRIANGLE:
            vertices.emplace_back(std::pair<int,int>(width/2, 0)); // Top
            vertices.emplace_back(std::pair<int,int>(0, height));     // Bottom-left
            vertices.emplace_back(std::pair<int,int>(width, height));    // Bottom-Right
            break;
    }
}

std::vector<std::vector<u_int8_t>> Data::getData() {
    return point_data;
}

int Data::getUpdates() {
    return updatesSinceRender;
}

void Data::resetUpdates() {
    updatesSinceRender = 0;
}
