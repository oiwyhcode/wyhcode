#include "Angle_PID.h"

void PID_Angle_init(PID_Angle *pid,float target_val,float Kp,float Ki,float Kd)
{
	pid->target_val=target_val;
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;


}


void PID_Angle_realize(PID_Angle *pid, float CurrentAngle) {
    // 1. 计算当前误差
    pid->Error = pid->target_val - CurrentAngle;

    // 2. 计算积分项 (带积分限幅，防止积分饱和)
    pid->Integral += pid->Error;
    if (pid->Integral > 300) pid->Integral = 300;
    if (pid->Integral < -300) pid->Integral = -300;

    // 3. 计算微分项
    float derivative = pid->Error - pid->LastError;

    // 4. 计算总输出
    pid->output_val = (pid->Kp * pid->Error) +
                  (pid->Ki * pid->Integral) +
                  (pid->Kd * derivative);
    if (pid->output_val > 300) pid->output_val = 300;
    if (pid->output_val < -500) pid->output_val = -300;
    // 5. 更新上次误差
    pid->LastError = pid->Error;
}

