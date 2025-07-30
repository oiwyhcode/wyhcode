#ifndef __UART_H
#define __UART_H
#include "ti_msp_dl_config.h"
#include "PID_speed.h"
void uart0_send_char(char ch);
void uart0_send_string(char* str);
void UART_0_INST_IRQHandler(void);
PID PIDL;
PID PIDR;
extern float PIDL_Kp,
 PIDL_Ki,
 PIDL_Kd,
 PIDR_Kp,
 PIDR_Ki,
 PIDR_Kd;

#endif

