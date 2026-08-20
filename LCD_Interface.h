/*
 * LCD_Interface.h
 *
 * Created: 7/22/2023 6:51:55 PM
 *  Author: Rizk
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);

void Lcd_SendCmd(u8 Command);

void LCD_voidSenddata(u8 data);

void Lcd_DisplayStr(u8* str);

void Lcd_Goto_Row_Column(u8 row, u8 col);

void Lcd_DisplayChr(u8 chr);

void Lcd_Displaynum(u16 number);





#endif /* LCD_INTERFACE_H_ */