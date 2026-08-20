#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_RED 0x00
#define LED_YELLOW 0x01
#define LED_GREEN 0x02
#define LAMP 0x03


void LED_INIT(void);
void LED_ON(u8 led_id);
void LED_OFF(u8 led_id);
void LED_TOGGLE(u8 led_id);


#endif