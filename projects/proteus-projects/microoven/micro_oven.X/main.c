/*
 * File:   main.c
 */

#include <xc.h>
#include "clcd.h"
#include "micro_oven.h"
#include "matrix_keypad.h"
#include "timers.h"

#pragma config WDTE = OFF
unsigned char screen_flag = POWER_SCREEN;


static void init_config(void) {
    init_clcd();
    init_matrix_keypad();
    init_timer2();
    FAN_DDR = 0;
    PEIE = 1;
    GIE = 1;
    
}

void main(void)
{
    init_config();

    
    unsigned char key;
    unsigned char reset_flag = 0;

    while (1)
    {
        key = read_matrix_keypad(STATE);

        if (screen_flag == MENU_SCREEN)
        {
            if (key == 1)
            {
                screen_flag = MICRO_MODE;
                clear_screen();
                clcd_print("Power = 900W", LINE2(2));
                __delay_ms(3000);
                clear_screen();
                reset_flag = MICRO_RESET_FLAG;
            }
            else if (key == 2)
            {
                screen_flag = GRILL_MODE;
                clear_screen();
            }
            else if (key == 3)
            {
                screen_flag = CONVECTION_MODE;
                clear_screen();
            }
            else if (key == 4)
            {
                screen_flag = START_MODE;
                clear_screen();
            }
        }

        switch (screen_flag)
        {
            case POWER_SCREEN:
                display_power_screen();
                clear_screen();
                screen_flag = MENU_SCREEN;
                break;

            case MENU_SCREEN:
                display_modes();
                break;

            case MICRO_MODE:
                set_time(key, reset_flag);
                break;
            
            case DISPLAY_TIME :
                display_time();
                break;
        }
        reset_flag = RESET_NOTHING;
    }
}
