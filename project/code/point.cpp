//
// Created by SanseYooyea on 2023/9/19.
//

#include "point.h"
#include "common_data.h"

boolean contain_point(Point *line, int line_length, Point p) {
    for (int i = 0; i < line_length; i++) {
        if (line[i].row == p.row && line[i].column == p.column) {
            return TRUE;
        }
    }
    return FALSE;
}

Point find_left_point(Point current_point, Direction current_direction) {
    Point left_point = current_point;
    switch (current_direction) {
        case UP:
            left_point.column--;
            break;
        case LEFT:
            left_point.row--;
            break;
        case DOWN:
            left_point.column++;
            break;
        case RIGHT:
            left_point.row++;
            break;
    }
    return left_point;
}

Point find_left_front_point(Point current_point, Direction current_direction) {
    Point left_front_point = current_point;
    switch (current_direction) {
        case UP:
            left_front_point.row--;
            left_front_point.column++;
            break;
        case LEFT:
            left_front_point.row--;
            left_front_point.column--;
            break;
        case DOWN:
            left_front_point.row++;
            left_front_point.column--;
            break;
        case RIGHT:
            left_front_point.row++;
            left_front_point.column++;
            break;
    }
    return left_front_point;
}

Point find_right_point(Point current_point, Direction current_direction) {
    Point right_point = current_point;
    switch (current_direction) {
        case UP:
            right_point.column++;
            break;
        case LEFT:
            right_point.row++;
            break;
        case DOWN:
            right_point.column--;
            break;
        case RIGHT:
            right_point.row--;
            break;
    }
    return right_point;
}

Point find_right_front_point(Point current_point, Direction current_direction) {
    Point right_front_point = current_point;
    switch (current_direction) {
        case UP:
            right_front_point.row--;
            right_front_point.column--;
            break;
        case LEFT:
            right_front_point.row++;
            right_front_point.column--;
            break;
        case DOWN:
            right_front_point.row++;
            right_front_point.column++;
            break;
        case RIGHT:
            right_front_point.row--;
            right_front_point.column++;
            break;
    }
    return right_front_point;
}