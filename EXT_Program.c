/*
 * EXT_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: General
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "DIO_Interface.h"
#include  "EXT_Private.h"
#include "EXT_Config.h"
#include "EXT_Interface.h"




static void (*ptr_ArrCallBack[3])(void) = {NULL,NULL,NULL};











void EXT_voidInit(u8 copy_u8EiNum,u8 copy_u8ControlSens)
{

	switch(copy_u8EiNum)
	{
	case EXT0 :


		DIO_voidSetPinDirection(PORTD_ID,PIN2,PIN_INPUT);
		
		if(copy_u8ControlSens==FALLING_EDGE)
		{


			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);

		}


		else if(copy_u8ControlSens==RISING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		}

		SET_BIT(GICR,GICR_INT0);



		break ;


	case EXT1 :

		DIO_voidSetPinDirection(PORTD_ID,PIN3,PIN_INPUT);
		if(copy_u8ControlSens==FALLING_EDGE)
		{

			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);

		}

		else if(copy_u8ControlSens==RISING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		}
		SET_BIT(GICR,GICR_INT1);

		break ;

	case EXT2 :

		DIO_voidSetPinDirection(PORTB_ID,PIN2,PIN_INPUT);
		if(copy_u8ControlSens==FALLING_EDGE)
		{
			CLR_BIT(MCUCSR,6);
		}

		else if(copy_u8ControlSens==RISING_EDGE)
		{
			SET_BIT(MCUCSR,6);
		}
		SET_BIT(GICR,5);

		break ;

	}
}


/**************call back function ****************/

void EXT_voidSetCallBack(  void (*ptr_ext)(void) ,u8 copy_u8ExtNum )
{



	if(ptr_ext!=NULL)
	{
		switch(copy_u8ExtNum)
		{
		case EXT0:
			ptr_ArrCallBack[ 0 ]= ptr_ext;
			break;
		case EXT1:
			ptr_ArrCallBack[ 1 ]= ptr_ext;
			break;
		case EXT2:
			ptr_ArrCallBack[ 2 ]= ptr_ext;
			break;
		default: break;

		}



	}
}



void __vector_1 () __attribute__ ((signal));
void __vector_1 ()
{

	ptr_ArrCallBack[0]();



}

void __vector_2 () __attribute__ ((signal));
void __vector_2 ()
{


	ptr_ArrCallBack[1]();

}

void __vector_3 () __attribute__ ((signal));
void __vector_3 ()
{

	ptr_ArrCallBack[2]();

}

