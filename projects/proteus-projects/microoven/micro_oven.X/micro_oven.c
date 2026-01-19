#include <xc.h>
#include "clcd.h"
#include "micro_oven.h"


unsigned char min, sec;


void display_power_screen(void )
{
    for (unsigned char i = 0; i < 16; i++)
{
    clcd_putch(BAR, LINE1(i)); // 0 1 2 3 ..... 15
    __delay_ms(100);
}

    clcd_print("Powering ON", LINE2(3));
    clcd_print("Microwave Oven", LINE3(2));
    for(unsigned char i = 0; i < 16; i++)
{
    clcd_putch(BAR, LINE4(i)); // 0 1 2 3 ..... 15
    __delay_ms(100);
}
    
  __delay_ms(1000);

    
}

void display_modes(void)
{
    clcd_print("1 Micro", LINE1(3));
    clcd_print("2 Grill", LINE2(3));
    clcd_print("3 Convection", LINE3(3));
    clcd_print("4 Start", LINE4(3));
}



void set_time(unsigned char key, unsigned char reset_flag)
{
    static unsigned char blink_pos = 0;
    static unsigned char delay, display_blank;
    if(reset_flag == MICRO_RESET_FLAG  )
    {
        sec = 0;
        min = 0;
    }
    clcd_print("SET TIME (MM:SS)", LINE1(0));
    clcd_print("TIME:", LINE2(0));
    clcd_putch(':', LINE2(7));

    
    clcd_print("*:CLEAR #:ENTER", LINE4(0));
    
    if(delay++ == 10)
    {
        delay = 0;
        display_blank = !display_blank;
    }
    
    if(display_blank)
    {
        if( blink_pos == 0)
        {
            clcd_putch(' ', LINE2(8));
            clcd_putch(' ', LINE2(9));
        }
        else
        {
            clcd_putch(' ', LINE2(5));
            clcd_putch(' ', LINE2(6));
        }
    }
    else
    {
        clcd_putch( sec / 10 + '0', LINE2(8));
        clcd_putch( sec % 10 + '0', LINE2(9));
        
        clcd_putch( min / 10 + '0', LINE2(5));
        clcd_putch( min % 10 + '0', LINE2(6));
    }
    
 }