#include "Trace.h"
#include "delay.h"
 bool KeyDetect(void) {
    // 检测按键是否按下
    if (DL_GPIO_readPins(KEY_PORT, KEY_PIN_8_PIN) == 0) {  // 假设低电平按下
        Delay_ms(20);  // 延时20ms消抖
        
        // 再次确认按键是否仍被按下
        if (DL_GPIO_readPins(KEY_PORT, KEY_PIN_8_PIN) == 0) {
            // 等待按键释放（避免长按触发多次）
            while (DL_GPIO_readPins(KEY_PORT, KEY_PIN_8_PIN) == 0) {
                // 可添加LED闪烁等反馈
            }
            return true;  // 按键有效按下并释放
        }
    }
    return false;  // 无有效按键
}

// 圈数设置函数（在主循环中调用）
void SetCircleByKey(void) {
    if (KeyDetect()) {
        // 圈数+1，超过5则重置为1
        set_circle++;
        if (set_circle > 5) {
            set_circle = 1;
        }
        
  
    }
}

void CheckStartKey(void) {
    // 读取B27引脚状态（上拉输入，未按下为1，按下为0）
    bool start_key_pressed = (DL_GPIO_readPins(KEY_PORT, KEY_PIN_9_PIN) == 0);
    
    if (start_key_pressed) {
        Delay_ms(20);  // 消抖处理
        // 再次确认按键按下
        if (DL_GPIO_readPins(KEY_PORT, KEY_PIN_9_PIN) == 0) {
            start_flag = 1;  // 置位启动标志
            // 等待按键释放，避免长按重复触发
            while (DL_GPIO_readPins(KEY_PORT, KEY_PIN_9_PIN) == 0);
        }
    }
}
float Get_Trace(){
    // 读取引脚状态（返回值为寄存器值，需判断对应位是否为1）
    uint32_t out1_raw = DL_GPIO_readPins(Trace_out1_PORT, Trace_out1_PIN);
    uint32_t out2_raw = DL_GPIO_readPins(Trace_out2_PORT, Trace_out2_PIN);
    uint32_t out3_raw = DL_GPIO_readPins(Trace_out3_PORT, Trace_out3_PIN);
    uint32_t out4_raw = DL_GPIO_readPins(Trace_out4_PORT, Trace_out4_PIN);
    uint32_t out5_raw = DL_GPIO_readPins(Trace_out5_PORT, Trace_out5_PIN);

    // 将寄存器值转换为逻辑0/1（高电平为1，低电平为0）
    int out1 = (out1_raw & Trace_out1_PIN) ? 1 : 0;  // 检查对应引脚位是否为1
    int out2 = (out2_raw & Trace_out2_PIN) ? 1 : 0;
    int out3 = (out3_raw & Trace_out3_PIN) ? 1 : 0;
    int out4 = (out4_raw & Trace_out4_PIN) ? 1 : 0;
    int out5 = (out5_raw & Trace_out5_PIN) ? 1 : 0;

    // 计算误差（此时每个out为0或1，结果范围：-2-2）
    float error = (-2 * out1) + (-1 * out2) + (0 * out3) + (1 * out4) + (2 * out5);
    return error;
}
 

void get_now_circle() {
     uint32_t out1_raw = DL_GPIO_readPins(Trace_out1_PORT, Trace_out1_PIN);
    uint32_t out2_raw = DL_GPIO_readPins(Trace_out2_PORT, Trace_out2_PIN);
     int out1 = (out1_raw & Trace_out1_PIN) ? 1 : 0;  // 检查对应引脚位是否为1
    int out2 = (out2_raw & Trace_out2_PIN) ? 1 : 0;

    // 1. 检测顶点条件：out1和out2同时为1，且未处于锁定状态
    if (out1 == 1 && out2 == 1 && count_lock == 0) {
        corner_count++;       // 顶点计数+1
        count_lock = 1;       // 锁定，1.5秒内不再加
      

        // 2. 每4个顶点计为1整圈
        if (corner_count >= 4) {
            now_circle++;     // 整圈计数+1
            corner_count = 0; // 重置顶点计数
        }


        Delay_ms(200);       // 1.5秒内不再计数
        count_lock = 0;       // 解锁

    }
}




void PID_Trace_init(PID_Trace *pid,float target_val,float Kp,float Ki,float Kd)
{
	pid->target_val=target_val;
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;


}


void PID_Trace_realize(PID_Trace *pid, float CurrentValue) {
    // 1. 计算当前误差
    pid->Error = pid->target_val - CurrentValue;

    // 2. 计算积分项 (带积分限幅，防止积分饱和)
    pid->Integral =0;
    // if (pid->Integral > 0) pid->Integral = 0;
    // if (pid->Integral < 0) pid->Integral = 0;

    // 3. 计算微分项
    float derivative = pid->Error - pid->LastError;

    // 4. 计算总输出
    pid->output_val = (pid->Kp * pid->Error) +
                  (pid->Ki * pid->Integral) +
                  (pid->Kd * derivative);
    if (pid->output_val > 300) pid->output_val = 300;
    if (pid->output_val < -300) pid->output_val = -300;
    // 5. 更新上次误差
    pid->LastError = pid->Error;
}

