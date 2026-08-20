#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#include "STD_Types.h"

void PWM_voidInit(void);
void PWM_voidStart(void);
void PWM_voidStop(void);
void PWM_voidSetDutyCycle(u8 Copy_u8Duty);

#endif