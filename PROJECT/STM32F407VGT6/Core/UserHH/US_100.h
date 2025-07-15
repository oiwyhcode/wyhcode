
#ifndef USERHH_US_100_H_
#define USERHH_US_100_H_
#include "main.h"

extern UART_HandleTypeDef huart1;
#define FILTER_SIZE 5

// 模块最大测量距离（根据型号设定，如US-100通常最大500cm）
#define MAX_DISTANCE 450.0f
float get_filtered_distance(void);


#endif /* USERHH_US_100_H_ */
