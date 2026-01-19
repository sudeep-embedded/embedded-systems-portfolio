#include <xc.h>
#include "clcd.h"
#include "micro_oven.h"




void display_power_screen(void)
{
    for (unsigned char i = 0; i < 16; i++)
{
    clcd_putch(BAR, LINE1(i)); // 0 1 2 3 ..... 15
    __delay_ms(100);
}

    clcd_print("Powering ON", LINE2(3));
    clcd_print("Microwave Oven", LINE3(2));

    for (unsigned char i = 0; i < 16; i++)
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