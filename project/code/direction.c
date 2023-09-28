#include "direction.h"

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
