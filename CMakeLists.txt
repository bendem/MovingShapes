cmake_minimum_required(VERSION 2.8.4)
project(SimplestGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -m64 -lsfml-graphics -lsfml-window -lsfml-system")

include_directories(header)

set(SOURCE_FILES
    header/Application.hpp
    header/EventManager.hpp
    header/Renderer.hpp
    header/utils/Random.hpp
    src/Application.cpp
    src/EventManager.cpp
    src/Renderer.cpp
    src/utils/Random.cpp
    main.cpp)
add_executable(SimplestGame ${SOURCE_FILES})
