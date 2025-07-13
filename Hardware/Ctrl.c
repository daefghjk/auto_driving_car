#include "SYS.h"

extern uint8_t Mpu_En;
extern uint8_t Mode;
extern uint8_t TraceEn;

extern uint8_t Motor_En;//���ʹ��
extern float Motor_Set;//ǿ���趨�ٶ�
extern float Motor_Speed;//��ʵ�ٶ�

extern float pitch,roll,yaw;

const uint16_t Tim_Round = 50;
uint16_t Tim_Count = 0;



/*
��ʱ�жϣ�10ms����һ��
��ȡ�Ҷȴ���������
��ȡ6050
*/
void ctrl_INST_IRQHandler(void)
{
    Trace_Get();

    Situation_Get();//����־λ���ı䣬Ѳ�ߣ��򵼺���

	if(Motor_En == 1)//���ʹ�ܺ�ת������
	{
		Motor_Speed = Motor_GetSpeed();
		Motor_Speed = Speed_Limit(Motor_Speed);
		Motor_Both(Motor_Speed);//Speed);
	}
	else//��ת
	{
		Motor_Both(0);
	}
}

void ctrl_Encoder_INST_IRQHandler()
{
    // OLED_ShowNum(2, 3, Encoder_Left_Pop(), 4);
    // OLED_ShowNum(2, 11, Encoder_Right_Pop(), 4);
}










