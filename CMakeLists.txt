cmake_minimum_required(VERSION 3.26)
project(DetectLine C)

set(CMAKE_C_STANDARD 23)

add_executable(DetectLine
        project/user/main.c
        project/code/camera.cpp
        project/code/camera.h
)
