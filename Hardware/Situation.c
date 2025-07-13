#include "SYS.h"

extern uint8_t Mode;//模式

extern float Servo_Angle_TurnMin;//每次变化的角度
extern float Servo_Angle;
extern float Servo_Angle_Init;//舵机角度

extern uint8_t Motor_En;//电机使能

extern uint16_t Trace_Num_Now;//11111
extern uint16_t Trace_Num_Ago[10];

uint8_t TraceEn = 0; //开关循迹 0:关 1:开
uint8_t KeyPointCount = 0; //已达到关键点的数量
uint8_t MaxCount = -1; //最大关键点数量
uint8_t KeyPointEn = 0;  //是否开始检测出黑线，0是不检测，1是检测

extern float pitch,roll,yaw;
extern float Yaw_Init;
extern float yaw_Error;
float Yaw_Set = 0;//设定要走的方向（0，180，）
float yaw_Error_Turn = 5.8;

float Angle_BAC_Init = 36.6;//对角值ac初始值，理想38.7
float Angle_BAC = 0;//对角值ac实时值
float Angle_BAC_Turn = 1.8;//对角值ac的变化，每次开始相应导航就加它
float Angle_BAC_Random[4] = {0,2.8,1.4,0};//

float Angle_ABD_Init = 39.0;//对角值bd初始值，理想38.7
float Angle_ABD = 0;//对角值bd实时值
float Angle_ABD_Turn = -0.2;//对角值ac的变化，每次开始相应导航就加它
float Angle_ABD_Random[4] = {0,0,0.0,0};//

float Servo_MaxAngle = 24;

//通过灰度的值，判断并操作舵机的角度，
void Situation_Get(void)
{
    if(Motor_En == 0)return;

    KeyPointCheck();
    if (TraceEn)//正常巡线
	{
        Sit_Blcak_Move();
	}
    else //白区按照要求角度走
    {
        Sit_Write_Move();
    }
	
}

//检测标志点位，并改变标志位
void KeyPointCheck(void)
{
    if(Sit_Blcak_Judge() || Sit_Write_Judge())//换区
    {
        LightAndBeep();//声光

        KeyPointCount++;//看到的标志点数量加一
        Sit_Stop();//看看停不停

        //复位三秒定时器（不检测标志点）
        Sit_Tim_Circle_Reset();
        
        if(Sit_Blcak_Judge())//进入黑区
        {
            Sit_Blcak_Init();
        }
        else//进入白区
        {
            Sit_Write_Init();
        }
    }
    
}


//检测是否达到最大数量标志位，是则停
void Sit_Stop(void)
{
    if (KeyPointCount >= MaxCount)
    {
        Motor_En = 0;
        TraceEn = 0;
    }
}


/*********************************************************************************/
//下方黑白区，判断，初始化，巡线（或导航）

uint8_t Sit_Blcak_Judge(void)
{
    if (TraceEn == 0) //在空白区
    {
        if (Trace_Num_Now != 0 && Trace_Num_Ago[3] != 0 && Trace_Num_Ago[5] != 0)//在空白区，遇到黑线
        {
            return 1;
        }
    }
    return 0;
}

uint8_t Sit_Write_Judge(void)
{
    if (TraceEn == 1) //在黑线区
    {
        if (KeyPointEn && Trace_Num_Now == 0 && Trace_Num_Ago[3] == 0 && Trace_Num_Ago[5] == 0) //在黑线区，可检测，出黑线
        {
            return 1;
        }
    }
    return 0;
}


//进入黑区的初始化
void Sit_Blcak_Init(void)
{
    TraceEn = 1;//黑线区,循迹开启
}

//进入白区的初始化
void Sit_Write_Init(void)
{
    Yaw_Set_Change();//设定空白区的角度

    TraceEn = 0;//白线区,不循迹
}

