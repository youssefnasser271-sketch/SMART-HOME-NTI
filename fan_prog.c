#include "STD_Types.h"

#include "PWM_interface.h"

#include "fan_interface.h"

void FAN_Init(void)
{
	PWM_voidInit();
	PWM_voidStart();
}

void FAN_SetSpeed(u8 speed)
{
	PWM_voidSetDutyCycle(speed);
}

void FAN_OFF(void)
{
	PWM_voidSetDutyCycle(0);
}