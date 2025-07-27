#ifndef __UART_H
#define __UART_H
#include "ti_msp_dl_config.h"
void uart0_send_char(char ch);
void uart0_send_string(char* str);
void UART_0_INST_IRQHandler(void);


#endif

