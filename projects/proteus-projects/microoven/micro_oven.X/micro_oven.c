#include <xc.h>
#include "clcd.h"
#include "micro_oven.h"
#include "matrix_keypad.h"


unsigned char min, sec;
 extern unsigned char screen_flag;


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
    static unsigned char key_count = 0;
    static unsigned char delay, display_blank;
    if(reset_flag == MICRO_RESET_FLAG  )
    {
        sec = 0;
        min = 0;
        key = 0;
    }
    clcd_print("SET TIME (MM:SS)", LINE1(0));
    clcd_print("TIME:", LINE2(0));
    clcd_putch(':', LINE2(7));

    
    clcd_print("*:CLEAR #:ENTER", LINE4(0));
    
    if (key != '*' && key != '#' && key != ALL_RELEASED  )
    {
        key_count++;
        if(key_count <= 2)
        {
           sec = sec * 10 + key;
           blink_pos = 0;
        }
        else if(key_count <= 4)
        {
            min = min * 10 + key;
            blink_pos =1;
        }
        
    }
    else if ( key == '*')
    {
        if(blink_pos ==0)
        {
            sec = 0;
            key_count = 0;
        }
        else if( blink_pos == 1)
        {
            min = 0;
            key_count = 2;
        }
    }
    else if(key == '#')
    {
        clear_screen();
        FAN = ON;
        TMR2ON = 1;
        screen_flag = DISPLAY_TIME;
        
        
        
    }
    
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

void display_time(void)
{
    clcd_print("TIME = ", LINE1(1));
    clcd_putch( min / 10 + '0', LINE1(9));
    clcd_putch( min % 10 + '0', LINE1(10));
    clcd_putch(':', LINE1(11));
    clcd_putch( sec / 10 + '0', LINE1(12));
    clcd_putch( sec % 10 + '0', LINE1(13));
    clcd_print("4.START/RESUME", LINE2(2));
    clcd_print("4.PAUSE", LINE3(2));
    clcd_print("4.STOP", LINE4(2));
    
    if (min == 0 && sec == 0)
    {
        clear_screen();
        TMR2ON = 0;
        FAN = 0;
        clcd_print("TIME UP!!!", LINE2(4));
        clcd_print("Enjoy your meal", LINE3(0));
        
      
        __delay_ms(2000);
        clear_screen();
        screen_flag = MENU_SCREEN;
        
    }
    
}