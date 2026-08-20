#include "BIT_MATH.h"
#include "PWM_private.h"
#include "PWM_interface.h"
#include "STD_Types.h"

void PWM_Timer0_Init(void) {
	// 1. ضبط طرف OC0 (PB3) كـ Output
	
	DIO_voidSetPinDirection(PORTB_ID,PIN3,PIN_OUTPUT);

	// 2. اختيار وضع Fast PWM (WGM00 = 1, WGM01 = 1)
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);

	// 3. ضبط وضع Non-Inverting Mode (COM01 = 1, COM00 = 0)
	// Clear OC0 on compare match, set OC0 at TOP
	SET_BIT(TCCR0_REG, COM01);
	CLR_BIT(TCCR0_REG, COM00);

	// 4. ضبط مقسم التردد Prescaler = 8 (CS01 = 1, CS00 = 0, CS02 = 0)
	CLR_BIT(TCCR0_REG, CS00);
	SET_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);

	// 5. بداية القيمة بـ 0
	OCR0_REG = 0;
}

void PWM_Timer0_SetDutyCycle(unsigned char copy_u8DutyCycle) {
	if (copy_u8DutyCycle > 100) {
		copy_u8DutyCycle = 100;
	}

	// معادلة تحويل النسبة (0-100%) إلى قيمة الـ Register (0-255)
	OCR0_REG = (unsigned char)(((unsigned long)copy_u8DutyCycle * 255) / 100);
}

void PWM_Timer0_Stop(void) {
	// إيقاف الـ Clock عن التايمر (CS00=0, CS01=0, CS02=0)
	CLR_BIT(TCCR0_REG, CS00);
	CLR_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
	
	OCR0_REG = 0;
}