
#ifndef USERHH_TRACE_PID_H_
#define USERHH_TRACE_PID_H_
#include "main.h"
#define SLAVE_ADDRESS 0x12// 从设备地址
#define REGISTER_ADDRESS 0x30  // 寄存器地址

//extern I2C_HandleTypeDef hi2c3;
extern UART_HandleTypeDef huart1;
typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float Error;
    float LastError;
    float Integral;

    float target_val; // 目标值，对于循迹，通常是0
    float output_val;   // PID计算输出
} PID_Trace;


void Get_Sensor_Trace();
void PID_Trace_init(PID_Trace *pid,float target_val,float Kp,float Ki,float Kd);
void PID_Trace_realize(PID_Trace *pid, float CurrentValue);
float Trace_error (void);
#endif /* USERHH_TRACE_PID_H_ */
