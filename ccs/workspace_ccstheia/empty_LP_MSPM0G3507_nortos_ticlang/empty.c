#include "ti_msp_dl_config.h"
#include "delay.h"
#include "OLED.h"
#include "uart.h"
#include "PID_speed.h"
#include "stdio.h"
#include "Trace.h"

char message[255];

uint8_t set_circle = 1;   // 定义圈数设置变量
uint8_t now_circle = 0;   // 定义当前圈数变量
uint8_t corner_count = 0;     // 顶点计数（0-3，累计4个为1圈）
uint8_t count_lock = 0;       // 锁标志（1：1.5秒内不计数）
uint32_t last_count_time = 0; // 上次顶点计数时间
uint8_t start_flag = 0;  // 启动标志：0=未启动，1=已启动
PID PIDL;
PID PIDR;
PID_Trace Trace_PID;
float PIDL_Kp=30;
float PIDL_Ki=6;
float PIDL_Kd=0;
float PIDR_Kp=30;
float PIDR_Ki=6;
float PIDR_Kd=0;
float Trace_PID_Kp=10;
float Trace_PID_Ki=0;
float Trace_PID_Kd=0;
int distance1, speednow1 ,pwm1,distance2,speednow2,pwm2,speed1,speed2;
int main(void)
{
 PIDL.target_val=8;
 PIDR.target_val=8; 
 Trace_PID.target_val=0;
    SYSCFG_DL_init();
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,0,GPIO_PWM_MOTOR_C0_IDX);
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,0,GPIO_PWM_MOTOR_C1_IDX);

OLED_Init();

Delay_ms(2000);
    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(GPIOA_INT_IRQn);
    NVIC_EnableIRQ(GPIOB_INT_IRQn); 
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    PID_Trace_init(&Trace_PID,Trace_PID.target_val,Trace_PID_Kp,Trace_PID_Ki,Trace_PID_Kd);
 PID_param_init(&PIDL,PIDL.target_val,PIDL_Kp,PIDL_Ki,PIDL_Kd);
 PID_param_init(&PIDR,PIDR.target_val,PIDR_Kp,PIDR_Ki,PIDR_Kd);
    while (1)
    {get_now_circle();

    CheckStartKey();////
    if(now_circle>=set_circle   ){
 motor_stop();
    }
SetCircleByKey();//设定圈数
OLED_NewFrame();
 
sprintf(message, "FINALLY1:%f",Get_Trace());
OLED_PrintString(1, 1, message, &font16x16, 0);
sprintf(message, "speednow1:%d",speednow1);
OLED_PrintString(1, 16, message, &font16x16, 0);
sprintf(message, "setcircle:%d",set_circle);
OLED_PrintString(1, 32, message, &font16x16, 0);
sprintf(message, "speednow2:%d",now_circle);
OLED_PrintString(1, 48, message, &font16x16, 0);
OLED_ShowFrame();
sprintf(message, "%f,%d,%f,%f,%d,%f\n",PIDL.target_finally,speednow1,PIDL.output_val,PIDR.target_finally,speednow2,PIDR.output_val );
//  uart0_send_string( message );
    }
}  






void TIMER_0_INST_IRQHandler(void)
{
    //如果产生了定时器中断
    switch( DL_TimerG_getPendingInterrupt(TIMER_0_INST) )
    {
        case DL_TIMER_IIDX_ZERO://如果是0溢出中断 
          if (start_flag == 1) {  // 仅启动后执行循迹控制
          
        PID_Trace_realize(&Trace_PID, Get_Trace());
        speednow1=speed1;
        speednow2=speed2;
        Set_motor_speedL(&PIDL,PIDL.target_val-Trace_PID.output_val ); 
               speed1=0;
        Set_motor_speedR(&PIDR,PIDR.target_val+Trace_PID.output_val);  
               speed2=0;
            DL_GPIO_togglePins(LED1_PORT, LED1_PIN_22_PIN);    

            break;

        default://其他的定时器中断
            break;
    }
}

}
void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
      switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) ){
         case ENCODERL_INT_IIDX:
          if( DL_GPIO_readPins(ENCODERL_PORT,  ENCODERL_PIN_4_PIN) != 0&&DL_GPIO_readPins(ENCODERL_PORT,ENCODERL_PIN_5_PIN)!=0 ) 
            {
                distance1++;
                speed1++;  
            }
        
          if( DL_GPIO_readPins(ENCODERL_PORT,  ENCODERL_PIN_4_PIN) != 0&&DL_GPIO_readPins(ENCODERL_PORT,ENCODERL_PIN_5_PIN)==0 ) 
            {
                 distance1--;
                 speed1--;  
            }
                break;      
         case ENCODERR_INT_IIDX:
          if( DL_GPIO_readPins(ENCODERR_PORT,  ENCODERR_PIN_6_PIN) != 0&&DL_GPIO_readPins(ENCODERR_PORT,ENCODERR_PIN_7_PIN)!=0 )   
            {
                distance2++;
                speed2++;  
            }
        
          if( DL_GPIO_readPins(ENCODERR_PORT,  ENCODERR_PIN_6_PIN) != 0&&DL_GPIO_readPins(ENCODERR_PORT,ENCODERR_PIN_7_PIN)==0 ) 
            {
                 distance2--;
                 speed2--;  
            }       
               break;   
            }

      
      }
