//
// Created by SanseYooyea on 2023/9/28.
//

#ifndef DETECTLINE_IMG_PROCESS_H
#define DETECTLINE_IMG_PROCESS_H

#include <stdint.h>

typedef struct image {
    uint8_t *data;
    uint32_t width;
    uint32_t height;
    uint32_t step;
} image_t;

typedef struct fimage {
    float *data;
    uint32_t width;
    uint32_t height;
    uint32_t step;
} fimage_t;

#define AT_IMAGE(img, x, y)          ((img)->data[(y)*(img)->step+(x)])
#define AT_IMAGE_CLIP(img, x, y)     AT_IMAGE(img, clip(x, 0, (img)->width-1), clip(y, 0, (img)->height-1))

#define DEF_IMAGE(ptr, w, h)         {.data=ptr, .width=w, .height=h, .step=w}
#define ROI_IMAGE(img, x1, y1, w, h) {.data=&AT_IMAGE(img, x1, y1), .width=w, .height=h, .step=img.width}

/**
 * 深拷贝图片，img0和img1不可以指向相同图片
 * @param img0 原图
 * @param img1 目标图
 */
void clone_image(image_t *img0, image_t *img1);

/**
 * 清空图片
 * @param img 图片
 */
void clear_image(image_t *img);

/**
 * 基础二值化，img0和img1可以指向相同图片
 * @param img0 图1
 * @param img1 图2
 * @param thres 阈值
 * @param low_value 低阈值
 * @param high_value 高阈值
 */
void threshold(image_t *img0, image_t *img1, uint8_t thres, uint8_t low_value, uint8_t high_value);

/**
 * 自适应二值化，img0和img1不可指向相同图片
 * @param img0 pointer to the input image
 * @param img1 pointer to the output image
 * @param block_size size of the block used for thresholding
 * @param down_value value subtracted from the threshold
 * @param low_value value assigned to pixels below the threshold
 * @param high_value value assigned to pixels above the threshold
 */
void adaptive_threshold(image_t *img0, image_t *img1, int block_size, int down_value, uint8_t low_value, uint8_t high_value);

// 像素逻辑与，即都为255时才为255
void image_and(image_t *img0, image_t *img1, image_t *img2);

// 像素逻辑或，即都为255时才为255
void image_or(image_t *img0, image_t *img1, image_t *img2);

// 最小值降采样x2
void minpool2(image_t *img0, image_t *img1);

// 3x3高斯滤波，img0和img1不可以指向相同图片，最外圈像素点不参与计算
void blur3(image_t *img0, image_t *img1);

// 3x3 Sobel梯度计算，img0和img1不可以指向相同图片，最外圈像素点不参与计算
void sobel3(image_t *img0, image_t *img1);

// 3x3腐蚀运算，img0和img1不可以指向相同图片，最外圈像素点不参与计算
void erode3(image_t *img0, image_t *img1);

// 3x3膨胀运算，img0和img1不可以指向相同图片，最外圈像素点不参与计算
void dilate3(image_t *img0, image_t *img1);

// 图像变换，最近邻插值。img0和img1不可以指向相同图片（去畸变，投影变换等。使用opencv生成变换表）
// 未测试，可能有BUG
void remap(image_t *img0, image_t *img1, fimage_t *mapx, fimage_t *mapy);

// 左手巡线同时自适应二值化，从(x,y)开始向上沿白边线走
void findline_lefthand_adaptive(image_t *img, int block_size, int clip_value, int x, int y, int pts[][2], int *num);

// 右手巡线同时自适应二值化，从(x,y)开始向上沿白边线走
void findline_righthand_adaptive(image_t *img, int block_size, int clip_value, int x, int y, int pts[][2], int *num);

// 大津法计算二值化阈值
uint16_t get_OSTU_threshold(image_t *img, uint8_t MinThreshold, uint8_t MaxThreshold);

// 点集三角滤波
void blur_points(float pts_in[][2], int num, float pts_out[][2], int kernel);

// 点集等距采样
void resample_points(float pts_in[][2], int num1, float pts_out[][2], int *num2, float dist);

// 点集局部角度变化率
void local_angle_points(float pts_in[][2], int num, float angle_out[], int dist);

// 角度变化率非极大抑制
void nms_angle(float angle_in[], int num, float angle_out[], int kernel);

/**
 * 左边线跟踪中线
 * @param pts_in 左边
 * @param num 点数
 * @param pts_out 中线
 * @param approx_num 近似点点数
 * @param dist 左边线和中线的距离
 */
void track_left_line(float pts_in[][2], int num, float pts_out[][2], int approx_num, float dist);

/**
 * 右边线跟踪中线
 * @param pts_in
 * @param num
 * @param pts_out
 * @param approx_num
 * @param dist
 */
void track_right_line(float pts_in[][2], int num, float pts_out[][2], int approx_num, float dist);

// 绘制X
void draw_x(image_t *img, int x, int y, int len, uint8_t value);

// 绘制O
void draw_o(image_t *img, int x, int y, int radius, uint8_t value);

#endif //DETECTLINE_IMG_PROCESS_H