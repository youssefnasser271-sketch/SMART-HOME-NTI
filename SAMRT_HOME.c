#define F_CPU 8000000UL

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "switch_interface.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "LDR_interface.h"
#include "led_interface.h"
#include "LCD_Interface.h"
#include "PWM_interface.h"
#include "EXT_Interface.h"
#include "GIE_Interface.h"
#include "Sensor_interfac.h"

#include "SMART_HOME.h"

#include <util/delay.h>


volatile u8 Alarm_Flag = 0;
volatile u16 current_ldr_val = 0;



void ALARM_ISR(void)
{
	Alarm_Flag = 1;
}


void MANUAL_ISR(void)
{
	LED_TOGGLE(LAMP);
}


void SMART_HOME_Init(void)
{
	LED_INIT();

	ADC_INIT();

	HAL_SWITCH_INI();

	USART_Init(9600);

	LCD_voidInit();

	PWM_voidInit();
	PWM_voidStart();
	
	EXT_voidSetCallBack(ALARM_ISR, EXT0);
	EXT_voidInit(EXT0, RISING_EDGE);

	EXT_voidSetCallBack(MANUAL_ISR, EXT2);
	EXT_voidInit(EXT2, RISING_EDGE);

	GIE_Enable();

	LED_ON(LED_GREEN);
	LED_OFF(LED_RED);
}

u16 SMART_HOME_GetTemperature(void)
{
	u16 adc_val;

	ADC_CHANNEL_SELECT(ADC_CHANNEL6);

	adc_val = ADC_Read_value();

	return (u16)(((u32)adc_val * 500) / 1024);
}


void SMART_HOME_ClimateControl(u16 temp)
{
	if(temp > 50)
	{
		 FAN_SetSpeed(100);
	}
	else if(temp > 30)
	{
		 FAN_SetSpeed(70);
	}
	else if(temp > 20)
	{
		 FAN_SetSpeed(50);
	}
	else
	{
		FAN_OFF();
	}
}



void SMART_HOME_BluetoothLight(void)
{
	u8 data;

	data = USART_Receive();

	switch(data)
	{
		case 'L':
		LED_ON(LAMP);
		USART_Transmit('L');
		break;

		case 'F':
		LED_OFF(LAMP);
		USART_Transmit('F');
		break;
	}
}


void SMART_HOME_AutoLight(u16 ldr)
{
	if(ldr < 500)
	{
		LED_ON(LAMP);
	}
	else
	{
		LED_OFF(LAMP);
	}
}


void SMART_HOME_AlarmTask(void)
{
	if (GAS_SENSOR_Read() == PIN_LOW)
	{
		Alarm_Flag = 0;
	}
	if(Alarm_Flag == 1)
	{
		LED_OFF(LED_GREEN);
		LED_ON(LED_RED);

		BUZZER_ON();
	}
	else
	{
		LED_ON(LED_GREEN);
		LED_OFF(LED_RED);

		BUZZER_OFF();
	}
}


static void LCD_ShowTemperature(u16 temp, u16 ldr)
{
	Lcd_Goto_Row_Column(0,0);
	Lcd_DisplayStr((u8*)"Temp:");
	Lcd_Displaynum(temp);
	Lcd_DisplayStr((u8*)" C ");

	if(ldr < 500)
	{
		Lcd_DisplayStr((u8*)"Night");
	}
	else
	{
		Lcd_DisplayStr((u8*)"Day  ");
	}
}


static void LCD_ShowRain(u8 rain)
{
	Lcd_Goto_Row_Column(2,0);

	if(rain == PIN_HIGH)
	{
		Lcd_DisplayStr((u8*)"It's Raining      ");
	}
	else
	{
		Lcd_DisplayStr((u8*)"                 ");
	}
}


static void LCD_ShowAlarm(u8 alarm)
{
	static u8 blink = 0;

	Lcd_Goto_Row_Column(1,0);

	if(alarm)
	{
		blink ^= 1;

		if(blink)
		{
			Lcd_DisplayStr((u8*)" ** ALARM ** ");
		}
		else
		{
			Lcd_DisplayStr((u8*)"             ");
		}
	}
	else
	{
		blink = 0;
		Lcd_DisplayStr((u8*)"             ");
	}
}


void SMART_HOME_LCD_Update(u16 temp,u16 ldr,u8 rain,u8 alarm)
{
	static u8 refresh = 0;

	refresh++;

	if(refresh < 5)
	{
		return;
	}

	refresh = 0;

	LCD_ShowTemperature(temp, ldr);

	LCD_ShowRain(rain);

	LCD_ShowAlarm(alarm);
}


void SMART_HOME_Run(void)
{
	u16 current_temp;
	u8 rain_status;

	current_temp = SMART_HOME_GetTemperature();

	current_ldr_val = LDR_u16ReadDigital();

	SMART_HOME_ClimateControl(current_temp);

	if(HAL_SWITCH_GET_u8VAL(BLUTOOTH) == 1)
	{
		SMART_HOME_BluetoothLight();
	}


	else if(HAL_SWITCH_GET_u8VAL(AUTO) == 1)
	{
		SMART_HOME_AutoLight(current_ldr_val);
	}
	SMART_HOME_AlarmTask();


	rain_status = RAIN_SENSOR_Read();


	SMART_HOME_LCD_Update(current_temp,current_ldr_val,rain_status,Alarm_Flag);
}