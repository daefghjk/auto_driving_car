#include "SYS.h"

extern uint8_t Motor_En;//电机使能
extern float Motor_Set;//强制设定速度，不设定（-1）即为pid模式

void Motor_Left(int8_t Speed)
{
    uint32_t compareValue = 0;
	if (Speed >= 0)
	{
        compareValue = 3199 - 3199 * (Speed/100.0);
		DL_GPIO_clearPins(GPIO_Motor_PIN_Motor1_1_PORT, GPIO_Motor_PIN_Motor1_1_PIN);
		DL_GPIO_setPins(GPIO_Motor_PIN_Motor1_2_PORT, GPIO_Motor_PIN_Motor1_2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, compareValue,GPIO_PWM_Motor_C0_IDX);
	}
	else
	{
        compareValue = 3199 - 3199 * (-Speed/100.0);
		DL_GPIO_setPins(GPIO_Motor_PIN_Motor1_1_PORT, GPIO_Motor_PIN_Motor1_1_PIN);
		DL_GPIO_clearPins(GPIO_Motor_PIN_Motor1_2_PORT, GPIO_Motor_PIN_Motor1_2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, compareValue,GPIO_PWM_Motor_C0_IDX);
	}
}

void Motor_Right(int8_t Speed)
{
    uint32_t compareValue = 0;
	if (Speed >= 0)
	{
        compareValue = 3199 - 3199 * (Speed/100.0);
		DL_GPIO_setPins(GPIO_Motor_PIN_Motor2_1_PORT, GPIO_Motor_PIN_Motor2_1_PIN);
		DL_GPIO_clearPins(GPIO_Motor_PIN_Motor2_2_PORT, GPIO_Motor_PIN_Motor2_2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, compareValue,GPIO_PWM_Motor_C1_IDX);
	}
	else
	{
        compareValue = 3199 - 3199 * (-Speed/100.0);
		DL_GPIO_clearPins(GPIO_Motor_PIN_Motor2_1_PORT, GPIO_Motor_PIN_Motor2_1_PIN);
		DL_GPIO_setPins(GPIO_Motor_PIN_Motor2_2_PORT, GPIO_Motor_PIN_Motor2_2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, compareValue,GPIO_PWM_Motor_C1_IDX);
	}
}

void Motor_Two(int8_t Speed1,int8_t Speed2)
{
	Motor_Left(Speed1);
	Motor_Right(Speed2);
}

//以下为个性化内容

void Motor_Both(int8_t Speed)
{
	Motor_Left(Speed);
	Motor_Right(Speed);
}


float Speed_Limit(float Speed)
{
	if(Speed < 0 )
	{
		Speed = 0;
	}
	
	if(Speed > 100 )
	{
		Speed = 100;
	}
	
	return Speed;
}

float Motor_GetSpeed(void)
{
	return Motor_Set;
}
































