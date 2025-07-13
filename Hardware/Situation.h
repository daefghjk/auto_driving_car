#ifndef __SITUATION_H
#define __SITUATION_H

// void PoseRevise(float Turn_Angle); //ûд��

void KeyPointCheck(void);
void Situation_Get(void);

void Yaw_Set_Change(void);

void Sit_Stop(void);

uint8_t Sit_Blcak_Judge(void);
uint8_t Sit_Write_Judge(void);

void Sit_Blcak_Init(void);
void Sit_Write_Init(void);

void Sit_Blcak_Move(void);
void Sit_Write_Move(void);

void Mpu_Get(void);
float Dyaw_Get(void);

void Sit_Tim_Circle_Open(void);
void Sit_Tim_Circle_Close(void);
void Sit_Tim_Circle_Reset(void);



extern uint8_t TraceEn; //����ѭ�� 0:�� 1:��
extern uint8_t KeyPointCount; //�Ѵﵽ�ؼ��������
extern uint8_t MaxCount; //���ؼ�������
extern uint8_t PoseReviseEn; //������̬����






#endif
