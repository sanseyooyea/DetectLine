#ifndef DETECTLINE_DIRECTION_H
#define DETECTLINE_DIRECTION_H

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define Direction int

/**
 * 改变方向
 * @param current_direction 当前方向
 * @param left_or_right 左转 or 右转
 * @return 改变后的方向
 */
void change_direction(Direction *current_direction, Direction left_or_right);

#endif //DETECTLINE_DIRECTION_H
