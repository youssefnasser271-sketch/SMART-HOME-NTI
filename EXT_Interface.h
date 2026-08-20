/*
 * EXT_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: General
 */

#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_




#define EXT0 (u8)(0X00)
#define EXT1 (u8)(0X01)
#define EXT2 (u8)(0X02)


#define FALLING_EDGE (u8)(0X00)
#define RISING_EDGE  (u8)(0X01)


#define G_INTERRUPT_NOT_WORK (u8)(0X00)
#define G_INTERRUPT_WORK  (u8)(0X01)




void EXT_voidInit(u8 copy_u8EiNum,u8 copy_u8ControlSens);
void EXT_voidSetCallBack(  void (*ptr_ext)(void) ,u8 copy_u8ExtNum );



#endif /* EXT_INTERFACE_H_ */
