#include "STD_Types.h"

#include "ADC_Interface.h"

#include "LDR_Interface.h"


// void LDR_voidInit(u8 Copy_u8Channel)
// {
// 	//ADC_INIT();
// 	ADC_CHANNEL_SELECT(Copy_u8Channel);
// }

u16 LDR_u16ReadDigital(void)
{	ADC_CHANNEL_SELECT(LDR_CHANNEL);
	return ADC_Read_value();
}

u16 LDR_u16ReadVoltage(void)
{
	u16 Digital;

	Digital = ADC_Read_value();

	return (Digital * 5000UL) / 1024;
}