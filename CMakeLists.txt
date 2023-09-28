cmake_minimum_required(VERSION 3.26)
project(DetectLine C)

set(CMAKE_C_STANDARD 23)

include_directories(project/code)
include_directories(project/user)

LINK_LIBRARIES(m)
add_executable(DetectLine
        project/user/main.c
        project/code/camera.h
        project/code/detect_line.c
        project/code/detect_line.h
        project/code/common_data.c
        project/code/common_data.h
        project/code/point.c
        project/code/point.h
        project/code/direction.c
        project/code/direction.h
        project/code/img_process.h
        project/code/img_process.c
        project/code/utils.h
)
