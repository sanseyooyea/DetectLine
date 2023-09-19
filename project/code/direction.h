//
// Created by SanseYooyea on 2023/9/19.
//

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
void change_direction(Direction *current_direction, Direction left_or_right) {
    // must be LEFT or RIGHT!
    if (left_or_right != LEFT && left_or_right != RIGHT) {
        return;
    }

    if (left_or_right == LEFT) {
        switch (*current_direction) {
            case UP:
                *current_direction = LEFT;
                break;
            case LEFT:
                *current_direction = DOWN;
                break;
            case DOWN:
                *current_direction = RIGHT;
                break;
            case RIGHT:
                *current_direction = UP;
                break;
        }
    }

    if (left_or_right == RIGHT) {
        switch (*current_direction) {
            case UP:
                *current_direction = RIGHT;
                break;
            case LEFT:
                *current_direction = UP;
                break;
            case DOWN:
                *current_direction = LEFT;
                break;
            case RIGHT:
                *current_direction = DOWN;
                break;
        }
    }
}

#endif //DETECTLINE_DIRECTION_H