//黑区动作（巡线）要改
void Sit_Blcak_Move(void)
{
    if (Trace_Num_Now & 0x01)                  //0000 0001 极右
    {
        Servo_SetAngle(Servo_Angle_Init + Servo_MaxAngle);
        return;
    }
    
    if (Trace_Num_Now & 0x80)                  //1000 0000 极左
    {
        Servo_SetAngle(Servo_Angle_Init - Servo_MaxAngle);
        return;
    }
    if (Trace_Num_Now & 0x02)                  //0000 0010 右
    {
        Servo_SetAngle(Servo_Angle_Init + Servo_MaxAngle);
        return;
    }

    if (Trace_Num_Now & 0x40)                  //0100 0000 左
    {
        Servo_SetAngle(Servo_Angle_Init - Servo_MaxAngle);
        return;
    }

    if (Trace_Num_Now & 0x04)                  //0000 0100 微右
    {
        Servo_SetAngle(Servo_Angle_Init + 14);
        return;
    }

    if (Trace_Num_Now & 0x20)                  //0010 0000 微左
    {
        Servo_SetAngle(Servo_Angle_Init - 14);
        return;
    }

    if (Trace_Num_Now & 0x08)                  //0000 1000 中右
    {
        Servo_SetAngle(Servo_Angle_Init);
        return;
    }

    if (Trace_Num_Now & 0x10)                  //0001 0000 中左
    {
        Servo_SetAngle(Servo_Angle_Init);
        return;
    }
}

//白区动作（按照特定角度要求pid行走）
void Sit_Write_Move(void)
{
    float dyaw = Dyaw_Get();//正则向左，负则向右
    if(dyaw > 24)dyaw = 24;
    if(dyaw < -24)dyaw = -24;
    Servo_SetAngle(Servo_Angle_Init + dyaw);
}

/*********************************************************************************/
//下方6050区

//更新mpu6050数据
void Mpu_Get(void)
{
    while ( mpu_dmp_get_data(&pitch,&roll,&yaw) != 0 );
}

//显示偏转角,-180到180,yawset在xx中给出
float Dyaw_Get(void)
{
    float Dyaw =yaw - Yaw_Set;
    if(Dyaw > 180)Dyaw -= 360;
    if(Dyaw < -180)Dyaw += 360;
    return Dyaw;
}

//通过mode和KeyPoint的值设定导航角，在白区初始化中完成
void Yaw_Set_Change(void)
{
    if(Mode == 0 && KeyPointCount %4 == 0)//模式2从c出
    {
        Yaw_Set = 0;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 0 && KeyPointCount %4 == 2)//模式2从c出
    {
        Yaw_Set = 180;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 2 && KeyPointCount == 2)//模式2从c出
    {
        Yaw_Set = 180;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 3 && KeyPointCount == 0)//模式3从a出
    {
        Yaw_Set = -Angle_BAC;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 3 && KeyPointCount == 2)//模式3从b出
    {
        Yaw_Set = Angle_ABD - 180;
        yaw_Error += yaw_Error_Turn;
    }
    if(Mode == 4 && KeyPointCount % 4 == 0)//模式4从a出
    {
        Angle_BAC += Angle_BAC_Random[KeyPointCount / 4];//ex:第二圈从a出发的时候kpc是4，整除正好是1
        Yaw_Set = -Angle_BAC;
        yaw_Error -= yaw_Error_Turn;
    }
    if(Mode == 4 && KeyPointCount % 4 == 2)//模式4从b出
    {
        Angle_ABD += Angle_ABD_Random[KeyPointCount / 4];
        Yaw_Set = Angle_ABD - 180;
        yaw_Error += yaw_Error_Turn;
    }

}

/*********************************************************************************/
//下方3s不检测标志点 定时器区

void circle_INST_IRQHandler(void)
{
    KeyPointEn = 1;
}

//三秒定时器
void Sit_Tim_Circle_Open(void)
{
    KeyPointEn = 0;

    DL_TimerA_setTimerCount(circle_INST, 0);
    NVIC_EnableIRQ(circle_INST_INT_IRQN);
    DL_TimerA_startCounter(circle_INST);
}

//三秒定时器关闭
void Sit_Tim_Circle_Close(void)
{
    KeyPointEn = 1;

    DL_TimerA_stopCounter(circle_INST);
    NVIC_DisableIRQ(circle_INST_INT_IRQN);
    DL_TimerA_setTimerCount(circle_INST, 0);
}

void Sit_Tim_Circle_Reset(void)
{
    Sit_Tim_Circle_Close();
    Sit_Tim_Circle_Open();
}