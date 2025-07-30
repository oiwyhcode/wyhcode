#include "PID_speed.h"
int   stop_flag;
void motor_stop(){
    
	DL_GPIO_clearPins(motorB_PORT, motorB_PIN_2_PIN);
	 DL_GPIO_clearPins(motorB_PORT, motorB_PIN_3_PIN);
     DL_GPIO_clearPins(motorA_PORT, motorA_PIN_1_PIN);
	 DL_GPIO_clearPins(motorA_PORT, motorA_PIN_0_PIN);
	 stop_flag=1;
}
void Set_motor_pwmL(float pwm){
	if(pwm<0&&stop_flag!=1)
	{DL_GPIO_setPins(motorA_PORT, motorA_PIN_1_PIN);
	 DL_GPIO_clearPins(motorA_PORT, motorA_PIN_0_PIN);
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,-pwm,GPIO_PWM_MOTOR_C0_IDX);  
	}
	else if(pwm>=0&&stop_flag!=1){
DL_GPIO_setPins(motorA_PORT, motorA_PIN_0_PIN);
	 DL_GPIO_clearPins(motorA_PORT, motorA_PIN_1_PIN);
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,pwm,GPIO_PWM_MOTOR_C0_IDX);
	}
}

void Set_motor_pwmR(float pwm){
	if(pwm<0&&stop_flag!=1)
	{DL_GPIO_setPins(motorB_PORT, motorB_PIN_2_PIN);
	 DL_GPIO_clearPins(motorB_PORT, motorB_PIN_3_PIN);
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,-pwm,GPIO_PWM_MOTOR_C1_IDX);
	}
	else if(pwm>=0&&stop_flag!=1){
     DL_GPIO_setPins(motorB_PORT, motorB_PIN_3_PIN);
	 DL_GPIO_clearPins(motorB_PORT, motorB_PIN_2_PIN);
     DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST,pwm,GPIO_PWM_MOTOR_C1_IDX);
	}
}

void Set_motor_expect_speedL(PID *pid,float speed){
	pid->target_val=speed;
}
void Set_motor_expect_speedR(PID *pid,float speed){
	pid->target_val=speed;
}
/*设置左轮速度值 pid为PID参数结构体
 * speed为期望达到速度
 */
void Set_motor_speedL(PID *pid,float speed){
	pid->target_finally=speed;
	Set_motor_pwmL(PosionPID_realize(pid,speednow1));  


}
/*设置右轮速度值 pid为PID参数结构体
 * speed为期望达到速度
 */
void Set_motor_speedR(PID *pid,float speed){
	pid->target_finally=speed;
	Set_motor_pwmR(PosionPID_realize(pid,speednow2));

}
/**
  * @brief  PID参数初始化
  *	@note 	无
  * @retval 无
  */
void PID_param_init(PID *pid,float target_val,float Kp,float Ki,float Kd)
{
	pid->target_val=target_val;
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;


}

// /**
//   * @brief  位置PID算法实现
//   * @param  actual_val:实际测量值
//   *	@note 	无
//   * @retval 通过PID计算后的输出
//   */
float PosionPID_realize(PID *pid, float actual_val)
{
	/*计算目标值与实际值的误差*/
	pid->Error = pid->target_finally - actual_val;
	/*积分项*/
	pid->integral += pid->Error;
	if (pid->integral > 600) {
	    pid->integral = 600 ;
	} else if (pid->integral < -600 ) {
	    pid->integral = -600 ;}
	/*PID算法实现*/
	pid->output_val = pid->Kp * pid->Error +
	                  pid->Ki * pid->integral +
	                  pid->Kd *(pid->Error -pid->LastError);
    if (pid->output_val > 1000) pid->output_val = 1000;
    if (pid->output_val < -1000) pid->output_val = -1000;
	/*误差传递*/
	pid-> LastError = pid->Error;



	return pid->output_val;
}