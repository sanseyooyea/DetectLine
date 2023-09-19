//
// Created by SanseYooyea on 2023/9/19.
//

#include "detect_line.h"

boolean is_wall(int (*img)[IMG_RIGHT], Point p) {
    return img[p.row][p.column] == WALL;
}

boolean is_road(int (*img)[IMG_RIGHT], Point p) {
    return img[p.row][p.column] == ROAD;
}

Point find_left_start_point(int (*img)[IMG_RIGHT]) {
    Point notfound = {-1, -1};

    int center = IMG_RIGHT / 2;
    for (int r = IMG_BOTTOM - 1; r >= 0; r--) {
        for (int c = center; c >= 0; c--) {
            Point p = {r, c};
            if (is_wall(img, p)) {
                return p;
            }
        }
    }
    return notfound;
}

Point find_right_start_point(int (*img)[IMG_RIGHT]) {
    Point notfound = {-1, -1};

    int center = IMG_RIGHT / 2;
    for (int r = IMG_BOTTOM - 1; r >= 0; r--) {
        for (int c = center; c < IMG_RIGHT; c++) {
            Point p = {r, c};
            if (is_wall(img, p)) {
                return p;
            }
        }
    }
    return notfound;
}

Point find_front_point(Point current_point, Direction current_direction) {
    Point front_point = current_point;
    switch (current_direction) {
        case UP:
            front_point.row--;
            break;
        case LEFT:
            front_point.column--;
            break;
        case DOWN:
            front_point.row++;
            break;
        case RIGHT:
            front_point.column++;
            break;
    }
    return front_point;
}