#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Private.h"
#include "UART_Configh.h"
#include "UART_Interface.h"

#define F_CPU 8000000UL


void USART_Init(u16 UART_BAUDRATE)
{
	u8 LOC_Var = 0;

	u16 BAUD_PRESCALE =
	((F_CPU / (UART_BAUDRATE * 16UL)) - 1);


	/* Normal Speed */
	CLR_BIT(UCSRA, 1);


	/* Set Baud Rate */
	UBRRH = (u8)(BAUD_PRESCALE >> 8);
	UBRRL = (u8)BAUD_PRESCALE;


	/* Enable TX and RX */
	SET_BIT(UCSRB, 3);   // TXEN
	SET_BIT(UCSRB, 4);   // RXEN


	/* Asynchronous Mode */
	CLR_BIT(LOC_Var, 6);


	/* No Parity */
	CLR_BIT(LOC_Var, 4);
	CLR_BIT(LOC_Var, 5);


	/* 1 Stop Bit */
	CLR_BIT(LOC_Var, 3);


	/* 8-bit Data */
	SET_BIT(LOC_Var, 1); // UCSZ0
	SET_BIT(LOC_Var, 2); // UCSZ1

	/* UCSZ2 = 0 */
	CLR_BIT(UCSRB, 2);


	/* Select UCSRC */
	SET_BIT(LOC_Var, 7);

	UCSRC = LOC_Var;
}


void USART_Transmit(u8 data)
{
	/* Wait until transmit buffer is empty */
	while(GET_BIT(UCSRA, 5) == 0);

	/* Send data */
	UDR = data;
}


u8 USART_Receive(void)
{
	
	if (GET_BIT(UCSRA, 7) == 0)
	{
		return 0;
	}

	return UDR;
}