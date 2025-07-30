#include "ti_msp_dl_config.h"
#include <stdint.h>
#include <stdbool.h>
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
// float out1,out2,out3,out4,out5;
// float error;
extern uint32_t sys_time;  // 声明全局变量
extern uint8_t set_circle;  // 声明圈数设置变量
extern uint8_t now_circle;  // 声明当前圈数变量
extern uint8_t corner_count ;     // 顶点计数（0-3，累计4个为1圈）
extern uint8_t count_lock ;       // 锁标志（1：1.5秒内不计数）
extern uint32_t last_count_time ; // 上次顶点计数时间
extern uint8_t start_flag;
void SetCircleByKey(void);
float Get_Trace();
void get_now_circle();
void motor_stop();
void CheckStartKey(void);
void PID_Trace_realize(PID_Trace *pid, float CurrentValue);
void PID_Trace_init(PID_Trace *pid,float target_val,float Kp,float Ki,float Kd);
