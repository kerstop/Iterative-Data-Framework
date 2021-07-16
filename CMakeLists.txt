cmake_minimum_required(VERSION 3.19)
project(Iterative_Data_Framework)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2)

add_library(IterativeDataEngine STATIC src/IterativeDataDisplay.cpp)

add_executable(fractal examples/sierpinski-triangle/FractalEngine.cpp)
target_link_libraries(fractal IterativeDataEngine ${SDL2_LIBRARIES})

include_directories(${SDL2_INCLUDE_DIRS} include)
