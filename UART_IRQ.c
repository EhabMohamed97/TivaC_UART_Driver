 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_IRQ.c
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - UART Driver.
 *
 * Author: Ehab Mohamed
 ******************************************************************************/
#include "UART.h"
#include "UART_Regs.h"

uint8 flag = 0;
uint8 RecDataBuffer;

volatile STATIC uint32* UARTRegs_Ptr = (volatile uint32*)UART0_BASE_ADDRESS;
void UART0_Handler()
{
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_ICR_REG_OFFSET), 4);
   
   RecDataBuffer = *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_DATA_REG_OFFSET);
   
   flag = 1; 
}   /* End UART0_Handler() function */