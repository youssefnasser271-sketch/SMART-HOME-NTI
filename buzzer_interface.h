#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_
#include "STD_TYPES.h"

#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN PIN6

void BUZZER_Init(void);
void BUZZER_ON(void);
void BUZZER_OFF(void);

#endif