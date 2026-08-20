#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "buzzer_config.h"
#include "buzzer_interface.h"



void BUZZER_Init(void)
{
	DIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);
	BUZZER_OFF();
}

void BUZZER_ON(void)
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, PIN_HIGH);
}

void BUZZER_OFF(void)
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, PIN_LOW);
}