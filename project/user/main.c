#include "../code/camera.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define boolean int

#define WALL 0
#define ROAD 1

#define IMG_BOTTOM 60
#define IMG_RIGHT 120

#define MAX_LINE_SIZE 100

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define Direction int

int stop = 0;

typedef struct {
    int r;
    int c;
} Point;

/**
 * 判断一个点是否为墙
 * @param img 二值化图像
 * @param p 点
 * @return 如果是墙，返回TRUE，否则返回FALSE
 */
boolean is_wall(int img[IMG_BOTTOM][IMG_RIGHT], Point p) {
    return img[p.r][p.c] == WALL;
}

/**
 * 判断一个点是否为路
 * @param img 二值化图像
 * @param p 点
 * @return 如果是路，返回TRUE，否则返回FALSE
 */
boolean is_road(int img[IMG_BOTTOM][IMG_RIGHT], Point p) {
    return img[p.r][p.c] == ROAD;
}

/**
 * 寻找左边界起始点
 * @param img 二值化图像
 * @return 左边界起始点
 *         如果没有找到，返回{-1, -1}
 */
Point find_left_start_point(int img[IMG_BOTTOM][IMG_RIGHT]) {
    Point notfound = {-1, -1};

    int center = IMG_RIGHT / 2;
    for (int r = IMG_BOTTOM - 1; r >= 0; r--) {
        for (int c = center; c >= 0; c--) {
            Point p = {r, c};
            if (is_wall(img, p)) {
                return (Point) {r, c + 1};
            }
        }
    }
    return notfound;
}

/**
 * 寻找右边界起始点
 * @param img 二值化图像
 * @return 右边界起始点
 *        如果没有找到，返回{-1, -1}
 */
Point find_right_start_point(int img[IMG_BOTTOM][IMG_RIGHT]) {
    Point notfound = {-1, -1};

    int center = IMG_RIGHT / 2;
    for (int r = IMG_BOTTOM - 1; r >= 0; r--) {
        for (int c = center; c < IMG_RIGHT; c++) {
            Point p = {r, c};
            if (is_wall(img, p)) {
                return (Point) {r, c - 1};
            }
        }
    }
    return notfound;
}

/**
 * 判断一个点是否在边线上
 * @param line 边线
 * @param line_length 线长
 * @param p 点
 * @return true为在边线上，false为不在边线上
 */
boolean contain_point(Point *line, int line_length, Point p) {
    for (int i = 0; i < line_length; i++) {
        if (line[i].r == p.r && line[i].c == p.c) {
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * 寻找左边线
 * @param img 二值化图像
 * @param left_start_point 左边线起始点
 * @return 左边线
 */
Point *find_left_line(int img[IMG_BOTTOM][IMG_RIGHT], Point left_start_point) {
    // initialize
    Point line[MAX_LINE_SIZE];
    for (int i = 0; i < MAX_LINE_SIZE; i++) {
        // default value
        line[i] = (Point) {-1, -1};
    }

    Point *start = line;
    int line_length = 0;
    Point current_point = left_start_point;
    Direction current_direction = UP;

    // first point
    line[line_length++] = current_point;

    // check line is closed
    while (current_point.r != 0 && current_point.r != IMG_RIGHT - 1
    && current_point.c != 0 && current_point.c != IMG_BOTTOM - 1) {
        Point next_point = current_point;
        switch (current_direction) {
            case UP:
                next_point.r--;
                break;
            case LEFT:
                next_point.c--;
                break;
            case DOWN:
                next_point.r++;
                break;
            case RIGHT:
                next_point.c++;
                break;
        }

        if (is_road(img, next_point) && !contain_point(line, line_length, next_point)) {
            // 符合记录条件
            current_point = next_point;
            line[line_length++] = current_point;
        } else if (is_wall(img, next_point)) {
            // 前进方向被挡住
            switch (current_direction) {
                case UP:
                    current_direction = RIGHT;
                    break;
                case LEFT:
                    current_direction = UP;
                    break;
                case DOWN:
                    current_direction = LEFT;
                    break;
                case RIGHT:
                    current_direction = DOWN;
                    break;
            }
        } else if (is_road(img, next_point) && contain_point(line, line_length, next_point)) {
            // 前进方向是路，但是已经走过了
            // 回退一步
            current_point = next_point;
        }
    }
    return start;
}

/**
 * 寻找右边线
 * @param img 二值化图像
 * @param right_start_point 右边线起始点
 * @return 右边线
 */
Point* find_right_line(int img[IMG_BOTTOM][IMG_RIGHT], Point right_start_point) {
    // initialize
    Point line[MAX_LINE_SIZE];
    for (int i = 0; i < MAX_LINE_SIZE; i++) {
        // default value
        line[i] = (Point) {-1, -1};
    }

    Point *start = line;
    int line_length = 0;
    Point current_point = right_start_point;
    Direction current_direction = UP;

    // first point
    line[line_length++] = current_point;

    // check line is closed
    while (current_point.r != 0 && current_point.r != IMG_RIGHT - 1
           && current_point.c != 0 && current_point.c != IMG_BOTTOM - 1) {
        Point next_point = current_point;
        switch (current_direction) {
            case UP:
                next_point.r--;
                break;
            case LEFT:
                next_point.c--;
                break;
            case DOWN:
                next_point.r++;
                break;
            case RIGHT:
                next_point.c++;
                break;
        }

        if (is_road(img, next_point) && !contain_point(line, line_length, next_point)) {
            // 符合记录条件
            current_point = next_point;
            line[line_length++] = current_point;
        } else if (is_wall(img, next_point)) {
            // 前进方向被挡住
            switch (current_direction) {
                case UP:
                    current_direction = LEFT;
                    break;
                case LEFT:
                    current_direction = DOWN;
                    break;
                case DOWN:
                    current_direction = RIGHT;
                    break;
                case RIGHT:
                    current_direction = UP;
                    break;
            }
        } else if (is_road(img, next_point) && contain_point(line, line_length, next_point)) {
            // 前进方向是路，但是已经走过了
            // 回退一步
            current_point = next_point;
        }
    }
    return start;
}

/**
 * 打印图像
 * @param img 二值化图像
 */
void print_image(int img[IMG_BOTTOM][IMG_RIGHT]) {
    for (int r = 0; r < IMG_BOTTOM; r++) {
        for (int c = 0; c < IMG_RIGHT; c++) {
            printf("%d", img[r][c]);
        }
        printf("\n");
    }
}

int main() {
    Point left_start_point_1 = find_left_start_point(Image1);
    Point right_start_point_1 = find_right_start_point(Image1);

    printf("左侧起始点为[%d, %d]\n", left_start_point_1.r, left_start_point_1.c);
    printf("右侧起始点为[%d, %d]\n", right_start_point_1.r, right_start_point_1.c);

    Point *left_line_1 = find_left_line(Image1, left_start_point_1);
    int left_line_length_1 = 0;
    while (left_line_1->r != -1 && left_line_1->c != -1) {
        left_line_1++;
        left_line_length_1++;
    }
    printf("左边线点的个数为%d\n", left_line_length_1);

    Point *right_line_1 = find_right_line(Image1, right_start_point_1);
    int right_line_length_1 = 0;
    while (right_line_1->r != -1 && right_line_1->c != -1) {
        right_line_1++;
        right_line_length_1++;
    }
    printf("右边线点的个数为%d\n", right_line_length_1);

    print_image(Image1);

    // TODO 求中线
    // TODO 将边线和中线显示
}
