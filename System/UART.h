#ifndef __UART_H__
#define __UART_H__

extern uint8_t UART0_RxData[100];
extern uint8_t UART1_RxData[100];
extern uint8_t UART2_RxData[100];
extern uint8_t UART3_RxData[100];

void UART_Init(UART_Regs * UART);
void UART_SendByte(UART_Regs * UART, uint8_t data);
void UART_SendString(UART_Regs * UART, uint8_t string[], int length);
uint8_t UART_GetFlag(UART_Regs * UART);

#endif