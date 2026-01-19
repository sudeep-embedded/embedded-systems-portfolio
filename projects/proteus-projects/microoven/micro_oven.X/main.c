/*
 * File:   main.c
 */

#include <xc.h>
#include "clcd.h"
#include "micro_oven.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_clcd();
}

 void main(void)
 {
    init_config();
    unsigned char screen_flag = POWER_SCREEN;
 
    while (1) 
    {
     switch( screen_flag)
  {
    
    case POWER_SCREEN :
                display_power_screen();
                clear_screen();
                screen_flag = MENU_SCREEN;
                break;

    case MENU_SCREEN :
        
                display_modes();
                break;
  }
   }
 }