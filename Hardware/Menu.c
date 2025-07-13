#include "SYS.h"

extern uint8_t Mode;//模式
extern uint8_t Mode_Set;//模式设置

extern int16_t Motor_Speed;//速度
extern uint8_t Motor_En;

extern uint8_t Mpu_En;
extern float Yaw_Init;
extern float Dyaw;
extern float pitch,roll,yaw;
extern float Yaw_Set;
extern float yaw_Error_Turn;
extern float yaw_Error;

extern float Servo_Angle_Init;
extern float Servo_MaxAngle;

extern float Angle_BAC_Init;
extern float Angle_BAC;
extern float Angle_BAC_Turn;
extern float Angle_BAC_Random[4];

extern float Angle_ABD_Init;
extern float Angle_ABD;
extern float Angle_ABD_Turn;
extern float Angle_ABD_Random[4];

extern float Motor_Set;

extern uint8_t KeyPointCount;

//页数
uint8_t Page_Num = 1;
uint8_t Cursor = 1;
void Menu_Show(void)
{
    //检测按键并改变
    uint8_t  Key_Num;
    Key_Num = Key_GetNum();
    if (Page_Num == 1)
    {
        Menu_P1_Var();//显示变量
        Menu_P1_Key(Key_Num);
    }
    else if (Page_Num == 2)
    {
        Menu_P2_Var();//显示变量
        Menu_P2_Key(Key_Num);
        
    }
    else if (Page_Num == 3)
    {
        Menu_P3_Var();//显示变量
        Menu_P3_Key(Key_Num);
    }
    else if (Page_Num == 4)
    {
        Menu_P4_Var();//显示变量
        Menu_P4_Key(Key_Num);
    }
        
}

//显示参量名称
void Menu_Init(void)
{
	Menu_P1_Init();
}

void Menu_P1_Init(void)
{
    OLED_Clear();
    OLED_ShowString(1,1,"Mode:   Set: ");
    if(Mpu_En)
    {
      OLED_ShowString(2, 1, "yaw:  ");
    }
    else 
    {
	    OLED_ShowString(2,1,"DMP isn't ready");
    }
    OLED_ShowString(3, 1, "Area:     ");
    OLED_ShowString(4, 1, "Circle:   ");
  
}

void Menu_P2_Init(void)
{
    OLED_Clear();
    OLED_ShowString(1, 1, "yawErTurn:");
    OLED_ShowString(2, 1, "SerMaxAng:");
    OLED_ShowString(3, 1, "Ang_BAC:");
    OLED_ShowString(4, 1, "Ang_ABD:");
    Cursor = 1;
    OLED_ShowChar(Cursor, 16, '<');
}

void Menu_P3_Init(void)
{
    OLED_Clear();
    OLED_ShowString(1, 1, "BAC_Turn:");
    OLED_ShowString(2, 1, "ABD_Turn:");
    OLED_ShowString(3, 1, "BAC_Ran2:");//第二圈bac调整角
    OLED_ShowString(4, 1, "ABD_Ran2:");
    Cursor = 1;
    OLED_ShowChar(Cursor, 16, '<');
}

void Menu_P4_Init(void)
{
    OLED_Clear();
    OLED_ShowString(1, 1, "BAC_Ran3:");
    OLED_ShowString(2, 1, "ABD_Ran3:");
    OLED_ShowString(3, 1, "BAC_Ran4:");
    OLED_ShowString(4, 1, "MotSpeed:");
    Cursor = 1;
    OLED_ShowChar(Cursor, 16, '<');
}



void Menu_P1_Var(void)
{
    OLED_ShowNum(1,6,Mode,1);
    OLED_ShowNum(1,13,Mode_Set,1);
    if(Mpu_En)
        OLED_ShowSignedNum(2, 6, yaw, 4);
    if(TraceEn == 0)OLED_ShowString(3,6,"WRITE");
    if(TraceEn == 1)OLED_ShowString(3,6,"BLCAK");
    OLED_ShowNum(4, 8, KeyPointCount / 4 + 1, 1);
}

void Menu_P2_Var(void)
{
    OLED_ShowFloat(1, 11, yaw_Error_Turn, 1, 1);
    OLED_ShowFloat(2, 11, Servo_MaxAngle, 2, 1);
    OLED_ShowFloat(3, 10, Angle_BAC_Init, 2, 1);
    OLED_ShowFloat(4, 10, Angle_ABD_Init, 2, 1);
}

void Menu_P3_Var(void)
{
    OLED_ShowFloat(1, 12, Angle_BAC_Turn, 1, 1);
    OLED_ShowFloat(2, 12, Angle_ABD_Turn, 1, 1);
    OLED_ShowFloat(3, 12, Angle_BAC_Random[1], 1, 1);//第二圈从A出发
    OLED_ShowFloat(4, 12, Angle_ABD_Random[1], 1, 1);
}

void Menu_P4_Var(void)
{
    OLED_ShowFloat(1, 12, Angle_BAC_Random[2], 1, 1);
    OLED_ShowFloat(2, 12, Angle_ABD_Random[2], 1, 1);
    OLED_ShowFloat(3, 12, Angle_BAC_Random[3], 1, 1);
    OLED_ShowNum(4, 12, Motor_Set, 3);
}



