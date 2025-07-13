#ifndef __MOTOOR_H
#define __MOTOOR_H

void Motor_Left(int8_t Speed);
void Motor_Right(int8_t Speed);
void Motor_Both(int8_t Speed);
void Motor_Two(int8_t Speed1,int8_t Speed2);
float Speed_Limit(float Speed);
float Motor_GetSpeed(void);

#endif
