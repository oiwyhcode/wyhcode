/*
 * pid.h
 *
 *  Created on: Jun 5, 2025
 *      Author: 14931
 */

#ifndef MYCODE_PID_H_
#define MYCODE_PID_H_

typedef struct
{
	 //相关速度PID参数
	float Velcity_Kp;
	float Velcity_Ki;
	float Velcity_Kd;
	float Ur;				//限幅值

	int PID_is_Enable;		//PID使能
	int Un;					//期望输出值
	int En_1;				//上一次的误差值
	int En_2;				//上上次的误差值
	int PWM;				//输出PWM值
	int Velcity_Target;

}PID_InitDefStruct;

extern PID_InitDefStruct pidL;  // 定义全局变量 pid
extern PID_InitDefStruct pidR;  // 定义全局变量 pidR

void PID_Init(PID_InitDefStruct* p, float Velcity_Kp, float Velcity_Ki, float Velcity_Kd,int Velcity_Target );
void Velocity_PID(int TargetVelocity,int CurrentVelocity,PID_InitDefStruct* p);



#endif /* MYCODE_PID_H_ */
