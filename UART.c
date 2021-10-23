 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.h
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - UART Driver.
 *
 * Author: Ehab Mohamed
 ******************************************************************************/
#include "UART.h"
#include "UART_Regs.h"

void UART_Init(const UART_ConfigType *configPtr)
{
    volatile uint32 * UARTRegs_Ptr = NULL_PTR;   /* point to the required UART Registers base address */

    #if(UART0_ENABLE == STD_ON)
        UARTRegs_Ptr = (volatile uint32*)UART0_BASE_ADDRESS;

        SET_BIT(SYSCTL_RCGCUART_REG, 0);

        CLEAR_BIT( *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_CTL_REG_OFFSET), 0);

        switch(configPtr->UARTs[0]->BaudRate)
        {
            case 9600:
                *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_IBRD_REG_OFFSET) = 104;
                *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_FBRD_REG_OFFSET) = 11;
                break;

            case 115200:
                *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_IBRD_REG_OFFSET) = 8;
                *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_FBRD_REG_OFFSET) = 44;
                break;
        }   /* End switch(configPtr->UARTs[0]->BaudRate) */

        *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_LCRH_REG_OFFSET) |= (configPtr->UARTs[0]->DataSize << 5);

        *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_LCRH_REG_OFFSET) |= (configPtr->UARTs[0]->ParityType << 1);
        
        *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_LCRH_REG_OFFSET) |= (configPtr->UARTs[0]->NoStopBits << 3);

        *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_CC_REG_OFFSET) = 0;

        *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_CTL_REG_OFFSET) = (*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_CTL_REG_OFFSET) & 0xFCFE) | 0x0301;

		#if(UART0_INTERRUPT_ENABLE == STD_ON)
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_IM_REG_OFFSET), 4);
  			SET_BIT(*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_ICR_REG_OFFSET), 4);
  			NVIC_PRI1_REG = (NVIC_PRI1_REG & 0xFFFF1FFF) | (UART0_INT_PERIORETY << 21);
  			SET_BIT(NVIC_EN0_REG, 5);
		#endif
        
    #endif   /* End #if(UART0_ENABLE==STD_ON) */

}   /* End UART_Init() function */

#if(UART0_ENABLE == STD_ON)

	void UART0_SendByte(uint8 data)
	{
		volatile uint32 * UARTRegs_Ptr = (volatile uint32*)UART0_BASE_ADDRESS;   /* point to the required UART Registers base address */

		while(BIT_IS_SET(*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_FLAG_REG_OFFSET), 5) );
		*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_DATA_REG_OFFSET) = data;
	}   /* End UART0_SendByte */

	uint8 UART0_RecieveByte()
	{
		volatile uint32 * UARTRegs_Ptr = (volatile uint32*)UART0_BASE_ADDRESS;   /* point to the required UART Registers base address */
		uint8 data;
	
		while(BIT_IS_SET(*(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_FLAG_REG_OFFSET), 4));
	
		data = *(volatile uint32 *)((volatile uint8 *)UARTRegs_Ptr + UART_DATA_REG_OFFSET);
		return data;
	}   /* End UART0_RecieveByte()function */

	void UART0_SendString(uint8* string)
	{
		unsigned short i = 0;

		while(string[i] != '\0')
		{
			UART0_SendByte(string[i]);
			i++;
		}

		UART0_SendByte('\0');
	}

#endif   /* End #if(UART0_ENABLE==STD_ON) */