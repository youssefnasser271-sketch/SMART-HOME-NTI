/*
 * UART_Interface.h
 *
 * Created: 6/27/2023 1:33:26 PM
 *  Author: Rizk
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void USART_Init(u16 UART_Baud_Rate);

void USART_Transmit( u8 data );

u8 USART_Receive( );



#endif /* UART_INTERFACE_H_ */