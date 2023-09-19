//
// Created by SanseYooyea on 2023/9/19.
//
#ifndef DETECTLINE_DETECT_LINE_H
#define DETECTLINE_DETECT_LINE_H

#include "common_data.h"
#include "point.h"
#include "direction.h"

#define WALL 0
#define ROAD 1

#define IMG_BOTTOM 60
#define IMG_RIGHT 120

#define MAX_LINE_SIZE 100

/**
 * 判断一个点是否为墙
 * @param img 二值化图像
 * @param p 点
 * @return 如果是墙，返回TRUE，否则返回FALSE
 */
boolean is_wall(int (*img)[IMG_RIGHT], Point p);

/**
 * 判断一个点是否为路
 * @param img 二值化图像
 * @param p 点
 * @return 如果是路，返回TRUE，否则返回FALSE
 */
boolean is_road(int (*img)[IMG_RIGHT], Point p);

/**
 * 寻找左边界起始点
 * @param img 二值化图像
 * @return 左边界起始点
 *         如果没有找到，返回{-1, -1}
 */
Point find_left_start_point(int (*img)[IMG_RIGHT]);

/**
 * 寻找右边界起始点
 * @param img 二值化图像
 * @return 右边界起始点
 *        如果没有找到，返回{-1, -1}
 */
Point find_right_start_point(int (*img)[IMG_RIGHT]);

/**
 * 寻找当前方向下一个点
 * @param current_point 当前点
 * @param current_direction 当前方向
 * @return 下一个点
 */
Point get_front_point(Point current_point, Direction current_direction);

/**
 * 寻找左边线
 * @param img 二值化图像
 * @param left_start_point 左边线起始点
 * @return 左边线
 */
Point *find_left_line(int (*img)[IMG_RIGHT], Point left_start_point, int *num);

/**
 * 寻找右边线
 * @param img 二值化图像
 * @param right_start_point 右边线起始点
 * @return 右边线
 */
Point *find_right_line(int img[IMG_BOTTOM][IMG_RIGHT], Point right_start_point, int *num);

/**
 * 寻找另一侧线上与给定点同高的点
 * @param line 另一侧边线
 * @param line_length 线长
 * @param p 给定点
 * @return 另一侧线上与给定点同高的点
 *        如果没有找到，返回{-1, -1}
 */
Point find_point_in_same_height(Point *line, int line_length, Point p);

/**
 * 寻找中线
 * @param left_line 左边线
 * @param left_line_length 左边线长度
 * @param right_line 右边线
 * @param right_line_length 右边线长度
 * @return 中线
 */
Point *find_middle_line(Point *left_line, int left_line_length, Point *right_line, int right_line_length);

#endif //DETECTLINE_DETECT_LINE_H
