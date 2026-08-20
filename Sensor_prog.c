#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "Sensor_config.h"
#include "Sensor_interfac.h"


void SENSORS_Init(void)
{
	
	DIO_voidSetPinDirection(GAS_SENSOR_PORT,GAS_SENSOR_PIN,PIN_INPUT);


	DIO_voidSetPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_INPUT);

	
	DIO_voidSetPinDirection(RAIN_SENSOR_PORT,RAIN_SENSOR_PIN,PIN_INPUT);
}


u8 GAS_SENSOR_Read(void)
{
	return DIO_voidGetBitValue(GAS_SENSOR_PORT,GAS_SENSOR_PIN);
}


u8 FLAME_SENSOR_Read(void)
{
	return DIO_voidGetBitValue(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);
}


u8 RAIN_SENSOR_Read(void)
{
	return DIO_voidGetBitValue(RAIN_SENSOR_PORT,RAIN_SENSOR_PIN);
}