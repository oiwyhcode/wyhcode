#include "gpio.h"   
void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
      switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) ){
         case ENCODERL_INT_IIDX:
          if( DL_GPIO_readPins(ENCODERL_PORT,  ENCODERL_PIN_4_PIN) != 0 ) 
            {if(DL_GPIO_readPins(ENCODERL_PORT,ENCODERL_PIN_5_PIN)!=0){
                distance1++;
            }
            else if (DL_GPIO_readPins(ENCODERL_PORT,ENCODERL_PIN_5_PIN)==0) {
            distance1--;
            }
               
                
            }

        break;
      }



}