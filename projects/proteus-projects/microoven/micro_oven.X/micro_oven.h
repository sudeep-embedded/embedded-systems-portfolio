/* 
 * File:   micro_oven.h
 * Author: sudee
 *
 * Created on January 19, 2026, 8:23 PM
 */

#ifndef MICRO_OVEN_H
#define	MICRO_OVEN_H

#define POWER_SCREEN       0x10
#define MENU_SCREEN        0x20
#define MICRO_MODE         0x30
#define GRILL_MODE         0x40
#define CONVECTION_MODE    0x50
#define START_MODE         0x60
#define BAR                0xFF




void display_power_screen(void);
void display_modes(void);

#endif	/* MICRO_OVEN_H */

