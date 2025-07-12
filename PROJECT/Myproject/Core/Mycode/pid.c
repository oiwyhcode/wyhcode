#include "pid.h"
void PID_Init(PID_InitDefStruct* p, float Velcity_Kp, float Velcity_Ki, float Velcity_Kd,int Velcity_Target )

{
	p->Velcity_Kp = Velcity_Kp;
	p->Velcity_Ki = Velcity_Ki;
	p->Velcity_Kd = Velcity_Kd;
	p->Ur = 1000;         //输出限幅
	p->PID_is_Enable = 1;
	p->Un = 0;
	p->En_1 = 0;
	p->En_2 = 0;
	p->PWM = 0;
	p->Velcity_Target=Velcity_Target;
}


void Velocity_PID(int TargetVelocity,int CurrentVelocity,PID_InitDefStruct* p)
{
	if(p->PID_is_Enable == 1)
	{
		int En = TargetVelocity - CurrentVelocity;  // 误差值

		        // 计算积分项并进行限幅处理
		        float integral_term = p->Velcity_Ki * En;
		        if(integral_term > 300) integral_term = 300;      // 正向积分限幅
		        if(integral_term < -300) integral_term = -300;    // 负向积分限幅

		        // 计算PID增量
		        float delta_output = p->Velcity_Kp*(En - p->En_1) + integral_term +
		                            p->Velcity_Kd*(En - 2*p->En_1 + p->En_2);

		        // 计算输出预估值
		        float predicted_output = p->Un + delta_output;

		        // 抗积分饱和处理（饱和值800）
		        if (predicted_output > 1000) {  // 正向饱和
		            // 只允许减小输出的积分项通过
		            if (integral_term < 0) {
		                p->Un += delta_output;
		            } else {
		                // 忽略增加输出的积分项
		                p->Un += p->Velcity_Kp*(En - p->En_1) +
		                         p->Velcity_Kd*(En - 2*p->En_1 + p->En_2);
		            }
		        } else if (predicted_output < 0) {  // 负向饱和
		            // 只允许增加输出的积分项通过
		            if (integral_term > 0) {
		                p->Un += delta_output;
		            } else {
		                // 忽略减小输出的积分项
		                p->Un += p->Velcity_Kp*(En - p->En_1) +
		                         p->Velcity_Kd*(En - 2*p->En_1 + p->En_2);
		            }
		        } else {
		            // 未饱和，正常累加
		            p->Un += delta_output;
		        }

		        p->En_2 = p->En_1;
		        p->En_1 = En;

		        p->PWM = p->Un;

		        /*输出限幅*/
		        if(p->PWM > p->Ur) p->PWM = p->Ur;
		        if(p->PWM < 0) p->PWM = 0;
		        if(TargetVelocity == 0) {
		            p->PWM = 0;  // 强制断电
		        }
	}


}
