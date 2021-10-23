 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - UART Driver 
 *              Registers
 *
 * Author: Ehab Mohamed
 ******************************************************************************/

#ifndef UART_REGS_H
#define UART_REGS_H

#include "Std_Types.h"

/*******************************************************************************
 *                              UART_Regs Definitions                          *
 *******************************************************************************/

/* UART Registers base addresses */
#define UART0_BASE_ADDRESS           0x4000C000
#define UART1_BASE_ADDRESS           0x4000D000
#define UART2_BASE_ADDRESS           0x4000E000
#define UART3_BASE_ADDRESS           0x4000F000
#define UART4_BASE_ADDRESS           0x40010000
#define UART5_BASE_ADDRESS           0x40011000
#define UART6_BASE_ADDRESS           0x40012000
#define UART7_BASE_ADDRESS           0x40013000

/* UART Registers offset addresses */
#define UART_DATA_REG_OFFSET              0x000
#define UART_FLAG_REG_OFFSET              0x018
#define UART_IBRD_REG_OFFSET              0x024
#define UART_FBRD_REG_OFFSET              0x028
#define UART_LCRH_REG_OFFSET              0x02C
#define UART_CTL_REG_OFFSET               0x030
#define UART_IM_REG_OFFSET                0x038
#define UART_ICR_REG_OFFSET                0x044
#define UART_CC_REG_OFFSET                0xFC8
#define UART_UARTRIS_REG_OFFSET           0x03C

#define SYSCTL_REGCGC2_REG    (*((volatile uint32 *)0x400FE108))
#define SYSCTL_RCGCUART_REG   (*((volatile uint32 *)0x400FE618))

#define NVIC_PRI1_REG             (*((volatile unsigned long *)0xE000E404))
#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))

#endif /* UART_REGS_H */