#include "ti_msp_dl_config.h"
#include "uart.h"
#include "OLED.h"
#include "tim.h"
#include "delay.h"
#include "PID_speed.h"
#include "stdio.h"
#include "string.h"
#include "gpio.h"
float PIDL_Kp=7;
float PIDL_Ki=1;
float PIDL_Kd=3.5;
float PIDR_Kp=7;
float PIDR_Ki=1;
float PIDR_Kd=3.5;
// PID PIDL;
// PID PIDR;
extern int distance1, speednow1,pwm1,distance2,speednow2,pwm2;

 char message[255]=" ";
int main(void)
{
    SYSCFG_DL_init();
    OLED_Init();
        //清除串口中断标志
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
            //清除定时器中断标志
    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);

    //使能定时器中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);

    NVIC_EnableIRQ(ENCODERL_INT_IRQN); 

    uart0_send_string("uart0 start work\r\n");
 
    while (1)
    {    
        sprintf(message, "distance1:%d",distance1) ;
           OLED_NewFrame();
        OLED_PrintString(1, 1, message, &font16x16,   0);
   
        OLED_ShowFrame();
  
 
            DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,1000,GPIO_PWM_MOTOR_C0_IDX);   



    
}


}