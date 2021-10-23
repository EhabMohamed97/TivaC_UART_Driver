# TivaC_UART_Driver
It is my implementation of the UART Driver for TM4C123GH6PM Microcontroller employing AUTOSAR design.
I know that UART is considered as a complex driver according to AUTOSAR standard but I implemented it using
AUTOSAR workflow or design concept so it's very configurable, portable and optimized.
If you want to use it in your project you only have to configure it using the provided configuration files which are:
    1-UART_Cfg:UART Pre-Compile configuration in which you choose which UART is enabled and if you want to enable its Interrupt or not.
    2-UART_PBCfg:UART Pos-Build Configuration in which you choose the UART frame paramaters which are(Baud Rate, Parity Type and number of 
          stop bits).
                      Hope You like it :D
