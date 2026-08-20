#define F_CPU 8000000UL

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "SMART_HOME.h"

#include <util/delay.h>


int main(void)
{
	SMART_HOME_Init();

	while(1)
	{
		SMART_HOME_Run();

		_delay_ms(10);
	}

	return 0;
}