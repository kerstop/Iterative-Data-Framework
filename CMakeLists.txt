cmake_minimum_required(VERSION 3.19)
project(Iterative_Data_Framework)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(SDL2 REQUIRED)

list(APPEND CMAKE_PREFIX_PATH "/usr/include/")

include_directories(${SDL2_INCLUDE_DIRS} include)

add_library(IterativeDataEngine STATIC src/IterativeDataDisplay.cpp src/ConsoleHandler.cpp include/ConsoleHandler.hpp src/CommunicationChannel.cpp include/CommunicationChannel.hpp)


#sierpinski triangle example
add_executable(fractal examples/sierpinski-triangle/FractalEngine.cpp)
target_link_libraries(fractal IterativeDataEngine ${SDL2_LIBRARIES})

#logistic map example
add_executable(logistic_map examples/logistic-map/LogisticMapEngine.cpp examples/logistic-map/LogisticMapEngine.hpp)
target_link_libraries(logistic_map IterativeDataEngine ${SDL2_LIBRARIES})

