#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

#include "STD_Types.h"

#define LDR_CHANNEL ADC_CHANNEL0

// void LDR_voidInit(u8 Copy_u8Channel);

u16 LDR_u16ReadDigital(void);

u16 LDR_u16ReadVoltage(void);

#endif