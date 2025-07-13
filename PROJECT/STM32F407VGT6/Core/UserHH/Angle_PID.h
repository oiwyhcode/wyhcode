#ifndef USERHH_ANGLE_PID_H_
#define USERHH_ANGLE_PID_H_
#include "main.h"
typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float Error;
    float LastError;
    float Integral;

    float target_val; // 目标角度值
    float output_val;   // PID计算输出
} PID_Angle;

void PID_Angle_realize(PID_Angle *pid, float CurrentAngle);
void PID_Angle_init(PID_Angle *pid,float target_val,float Kp,float Ki,float Kd);

#endif /* USERHH_ANGLE_PID_H_ */
