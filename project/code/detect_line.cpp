//
// Created by SanseYooyea on 2023/9/19.
//

#include "detect_line.h"

//boolean is_wall(int (*img)[IMG_RIGHT], Point p) {
//    return img[p.row][p.column] == WALL;
//}
//
//boolean is_road(int (*img)[IMG_RIGHT], Point p) {
//    return img[p.row][p.column] == ROAD;
//}
//
//Point find_left_start_point(int (*img)[IMG_RIGHT]) {
//    Point notfound = {-1, -1};
//
//    int center = IMG_RIGHT / 2;
//    for (int r = IMG_BOTTOM - 1; r >= 0; r--) {
//        for (int c = center; c >= 0; c--) {
//            Point p = {r, c};
//            if (is_wall(img, p)) {
//                return p;
//            }
//        }
//    }
//    return notfound;
//}
//
//Point find_right_start_point(int (*img)[IMG_RIGHT]) {
//    Point notfound = {-1, -1};
//
//    int center = IMG_RIGHT / 2;
//    for (int r = IMG_BOTTOM - 1; r >= 0; r--) {
//        for (int c = center; c < IMG_RIGHT; c++) {
//            Point p = {r, c};
//            if (is_wall(img, p)) {
//                return p;
//            }
//        }
//    }
//    return notfound;
//}
//
//Point get_front_point(Point current_point, Direction current_direction) {
//    Point front_point = current_point;
//    switch (current_direction) {
//        case UP:
//            front_point.row--;
//            break;
//        case LEFT:
//            front_point.column--;
//            break;
//        case DOWN:
//            front_point.row++;
//            break;
//        case RIGHT:
//            front_point.column++;
//            break;
//    }
//    return front_point;
//}
//
//Point *find_left_line(int (*img)[IMG_RIGHT], Point left_start_point, int *num) {
//    // initialize
//    static Point line[MAX_LINE_SIZE];
//    int step = 0;
//    Point current_point = left_start_point;
//    Direction current_direction = UP;
//
//    // first point
//    line[step++] = current_point;
//
//    // turn direction times
//    int turn = 0;
//
//    // check line is closed
//    while (turn < 4
//           && current_point.row != 0 && current_point.row != IMG_RIGHT - 1
//           && current_point.column != 0 && current_point.column != IMG_BOTTOM - 1) {
//
//        // get left point and left front point
//        Point front_point = get_front_point(current_point, current_direction);
//        Point right_point = get_right_point(current_point, current_direction);
//        Point right_front_point = get_right_front_point(current_point, current_direction);
//
//        // make sure right point is not accessible
//        // if not, break, maybe end of the line or img is wrong
//        // TODO need to check, if the img is wrong
//        if (is_wall(img, right_point)) {
//            break;
//        }
//
//        if (is_wall(img, front_point)) {
//            // front point is accessible
//            if (is_wall(img, right_front_point)) {
//                // right front point is accessible
//                current_point = right_front_point;
//                change_direction(current_direction, RIGHT);
//                turn++;
//                if (!contain_point(line, step, right_front_point)) {
//                    // meets recording conditions
//                    line[step++] = current_point;
//                    turn = 0;
//                }
//                continue;
//            }
//
//            // right front point is not accessible
//            current_point = front_point;
//            if (!contain_point(line, step, front_point)) {
//                // meets recording conditions
//                line[step++] = current_point;
//                turn = 0;
//            }
//            continue;
//        }
//
//        // both front point and right front point are not accessible
//        // change direction to left
//        change_direction(current_direction, LEFT);
//        turn++;
//    }
//
//    *num = step;
//    return line;
//}
//
//Point *find_right_line(int img[IMG_BOTTOM][IMG_RIGHT], Point right_start_point, int *num) {
//    // initialize
//    static Point line[MAX_LINE_SIZE];
//    for (int i = 0; i < MAX_LINE_SIZE; i++) {
//        // default value
//        line[i] = (Point) {-1, -1};
//    }
//
//    int step = 0;
//    Point current_point = right_start_point;
//    Direction current_direction = UP;
//
//    // first point
//    line[step++] = current_point;
//
//    // check line is closed
//    while (current_point.row != 0 && current_point.row != IMG_RIGHT - 1
//           && current_point.column != 0 && current_point.column != IMG_BOTTOM - 1) {
//        Point next_point = current_point;
//        switch (current_direction) {
//            case UP:
//                next_point.row--;
//                break;
//            case LEFT:
//                next_point.column--;
//                break;
//            case DOWN:
//                next_point.row++;
//                break;
//            case RIGHT:
//                next_point.column++;
//                break;
//        }
//
//        if (is_road(img, next_point) && !contain_point(line, step, next_point)) {
//            // meets recording conditions
//            current_point = next_point;
//            line[step++] = current_point;
//        } else if (is_wall(img, next_point)) {
//            // forward direction is blocked
//            switch (current_direction) {
//                case UP:
//                    current_direction = LEFT;
//                    break;
//                case LEFT:
//                    current_direction = DOWN;
//                    break;
//                case DOWN:
//                    current_direction = RIGHT;
//                    break;
//                case RIGHT:
//                    current_direction = UP;
//                    break;
//            }
//        } else if (is_road(img, next_point) && contain_point(line, step, next_point)) {
//            // The forward direction is a road, but it has already been traveled
//            current_point = next_point;
//        }
//    }
//
//    *num = step;
//    return line;
//}
//
//Point find_point_in_same_height(Point *line, int line_length, Point p) {
//    for (int i = 0; i < line_length; i++) {
//        if (line[i].row == p.row) {
//            return line[i];
//        }
//    }
//    return (Point) {p.row, IMG_RIGHT};
//}
//
//Point *find_middle_line(Point *left_line, int left_line_length, Point *right_line, int right_line_length) {
//    // initialize
//    Point *line = (Point *) malloc(sizeof(Point) * MAX_LINE_SIZE);
//    for (int i = 0; i < MAX_LINE_SIZE; i++) {
//        // default value
//        line[i] = (Point) {-1, -1};
//    }
//
//    if (left_line_length > right_line_length) {
//        for (int i = 0; i < left_line_length; i++) {
//            Point left_point = left_line[i];
//            Point right_point = find_point_in_same_height(right_line, right_line_length, left_point);
//            Point middle_point = find_middle_point(left_point, right_point);
//            line[i] = middle_point;
//        }
//    } else {
//        for (int i = 0; i < right_line_length; i++) {
//            Point right_point = right_line[i];
//            Point left_point = find_point_in_same_height(left_line, left_line_length, right_point);
//            Point middle_point = find_middle_point(left_point, right_point);
//            line[i] = middle_point;
//        }
//    }
//
//    return line;
//}