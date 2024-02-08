#ifndef LCD_INC_LCD_H_
#define LCD_INC_LCD_H_

#include "GPIO_Interface.h"
#include "Bit_math.h"

#define LCD_CONFIG_WORD             (0x30)
#define LCD_CLR                     (0x01)
#define LCD_CURSOR_HOME             (0x02)
#define LCD_SET_ENTRY_MODE          (0x40)
#define LCD_INCREMENT_CURSOR        (0x02)
#define LCD_DECREMENT_CURSOR        (0x00)
#define LCD_DISPLAY_SHIFT_ON        (0x01)
#define LCD_DISPLAY_SHIFT_OFF       (0x00)
#define LCD_DISPLAY_CONTROL         (0x08)
#define LCD_DISPLAY_ON              (0x04)
#define LCD_DISPLAY_OFF             (0x00)
#define LCD_CURSOR_ON               (0x02)
#define LCD_CURSOR_OFF              (0x00)
#define LCD_CURSOR_BLINK_ON         (0x01)
#define LCD_CURSOR_BLINK_OFF        (0x00)
#define LCD_CURSOR_DISPLAY_CONTROL  (0x10)
#define LCD_SHIFT_CURSOR            (0x00)
#define LCD_SHIFT_DISPLAY           (0x08)
#define LCD_SHIFT_LEFT              (0x00)
#define LCD_SHIFT_RIGHT             (0x04)
#define LCD_FUNCTION_SET            (0x20)
#define LCD_DATA_LENGTH_4           (0x00)
#define LCD_DATA_LENGTH_8           (0x10)
#define LCD_ONE_LINE                (0x00)
#define LCD_TWO_LINES               (0x08)
#define LCD_SMALL_FONT              (0x00)
#define LCD_LARGE_FONT              (0x04)
#define LCD_SET_CGRAM_ADDRESS       (0x40)
#define LCD_SET_DDRAM_ADDRESS       (0x80)
#define LCD_DDRAM_LINE_SIZE         (0x28)
#define LCD_DDRAM_LINE_2_ADDRESS    (0x40)



void LCD_Init(void);
void LCD_SendChar(uint8 ch);
void LCD_SendString(char * str);
void LCD_GoTo(uint8 line, uint8 column);
void LCD_CustomChar(uint8 address,uint8*pattern);
void LCD_Clear(void);
void LCD_writeNumber(int num);
void LCD_SendCommand(uint8 command);


#endif /* LCD_INC_LCD_H_ */
