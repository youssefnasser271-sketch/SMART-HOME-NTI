#include "STD_Types.h"
#include "BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_Private.h"
#include "DIO_Interface.h"

void PWM_voidInit(void)
{
	/* OC0(PB3) Output */
	DIO_voidSetPinDirection(PORTB_ID,PIN3,PIN_OUTPUT);

	/* Fast PWM */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/* Non Inverting Mode */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

	/* Prescaler = 64 */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	OCR0 = 0;
}

void PWM_voidStart(void)
{
	/* Prescaler = 64 */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

void PWM_voidStop(void)
{
	/* Stop Timer */
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

void PWM_voidSetDutyCycle(u8 Copy_u8Duty)
{
	if(Copy_u8Duty > 100)
	{
		Copy_u8Duty = 100;
	}

	OCR0 = ((u16)Copy_u8Duty * 255) / 100;
}