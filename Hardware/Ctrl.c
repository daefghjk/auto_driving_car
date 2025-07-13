#include "SYS.h"

extern uint8_t Mpu_En;
extern uint8_t Mode;
extern uint8_t TraceEn;

extern uint8_t Motor_En;//电机使能
extern float Motor_Set;//强制设定速度
extern float Motor_Speed;//真实速度

extern float pitch,roll,yaw;

const uint16_t Tim_Round = 50;
uint16_t Tim_Count = 0;



/*
定时中断，10ms触发一次
读取灰度传感器数据
读取6050
*/
void ctrl_INST_IRQHandler(void)
{
    Trace_Get();

    Situation_Get();//检测标志位并改变，巡线（或导航）

	if(Motor_En == 1)//电机使能和转速设置
	{
		Motor_Speed = Motor_GetSpeed();
		Motor_Speed = Speed_Limit(Motor_Speed);
		Motor_Both(Motor_Speed);//Speed);
	}
	else//不转
	{
		Motor_Both(0);
	}
}

void ctrl_Encoder_INST_IRQHandler()
{
    // OLED_ShowNum(2, 3, Encoder_Left_Pop(), 4);
    // OLED_ShowNum(2, 11, Encoder_Right_Pop(), 4);
}










