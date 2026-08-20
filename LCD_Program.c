/*
 * LCD_Program.c
 *
 * Created: 7/22/2023 6:51:19 PM
 *  Author: Rizk
 */ 
#define F_CPU 8000000UL // Set this to match your Proteus clock speed

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdio.h>      // Added for sprintf
#include <util/delay.h>
#include "DIO_Interface.h"

#include "LCD_Private.h"
#include "LCD_Interface.h"
#include "LCD_cnf.h"

static void Enable_Pulse(void);

void LCD_voidInit(void)
{
	DIO_voidSetPinDirection(RS_PORT,RS_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(E_PORT,E_PIN,PIN_OUTPUT);
	
	DIO_voidSetPinDirection(D4_PORT,D4_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D5_PORT,D5_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D6_PORT,D6_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D7_PORT,D7_PIN,PIN_OUTPUT);
	
	

	_delay_ms(15);

	Lcd_SendCmd(0x03);
	_delay_ms(5);
	Lcd_SendCmd(0x03);
	_delay_us(100);
	Lcd_SendCmd(0x03);
	Lcd_SendCmd(0x02);
	Lcd_SendCmd(0x28);
	Lcd_SendCmd(0x0C);
	Lcd_Goto_Row_Column(0, 0);
	Lcd_SendCmd(0x01);
	
	_delay_ms(25);

}

void Lcd_SendCmd(u8 Command)

{

	/* command mode */
	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_LOW);

  
  /*      Send Command         */
		DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(Command,7));
		DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(Command,6));
		DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(Command,5));
		DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(Command,4));

		
		
		/*   Latching   */
		Enable_Pulse();
		
		DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(Command,3));
		DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(Command,2));
		DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(Command,1));
		DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(Command,0));
  
  /*   Latching   */
  Enable_Pulse();	    
  

}

void LCD_voidSenddata(u8 data)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_HIGH);

	
	/*      Send Command         */

		DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(data,4));
		DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(data,5));
		DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(data,6));
		DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(data,7));


	
	/*   Latching   */
	Enable_Pulse();
	



		DIO_voidSetPinValue(D4_PORT,D4_PIN,GET_BIT(data,0));
		DIO_voidSetPinValue(D5_PORT,D5_PIN,GET_BIT(data,1));
		DIO_voidSetPinValue(D6_PORT,D6_PIN,GET_BIT(data,2));
		DIO_voidSetPinValue(D7_PORT,D7_PIN,GET_BIT(data,3));					
	/*   Latching   */
	Enable_Pulse();
	
	
}



static void Enable_Pulse(void)
{
		DIO_voidSetPinValue(E_PORT,E_PIN,PIN_HIGH);
		_delay_us(1);
		DIO_voidSetPinValue(E_PORT,E_PIN,PIN_LOW);
		_delay_ms(2);
}



void Lcd_DisplayStr(u8* str)
{
	while (*str != '\0')
	{
		Lcd_DisplayChr(*str);
		str++;
	}
}

void Lcd_Goto_Row_Column(u8 row, u8 col)
{
	switch (row)
	{
		case 0:
		Lcd_SendCmd(0x80 + col);
		break;
		case 1:
		Lcd_SendCmd(0xC0 + col);
		break;
		case 2:
		Lcd_SendCmd(0x94 + col); // Address for Row 3
		break;
		case 3:
		Lcd_SendCmd(0xD4 + col); // Address for Row 4
		break;
	}
}

void Lcd_DisplayChr(u8 chr)
{
	LCD_voidSenddata(chr);
}


void HLCD_voidClearLCD(void)
{
	/*send Display clear instruction*/
	Lcd_SendCmd(_LCD_CLEAR);
	
	}/*end of HLCD_voidClearLCD()*/
	
	
	 void HLCD_voidReturnHome(void)
	 {
		 /*send Return home instruction*/
		 Lcd_SendCmd(_LCD_RETURN_HOME);
		 
	 }
	 
	 
	 
	 
	 void Lcd_Displaynum(u16 number)
	 {
		 char str[7];
		 sprintf(str, "%d", number);
		Lcd_DisplayStr((u8*)str);		 
		// Lcd_DisplayChr(number/10000);
		// Lcd_DisplayChr(number%10000/1000);
		// Lcd_DisplayChr(number%10000%1000/100);
		// Lcd_DisplayChr(number%10000%1000%100/10);
		// Lcd_DisplayChr(number%10000%1000%100%10);
		 
		 
		 
	 }