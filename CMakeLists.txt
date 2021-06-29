cmake_minimum_required(VERSION 3.19)
project(fractal_v2)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug)

set(CMAKE_CXX_STANDARD 14)

add_executable(fractal_v2 main.cpp App.cpp App.h Data.cpp Data.h)

find_package(SDL2)

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

