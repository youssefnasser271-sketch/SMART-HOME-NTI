#ifndef SENSORS_INTERFACE_H_
#define SENSORS_INTERFACE_H_

void SENSORS_Init(void);

u8 GAS_SENSOR_Read(void);

u8 FLAME_SENSOR_Read(void);

u8 RAIN_SENSOR_Read(void);

#endif