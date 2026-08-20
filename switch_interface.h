#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define MANUAL 0x00
#define BLUTOOTH 0x01
#define AUTO 0x02
#define LAMP_SW 0X03



void HAL_SWITCH_INI(void);

u8 HAL_SWITCH_GET_u8VAL(u8 switch_num);





#endif

