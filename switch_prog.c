#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "switch_interface.h"
#include "switch_config.h"
#include "DIO_Interface.h"


void HAL_SWITCH_INI(void){
	DIO_voidSetPinDirection(SW1_PORT,SW1_PIN,PIN_INPUT);
	DIO_voidSetPinDirection(SW2_PORT,SW2_PIN,PIN_INPUT);
	DIO_voidSetPinDirection(SW3_PORT,SW3_PIN,PIN_INPUT);
}
u8 HAL_SWITCH_GET_u8VAL(u8 switch_num){
	u8 local = 0;
	switch(switch_num){
		case MANUAL :	local = DIO_voidGetBitValue(SW1_PORT,SW1_PIN); break;
		
		case BLUTOOTH:	local = DIO_voidGetBitValue(SW2_PORT,SW2_PIN); break;
		
		case AUTO:	local = DIO_voidGetBitValue(SW3_PORT,SW3_PIN); break;
		
		case LAMP_SW:	local = DIO_voidGetBitValue(SW4_PORT,SW4_PIN); break;
	}
	 return local;
}