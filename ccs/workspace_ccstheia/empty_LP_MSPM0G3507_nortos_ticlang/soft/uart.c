#include "uart.h"
#include <stdio.h>      // 用于sscanf函数
#include <string.h>     // 用于字符串处理

#define BUFFER_SIZE 32  // 接收缓冲区大小
static char rx_buffer[BUFFER_SIZE];
static uint8_t rx_index = 0;
float speed_value = 0.0f;  // 存储提取的速度值
volatile unsigned char uart_data = 0;
 
 //串口发送单个字符
void uart0_send_char(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_0_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_0_INST, ch);
}
//串口发送字符串
void uart0_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart0_send_char(*str++);
    }
}




//串口的中断服务函数
void UART_0_INST_IRQHandler(void)
{
    // 如果产生了串口中断
    switch( DL_UART_getPendingInterrupt(UART_0_INST) )
    {
        case DL_UART_IIDX_RX:  // 如果是接收中断
            // 读取接收到的字符
            char c = DL_UART_Main_receiveData(UART_0_INST);
            
            // 简单的行缓冲处理（遇到换行符或缓冲区满时处理）
            if ((c == '\n') || (rx_index >= BUFFER_SIZE - 1)) {
                rx_buffer[rx_index] = '\0';  // 字符串结束符
                
                // 解析SPEEDL命令
                if (strstr(rx_buffer, "SPEEDL") != NULL) {
                    float value;
                    if (sscanf(rx_buffer, "SPEEDL %f", &value) == 1) {
                        PIDL.target_val = value;  // 成功提取浮点数
                        // 发送确认消息
                        char response[32];
                        sprintf(response, "SPEEDL SET TO %.2f\n", PIDL.target_val);
                        uart0_send_string(response);
                    }
                }
                // 解析PIDL命令 (新增代码)
                else if (strstr(rx_buffer, "PIDL") != NULL) {
                    float kp, ki, kd;
                    if (sscanf(rx_buffer, "PIDL %f %f %f", &kp, &ki, &kd) == 3) {
                        PIDL.Kp = kp;
                        PIDL.Ki = ki;
                        PIDL.Kd = kd;
                        // 发送确认消息
                        char response[64];
                        sprintf(response, "PIDL UPDATED: Kp=%.2f Ki=%.2f Kd=%.2f\n", kp, ki, kd);
                        uart0_send_string(response);
                    }
                }
                
                rx_index = 0;  // 重置缓冲区
            } else {
                rx_buffer[rx_index++] = c;  // 存储字符到缓冲区
            }
            break;

        default:  // 其他的串口中断
            break;
    }
}