void Menu_P1_Key(uint8_t  Key_Num )
{
    if(Key_Num == 1)//改变模式预备值
    {
        Mode_Set++;
        if(Mode_Set == 6)
        {
            Mode_Set = 1;
        }
    }
    
    if(Key_Num == 2)//载入模式预备值，并进行模式初始化  //初始化6050，后续将在主程序中更新
    {
        Mode = Mode_Set;

        TraceEn = 0; //白区 导航模式
        Yaw_Set = 0;//导航角为0

        KeyPointCount = 0; //已到关键点数量清零

        if(Mode == 1)
        {
            MaxCount = 0;
            Yaw_Set = 0;
        }
        if(Mode == 2)
        {
            MaxCount = 4;
            Yaw_Set = 0;
        }
        if(Mode == 3)
        {
            MaxCount = 4;
            Yaw_Set = -Angle_BAC_Init;
        }
        if(Mode == 4)
        {
            MaxCount = 16;
            Yaw_Set = -Angle_BAC_Init;
        }
        if(Mode == 5)
        {
            MaxCount = -1;
            Yaw_Set = -Angle_BAC_Init;
        }

        //初始化
        board_init();
        Servo_SetAngle(Servo_Angle_Init);
        MPU6050_Init();

        OLED_ShowString(2, 1, "DMP loading... ");
        while( mpu_dmp_init() )
        {
            delay_ms(200);
        }

        //读数据
        while ( mpu_dmp_get_data(&pitch,&roll,&yaw) != 0 );//读不到就卡在这/
        Yaw_Init = yaw ;
        yaw_Error = 0;
        Mpu_En = 1;
        OLED_ShowString(2, 1, "               ");
        OLED_ShowString(2, 1, "DMP OK");
        LightAndBeep();
        delay_ms(500);
        OLED_ShowString(2, 1, "yaw:  ");

        //角度初始化
        Angle_BAC = Angle_BAC_Init;
        Angle_ABD = Angle_ABD_Init;
    }
    
    if(Key_Num == 3)//跑！
    {
        Motor_En = !Motor_En;
    }

    if(Key_Num == 4)
    {
        Page_Num = 2;
        Menu_P2_Init();
    }
}

void Menu_P2_Key(uint8_t  Key_Num )
{
    if (Key_Num == 1)
    {
        Cursor++;
        if (Cursor > 4)
            Cursor = 1;
    
        for (uint8_t i = 1; i <= 4; ++i)
        OLED_ShowChar(i, 16, ' ');
        OLED_ShowChar(Cursor, 16, '<');
    }

    if (Key_Num == 2)
    {
        if (Cursor == 1)
            yaw_Error_Turn -= 0.1;
        else if (Cursor == 2)
            Servo_MaxAngle -= 0.2;
        else if (Cursor == 3)
            Angle_BAC_Init -= 0.2;
        else if (Cursor == 4)
            Angle_ABD_Init -= 0.2;
    }

    if (Key_Num == 3)
    {
        if (Cursor == 1)
            yaw_Error_Turn += 0.1;
        else if (Cursor == 2)
            Servo_MaxAngle += 0.2;
        else if (Cursor == 3)
            Angle_BAC_Init += 0.2;
        else if (Cursor == 4)
            Angle_ABD_Init += 0.2;
    }

    if (Key_Num == 4)
    {
        Page_Num = 3;
        Menu_P3_Init();
    }
}

void Menu_P3_Key(uint8_t  Key_Num )
{
    if (Key_Num == 1)
    {
        Cursor++;
        if (Cursor > 4)
            Cursor = 1;
    
        for (uint8_t i = 1; i <= 4; ++i)
        OLED_ShowChar(i, 16, ' ');
        OLED_ShowChar(Cursor, 16, '<');
    }

    if (Key_Num == 2)
    {
        if (Cursor == 1)
            Angle_BAC_Turn -= 0.2;
        else if (Cursor == 2)
            Angle_ABD_Turn -= 0.2;
        else if (Cursor == 3)
            Angle_BAC_Random[1] -= 0.2;
        else if (Cursor == 4)
            Angle_ABD_Random[1] -= 0.2;
    }

    if (Key_Num == 3)
    {
        if (Cursor == 1)
            Angle_BAC_Turn += 0.2;
        else if (Cursor == 2)
            Angle_ABD_Turn += 0.2;
        else if (Cursor == 3)
            Angle_BAC_Random[1] += 0.2;
        else if (Cursor == 4)
            Angle_ABD_Random[1] += 0.2;
    }

    if (Key_Num == 4)
    {
        Page_Num = 4;
        Menu_P4_Init();
    }
}

void Menu_P4_Key(uint8_t  Key_Num )
{
    if (Key_Num == 1)
    {
        Cursor++;
        if (Cursor > 4)
            Cursor = 1;
    
        for (uint8_t i = 1; i <= 4; ++i)
        OLED_ShowChar(i, 16, ' ');
        OLED_ShowChar(Cursor, 16, '<');
    }

    if (Key_Num == 2)
    {
        if (Cursor == 1)
            Angle_BAC_Random[2] -= 0.2;
        else if (Cursor == 2)
            Angle_ABD_Random[2] -= 0.2;
        else if (Cursor == 3)
            Angle_BAC_Random[3] -= 0.2;
        else if (Cursor == 4)
                Motor_Set -= 5;
    }

    if (Key_Num == 3)
    {
        if (Cursor == 1)
            Angle_BAC_Random[2] += 0.2;
        else if (Cursor == 2)
            Angle_ABD_Random[2] += 0.2;
        else if (Cursor == 3)
            Angle_BAC_Random[3] += 0.2;
        else if (Cursor == 4)
             Motor_Set += 5;
    }

    if (Key_Num == 4)
    {
        Page_Num = 1;
        Menu_P1_Init();
    }
}