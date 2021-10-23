#include "Port.h"
#include "Dio.h"
#include "UART.h"

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")

/* Enable Exceptions ... This Macro enables Exceptions by clearing the F-bit in the FAULTMASK */
#define Enable_Exceptions()    __asm("CPSIE F")

/* Disable Exceptions ... This Macro disables Exceptions by setting the F-bit in the FAULTMASK */
#define Disable_Exceptions()   __asm("CPSID F") 

void main()
{
    uint8 data;

    Port_Init(&Port_Configuration);
    Dio_Init(&Dio_Configuration);
    UART_Init(&UART_Configuration);
  
    Enable_Interrupts();

    while(1)
    {
      UART0_SendString("Enter r ,g or b to turn the correspondig LED On\r\n");
      while(0 == flag);
      flag = 0;
      UART0_SendByte(RecDataBuffer);
      UART0_SendString("\r\n");
    
      switch(RecDataBuffer)
        {
            case 'r':
              Dio_WriteChannel(DioConf_RED_LED_CHANNEL_ID_INDEX, STD_HIGH);
              Dio_WriteChannel(DioConf_GREEN_LED_CHANNEL_ID_INDEX, STD_LOW);
              Dio_WriteChannel(DioConf_BLUE_LED_CHANNEL_ID_INDEX, STD_LOW);
              break;
            
            case 'g':
              Dio_WriteChannel(DioConf_GREEN_LED_CHANNEL_ID_INDEX, STD_HIGH);
              Dio_WriteChannel(DioConf_BLUE_LED_CHANNEL_ID_INDEX, STD_LOW);
              Dio_WriteChannel(DioConf_RED_LED_CHANNEL_ID_INDEX, STD_LOW);
              break;
            
            case 'b':
              Dio_WriteChannel(DioConf_BLUE_LED_CHANNEL_ID_INDEX, STD_HIGH);
              Dio_WriteChannel(DioConf_RED_LED_CHANNEL_ID_INDEX, STD_LOW);
              Dio_WriteChannel(DioConf_GREEN_LED_CHANNEL_ID_INDEX, STD_LOW);
              break;
        }
    }
 

}   /* End main()function*/

