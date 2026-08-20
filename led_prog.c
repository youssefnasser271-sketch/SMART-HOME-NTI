// 1. THIS MUST BE FIRST. It defines what a 'u8' is.
#include "STD_Types.h"

// 2. Now the compiler can safely read the rest of the files
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "led_comfig.h"
#include "led_interface.h"

void LED_INIT(void){
	DIO_voidSetPinDirection(LED_RED_PORT,LED_RED_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(LED_YELLOW_PORT,LED_YELLOW_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(LED_GREEN_PORT,LED_GREEN_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(LAMP_PORT,LAMP_PIN ,PIN_OUTPUT);
}

void LED_ON(u8 led_id){
	switch ( led_id)
	{
		case LED_RED  :   	DIO_voidSetPinValue(LED_RED_PORT,LED_RED_PIN,PIN_HIGH); break;
		case LED_YELLOW :	DIO_voidSetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,PIN_HIGH); break;
		case LED_GREEN :	DIO_voidSetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,PIN_HIGH); break;
		case LAMP :			DIO_voidSetPinValue(LAMP_PORT,LAMP_PIN ,PIN_HIGH); break;
	}
}

void LED_OFF(u8 led_id){
	switch ( led_id)
	{
		case LED_RED :   	DIO_voidSetPinValue(LED_RED_PORT,LED_RED_PIN,PIN_LOW); break;
		case LED_YELLOW :	DIO_voidSetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,PIN_LOW); break;
		case LED_GREEN :	DIO_voidSetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,PIN_LOW); break;
		case LAMP :			DIO_voidSetPinValue(LAMP_PORT,LAMP_PIN ,PIN_LOW); break;
	}
}

void LED_TOGGLE(u8 led_id){
	switch(led_id){
		case LAMP :			DIO_voidToggelPin(LAMP_PORT,LAMP_PIN ); break;
	}
}