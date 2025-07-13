#include "SYS.h"

extern float Servo_Angle_TurnMin;//每�?�变化的角度
extern float Servo_Angle;


void Servo_SetAngle(float Angle)	//设置角度,60-120
{
    if(Angle >= 180)
    {
        Servo_SetAngle(Angle - 180); 
    }
    else if (Angle < 0) 
    {
        Servo_SetAngle(Angle + 180);
    }
    else
    {
        Servo_Angle = Angle;
	    DL_TimerA_setCaptureCompareValue(PWM_Servo_INST, Angle / 180 * 2000 + 500,GPIO_PWM_Servo_C0_IDX);
    }
	/*
	TIM_SetCompare4(TIM4, Angle / 180 * 2000 + 500);
	*/
}

void Servo_Angle_Limit(void)		//限制角度�?60-120
{
	if(Servo_Angle >= 120)
	{
		Servo_Angle = 120;
	}
	
	if(Servo_Angle <= 60)
	{
		Servo_Angle = 60;
	}
}

void Servo_Turn_Right(float Angle_Turn)
{
	Servo_Angle += Angle_Turn;
	Servo_Angle_Limit();//限幅
	Servo_SetAngle(Servo_Angle);
}

void Servo_Turn_Left(float Angle_Turn)
{
	Servo_Angle -= Angle_Turn;
	Servo_Angle_Limit();//限幅
	Servo_SetAngle(Servo_Angle);
}

void Servo_Turn_Stright(float Angle_Turn)
{
	if(Servo_Angle > 90)
	{
		Servo_Turn_Left(Angle_Turn);
	}
	
	else if(Servo_Angle < 90)
	{
		Servo_Turn_Right(Angle_Turn);
	}
	
	Servo_SetAngle(Servo_Angle);
}

//ת��
void Servo_Angle_Turn(float Angle_Turn)
{
	if(Servo_Angle < 0)
	{
		Servo_Turn_Left(Angle_Turn);
	}
	
	else if(Servo_Angle > 0)
	{
		Servo_Turn_Right(Angle_Turn);
	}
}

