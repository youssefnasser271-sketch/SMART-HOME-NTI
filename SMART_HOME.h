#ifndef SMARTHOME_H_
#define SMARTHOME_H_

#include "STD_Types.h"

// extern volatile u8 Alarm_Flag;
// extern volatile u16 current_ldr_val;

void SMART_HOME_Init(void);
void SMART_HOME_Run(void);

void ALARM_ISR(void);
void MANUAL_ISR(void);

u16 SMART_HOME_GetTemperature(void);
void SMART_HOME_ClimateControl(u16 temp);

void SMART_HOME_BluetoothLight(void);
void SMART_HOME_AutoLight(u16 ldr);

void SMART_HOME_AlarmTask(void);

void SMART_HOME_LCD_Update(u16 temp,u16 ldr,u8 rain,u8 alarm);

#endif