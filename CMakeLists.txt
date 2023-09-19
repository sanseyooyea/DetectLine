cmake_minimum_required(VERSION 3.26)
project(DetectLine C)

set(CMAKE_C_STANDARD 23)

add_executable(DetectLine
        project/user/main.c
        project/code/camera.cpp
        project/code/camera.h
        project/code/detect_line.cpp
        project/code/detect_line.h
        project/code/common_data.cpp
        project/code/common_data.h
        project/code/point.cpp
        project/code/point.h
        project/code/direction.cpp
        project/code/direction.h
)
