#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"
char read_val;
unsigned short temperatue;
int main(void)
{
	DIO_vsetPINDir('D',0,1);
	DIO_vsetPINDir('D',1,1);
	LCD_vInit();
	ADC_vinit();
	 LCD_vSend_string("TEMPERATURE =");
    while(1)
    {
		
        temperatue=(ADC_u16Read()*0.25);
		
		if(temperatue<10)
		{
			LCD_movecursor(1,13);
			LCD_vSend_char(30);
			LCD_vSend_char((temperatue%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('c');
		}
		else if( temperatue<100)
		{
		LCD_movecursor(1,13);
		LCD_vSend_char((temperatue/10)+48);
		LCD_vSend_char((temperatue%10)+48);
		LCD_vSend_char(0XDF);
		LCD_vSend_char('c');
		
			if(temperatue<20)
			{
				DIO_write('D',1,1);
			}
			else if (temperatue>30)
			{
				DIO_write('D',0,1);
			}
			else
			{
				DIO_write('D',0,0);
				DIO_write('D',1,0);
			}
		}		
		else
		{
		
		}
		
    }
}