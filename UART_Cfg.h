/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_Cfg.h
 *
 * Description: Pre Compile Configuration file for TM4C123GH6PM Microcontroller 
 *              UART Driver.
 *
 * Author: Ehab Mohamed
 ******************************************************************************/
#ifndef UART_CFG_H
#define UART_CFG_H

/* Number of the configured UARTs */
#define UART_CONFIGURED_NUMBER             (2U)

#define UART0_ENABLE                       (STD_ON)
#define UART1_ENABLE                       (STD_ON)
#define UART2_ENABLE                       (STD_OFF)
#define UART3_ENABLE                       (STD_OFF)
#define UART4_ENABLE                       (STD_OFF)
#define UART5_ENABLE                       (STD_OFF)
#define UART6_ENABLE                       (STD_OFF)
#define UART7_ENABLE                       (STD_OFF)

#define UART0_INTERRUPT_ENABLE   (STD_ON)
#define UART0_INT_PERIORETY   (1U)


#endif