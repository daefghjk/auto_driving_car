#include <ti/driverlib/driverlib.h>
#include "UART.h"
#include "ti/devices/msp/m0p/mspm0g350x.h"
#include "stdio.h"
#include "string.h"

uint8_t UART0_RxData[100] = "\0";
uint8_t UART1_RxData[100] = "\0";
uint8_t UART2_RxData[100] = "\0";
uint8_t UART3_RxData[100] = "\0";
uint8_t UART0_Flag = 0;
uint8_t UART1_Flag = 0;
uint8_t UART2_Flag = 0;
uint8_t UART3_Flag = 0;

void UART_Init(UART_Regs * UART)
{
    if (UART == UART0)
    {
        NVIC_ClearPendingIRQ(UART0_INT_IRQn);
        NVIC_EnableIRQ(UART0_INT_IRQn);
    }
    else if (UART == UART1) 
    {
        NVIC_ClearPendingIRQ(UART1_INT_IRQn);
        NVIC_EnableIRQ(UART1_INT_IRQn);
    }
    else if (UART == UART2) 
    {
        NVIC_ClearPendingIRQ(UART2_INT_IRQn);
        NVIC_EnableIRQ(UART2_INT_IRQn);
    }
    else if (UART == UART3) 
    {
        NVIC_ClearPendingIRQ(UART3_INT_IRQn);
        NVIC_EnableIRQ(UART3_INT_IRQn);
    }
}

void UART_SendByte(UART_Regs * UART, uint8_t data)
{
    DL_UART_Main_transmitDataBlocking(UART, data);
}

void UART_SendString(UART_Regs * UART, uint8_t string[], int length) //length为-1时发送全字符串
{
    if (length == -1)
        for (uint8_t i = 0; string[i] != '\0'; ++i)
            UART_SendByte(UART, string[i]);
    else
        for (uint8_t i = 0; i < length && string[i] != '\0'; ++i)
            UART_SendByte(UART, string[i]);
}

uint8_t UART_GetFlag(UART_Regs * UART) //调用后Flag置0
{
    if (UART == UART0)
    {
        if (UART0_Flag)
        {
            UART0_Flag = 0;
            return 1;
        }
        return 0;
    }
    else if (UART == UART1)
    {
        if (UART1_Flag)
        {
            UART1_Flag = 0;
            return 1;
        }
        return 0;
    }
    else if (UART == UART2)
    {
        if (UART2_Flag)
        {
            UART2_Flag = 0;
            return 1;
        }
        return 0;
    }
    else if (UART == UART3)
    {
        if (UART3_Flag)
        {
            UART3_Flag = 0;
            return 1;
        }
        return 0;
    }
    return  0;
}

void UART0_IRQHandler(void)
{
    static uint8_t length = 0, state = 0;
    uint8_t RxData = DL_UART_Main_receiveData(UART0);
    switch (state)
    {
    case 0:
        if (RxData == '@')
        {
            state = 1;
            UART0_Flag = 0;
            length = 0;
        }
        break;
    case 1:
        if (RxData == '\r')
        {
            state = 2;
        }
        else
        {
            UART0_RxData[length] = RxData;
            length++;
        }
        break;
    case 2:
        if (RxData == '\n')
        {
            state = 0;
            UART0_RxData[length] = '\0';
            UART0_Flag = 1;
        }
        break;
    }
}

void UART1_IRQHandler(void)
{
    static uint8_t length = 0, state = 0;
    uint8_t RxData = DL_UART_Main_receiveData(UART1);
    switch (state)
    {
    case 0:
        if (RxData == '@')
        {
            state = 1;
            UART1_Flag = 0;
            length = 0;
        }
        break;
    case 1:
        if (RxData == '\r')
        {
            state = 2;
        }
        else
        {
            UART1_RxData[length] = RxData;
            length++;
        }
        break;
    case 2:
        if (RxData == '\n')
        {
            state = 0;
            UART1_RxData[length] = '\0';
            UART1_Flag = 1;
        }
        break;
    }
    NVIC_ClearPendingIRQ(UART1_INT_IRQn);
}

void UART2_IRQHandler(void)
{
    static uint8_t length = 0, state = 0;
    uint8_t RxData = DL_UART_Main_receiveData(UART2);
    switch (state)
    {
    case 0:
        if (RxData == '@')
        {
            state = 1;
            UART2_Flag = 0;
            length = 0;
        }
        break;
    case 1:
        if (RxData == '\r')
        {
            state = 2;
        }
        else
        {
            UART2_RxData[length] = RxData;
            length++;
        }
        break;
    case 2:
        if (RxData == '\n')
        {
            state = 0;
            UART2_RxData[length] = '\0';
            UART2_Flag = 1;
        }
        break;
    }
    NVIC_ClearPendingIRQ(UART2_INT_IRQn);
}

void UART3_IRQHandler(void)
{
    static uint8_t length = 0, state = 0;
    uint8_t RxData = DL_UART_Main_receiveData(UART3);
    switch (state)
    {
    case 0:
        if (RxData == '@')
        {
            state = 1;
            UART3_Flag = 0;
            length = 0;
        }
        break;
    case 1:
        if (RxData == '\r')
        {
            state = 2;
        }
        else
        {
            UART3_RxData[length] = RxData;
            length++;
        }
        break;
    case 2:
        if (RxData == '\n')
        {
            state = 0;
            UART3_RxData[length] = '\0';
            UART3_Flag = 1;
        }
        break;
    }
    NVIC_ClearPendingIRQ(UART3_INT_IRQn);
}

int fputc(int c, FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART0, c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        DL_UART_Main_transmitDataBlocking(UART0, s[i]);
    }
    return len;
}

int puts(const char *_ptr)
{
    int count = fputs(_ptr, stdout);
    count += fputs("\n", stdout);
    return count;
}
