#include "../code/camera.h"
#include "../code/detect_line.h"

/**
 * 打印图像
 * @param img 二值化图像
 */
void print_image(int (*img)[IMG_RIGHT]) {
    for (int r = 0; r < IMG_BOTTOM; r++) {
        for (int c = 0; c < IMG_RIGHT; c++) {
            printf("%d", img[r][c]);
        }
        printf("\n");
    }
}

int main() {
    // 1. find left and right start point
    Point left_start_point_1 = find_left_start_point(Image1);
    Point right_start_point_1 = find_right_start_point(Image1);

    printf("左侧起始点为[%d, %d]\n", left_start_point_1.row, left_start_point_1.column);
    printf("右侧起始点为[%d, %d]\n", right_start_point_1.row, right_start_point_1.column);

    // 2. find left and right line
    int left_line_length_1 = 0;
    Point *left_line_1 = find_left_line(Image1, left_start_point_1, &left_line_length_1);
    printf("左边线点的个数为%d\n", left_line_length_1 + 1);

    int right_line_length_1 = 0;
    Point *right_line_1 = find_right_line(Image1, right_start_point_1, &right_line_length_1);
    printf("右边线点的个数为%d\n", right_line_length_1);

    // 3. find middle line
    Point *middle_line_1 = find_middle_line(left_line_1, left_line_length_1, right_line_1, right_line_length_1);
    int result[IMG_BOTTOM][IMG_RIGHT];
    for (int i = 0; i < IMG_BOTTOM; ++i) {
        for (int j = 0; j < IMG_RIGHT; ++j) {
            result[i][j] = 0;
        }
    }

    // 4. print result
    for (int i = 0; i < left_line_length_1; i++) {
        result[left_line_1[i].row][left_line_1[i].column] = 1;
        printf("left_line_1[%d] = [%d, %d]\n", i, left_line_1[i].row, left_line_1[i].column);
    }

    for (int i = 0; i < right_line_length_1; ++i) {
        result[right_line_1[i].row][right_line_1[i].column] = 1;
        printf("right_line_1[%d] = [%d, %d]\n", i, right_line_1[i].row, right_line_1[i].column);
    }

    while (middle_line_1->row != -1 && middle_line_1->column != -1) {
        result[middle_line_1->row][middle_line_1->column] = 2;
        middle_line_1++;
    }

    print_image(result);
}