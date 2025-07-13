#ifndef __SITUATION_H
#define __SITUATION_H

// void PoseRevise(float Turn_Angle); //没写完

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



extern uint8_t TraceEn; //开关循迹 0:关 1:开
extern uint8_t KeyPointCount; //已达到关键点的数量
extern uint8_t MaxCount; //最大关键点数量
extern uint8_t PoseReviseEn; //开关姿态修正






#endif
