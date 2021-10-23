 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_PBCfg.h
 *
 * Description: Post Build Configuration file for TM4C123GH6PM Microcontroller  
 *              UART Driver.
 *
 * Author: Ehab Mohamed
 ******************************************************************************/
#include "UART.h"

/* Symbolic names for major(most used) configurations */
typedef enum
{
  UART_DEFAULT_CONFIG, EIGHT_9600_INT, EIGHT_115200_POLLING, EIGHT_115200_INT
}MajorUARTConfig;

/* Array of structures contians most used  pin configurations*/
STATIC const UART_Config UARTsConfigSettings[] = { {EIGHT_BITS, NO_PARITY, ONE, 9600},
                                                   {EIGHT_BITS, NO_PARITY, ONE, 9600},
                                                   {EIGHT_BITS, NO_PARITY, ONE, 115200},
                                                   {EIGHT_BITS, NO_PARITY, ONE, 115200}
                                                 };

/* PB structure used with UART_Init API */
const UART_ConfigType UART_Configuration = { &UARTsConfigSettings[UART_DEFAULT_CONFIG],    /* UART 0 */
                                             &UARTsConfigSettings[EIGHT_9600_INT]        /* UART 1 */
                                             //&UARTsConfigSettings[EIGHT_115200_POLLING],   /* UART 2 */
                                             //&UARTsConfigSettings[UART_DEFAULT_CONFIG],    /* UART 3 */ 
                                             //&UARTsConfigSettings[UART_DEFAULT_CONFIG],    /* UART 4 */ 
                                             //&UARTsConfigSettings[UART_DEFAULT_CONFIG],    /* UART 5 */ 
                                             //&UARTsConfigSettings[UART_DEFAULT_CONFIG],    /* UART 6 */
                                             //&UARTsConfigSettings[UART_DEFAULT_CONFIG],    /* UART 6 */                                               
				                                   };