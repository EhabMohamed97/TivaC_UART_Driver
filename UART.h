 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - UART Driver.
 *
 * Author: Ehab Mohamed
 ******************************************************************************/

#ifndef UART_H
#define UART_H

#include "UART_Cfg.h"
#include "Std_Types.h"
#include "Common_Macros.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Enumeration to define the character size */
typedef enum
{
	FIVE_BITS, SIX_BITS, SEVEN_BITS, EIGHT_BITS
}CharacterSize;

/* Enumeration to define the parity type */
typedef enum
{
	NO_PARITY, ODD, EVEN = 3
}Parity;

/* Enumeration to define the number of stop bits */
typedef enum
{
	ONE, TWO
}StopBits;

typedef enum
{
    POLLING, INTERRUPT
}UART_Mode;

typedef struct
{
	CharacterSize DataSize;
	Parity ParityType;
	StopBits NoStopBits;   /*Number of stop bits*/
	uint32 BaudRate;
}UART_Config;

/* Data Structure required for initializing the UART Driver */
typedef struct UART_ConfigType
{
	const UART_Config *UARTs[UART_CONFIGURED_NUMBER];
} UART_ConfigType;

extern const UART_ConfigType UART_Configuration;
extern uint8 flag;
extern uint8 RecDataBuffer;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void UART_Init(const UART_ConfigType*);

#if(UART0_ENABLE == STD_ON)
	void UART0_SendByte(uint8);
	uint8 UART0_RecieveByte();
	void UART0_SendString(uint8*);
	
#endif


#endif