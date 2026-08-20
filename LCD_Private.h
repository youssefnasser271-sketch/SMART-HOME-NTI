/*
 * LCD_Private.h
 *
 * Created: 7/22/2023 6:51:38 PM
 *  Author: Rizk
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/* MACRO DECRELATION SECTION  */
#define _LCD_CLEAR                               0x01
#define _LCD_RETURN_HOME                         0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF            0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON             0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF            0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON             0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT              0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT             0x14
#define _LCD_DISPLAY_SHIFT_LEFT                  0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                 0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE                    0x38
#define _LCD_4BIT_MODE_2_LINE                    0x28

#define _LCD_CGRAM_START                         0x40
#define _LCD_DDRAM_START                         0x80



#endif /* LCD_PRIVATE_H_ */