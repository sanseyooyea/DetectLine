#ifndef DETECTLINE_POINT_H
#define DETECTLINE_POINT_H

#include "common_data.h"
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
boolean contain_point(Point *line, int line_length, Point p);

/**
 * 寻找当前方向下一个点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 下一个点
 */
Point get_front_point(Point current_point, Direction current_direction);

/**
 * 寻找当前点的左侧点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 左侧点
 */
Point find_left_point(Point current_point, Direction current_direction);

/**
 * 寻找当前点的左前方点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 左前方点
 */
Point find_left_front_point(Point current_point, Direction current_direction);

/**
 * 寻找当前点的右侧点
 * @param current_point
 * @param current_direction
 * @return
 */
Point get_right_point(Point current_point, Direction current_direction);

/**
 * 寻找当前点的右前方点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 右前方点
 */
Point get_right_front_point(Point current_point, Direction current_direction);

/**
 * 寻找当前点的左侧点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 左侧点
 */
Point get_left_point(Point current_point, Direction current_direction);

/**
 * 寻找当前点的左前方点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 左前方点
 */
Point get_left_front_point(Point current_point, Direction current_direction);

/**
 * 寻找中点
 * @param left 左侧点
 * @param right 右侧点
 * @return 中点
 */
Point find_middle_point(Point left, Point right);

#endif //DETECTLINE_POINT_H
