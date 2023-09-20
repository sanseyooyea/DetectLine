#ifndef DETECTLINE_POINT_H
#define DETECTLINE_POINT_H

#include "direction.h"

typedef struct {
    /**
     * 行
     */
    int row;
    /**
     * 列
     */
    int column;
} Point;


/**
 * 判断一个点是否在边线上
 * @param line 边线
 * @param line_length 线长
 * @param p 点
 * @return true为在边线上，false为不在边线上
 */
boolean contain_point(Point *line, int line_length, Point p) {
    for (int i = 0; i < line_length; i++) {
        if (line[i].row == p.row && line[i].column == p.column) {
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * 寻找当前方向下一个点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 下一个点
 */
Point get_front_point(Point current_point, Direction current_direction) {
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

/**
 * 寻找当前点的左侧点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 左侧点
 */
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

/**
 * 寻找当前点的左前方点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 左前方点
 */
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

/**
 * 寻找当前点的右侧点
 * @param current_point
 * @param current_direction
 * @return
 */
Point get_right_point(Point current_point, Direction current_direction) {
    Point right_point = current_point;
    switch (current_direction) {
        case UP:
            right_point.column++;
            break;
        case LEFT:
            right_point.row--;
            break;
        case DOWN:
            right_point.column--;
            break;
        case RIGHT:
            right_point.row++;
            break;
    }
    return right_point;
}

/**
 * 寻找当前点的右前方点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 右前方点
 */
Point get_right_front_point(Point current_point, Direction current_direction) {
    Point right_front_point = current_point;
    switch (current_direction) {
        case UP:
            right_front_point.row--;
            right_front_point.column++;
            break;
        case LEFT:
            right_front_point.row--;
            right_front_point.column--;
            break;
        case DOWN:
            right_front_point.row++;
            right_front_point.column--;
            break;
        case RIGHT:
            right_front_point.row++;
            right_front_point.column++;
            break;
    }
    return right_front_point;
}

Point get_left_point(Point current_point, Direction current_direction) {
    Point left_point = current_point;
    switch (current_direction) {
        case UP:
            left_point.column--;
            break;
        case LEFT:
            left_point.row++;
            break;
        case DOWN:
            left_point.column++;
            break;
        case RIGHT:
            left_point.row--;
            break;
    }
    return left_point;
}

Point get_left_front_point(Point current_point, Direction current_direction) {
    Point left_front_point = current_point;
    switch (current_direction) {
        case UP:
            left_front_point.row--;
            left_front_point.column--;
            break;
        case LEFT:
            left_front_point.row++;
            left_front_point.column--;
            break;
        case DOWN:
            left_front_point.row++;
            left_front_point.column++;
            break;
        case RIGHT:
            left_front_point.row--;
            left_front_point.column++;
            break;
    }
    return left_front_point;
}

/**
 * 寻找中点
 * @param left 左侧点
 * @param right 右侧点
 * @return 中点
 */
Point find_middle_point(Point left, Point right) {
    return (Point) {(left.row + right.row) / 2, (left.column + right.column) / 2};
}

#endif //DETECTLINE_POINT_H
