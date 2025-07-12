#include "pidspeed.h"

void Set_motor_pwmL(float pwm){
	if(pwm<0)
	{HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, ENABLE);
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, DISABLE);
	 __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,-pwm);
	}
	else if(pwm>=0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, DISABLE);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, ENABLE);
	 __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,pwm);
	}
}

void Set_motor_pwmR(float pwm){
	if(pwm<0)
	{HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, DISABLE);
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, ENABLE);
	 __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,-pwm);
	}
	else if(pwm>=0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, ENABLE);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, DISABLE);
	 __HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,pwm);
	}
}


/*设置左轮速度值 pid为PID参数结构体
 * speed为期望达到速度
 */
void Set_motor_speedL(PID *pid,float speed){
	pid->target_val=speed;
	Set_motor_pwmL(PosionPID_realize(pid,speednow));


}
/*设置右轮速度值 pid为PID参数结构体
 * speed为期望达到速度
 */
void Set_motor_speedR(PID *pid,float speed){
	pid->target_val=speed;
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

/**
  * @brief  位置PID算法实现
  * @param  actual_val:实际测量值
  *	@note 	无
  * @retval 通过PID计算后的输出
  */
float PosionPID_realize(PID *pid, float actual_val)
{
	/*计算目标值与实际值的误差*/
	pid->Error = pid->target_val - actual_val;
	/*积分项*/
	pid->integral += pid->Error;
	if (pid->integral > 800 / pid->Ki) {
	    pid->integral = 800 / pid->Ki;
	} else if (pid->integral < -800 / pid->Ki) {
	    pid->integral = -800 / pid->Ki;}
	/*PID算法实现*/
	pid->output_val = pid->Kp * pid->Error +
	                  pid->Ki * pid->integral +
	                  pid->Kd *(pid->Error -pid->LastError);
	/*误差传递*/
	pid-> LastError = pid->Error;



	return pid->output_val;
}

