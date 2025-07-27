#include "tim.h"
#include "uart.h"

int distance1, speednow1,pwm1,distance2,speednow2,pwm2;

//定时器的中断服务函数 已配置为1秒的周期
void TIMER_0_INST_IRQHandler(void)
{
    //如果产生了定时器中断
    switch( DL_TimerG_getPendingInterrupt(TIMER_0_INST) )
    {
        case DL_TIMER_IIDX_ZERO://如果是0溢出中断 
            //将LED灯的状态翻转
               uart0_send_string("uart0 start work\r\n");
               

            break;

        default://其他的定时器中断
            break;
    }
}
