//-----------------------------------------------------------------------//
//                   _                      _                            //
//                  | |                    | |                           //
//                  | |     _______    _   | |     _                     //
//                  | |    |  ___  |  |_|  | |    | |                    //
//                  | |   _| |_|_| |   _   | |____| |                    //
//                  |_|  |  _______|  | |  |________|                    //
//                     __| |        __| |     _  _                       //
//                    |____|       |____|    |_||_|                      //
//-----------------------------------------------------------------------//

//-----------------------------------------------------------------------//
// header guard                                                          //
//-----------------------------------------------------------------------//
#ifndef _GPIO_H_
#define _GPIO_H_

#include "main.h"

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief LED GPIO Configuration
*/
void gpio_LED_config(void);

/*
// @brief LED write/toggle (Green/Red)
*/
void gpio_LED_write_green(bool state);
void gpio_LED_write_red(bool state);
void gpio_LED_toggle_green(void);
void gpio_LED_toggle_red(void);

/*
// @brief PB GPIO Configuration
*/
void gpio_PB_config(void);

/*
// @brief PB GPIO read pin
*/
bool gpio_PB_read(void);


/*
// @brief PB GPIO Configuration
*/
void gpio_SW_config(void);

/*
// @brief PB GPIO read pin
*/
bool gpio_SW_1_read(void);
bool gpio_SW_2_read(void);


/*
// @brief tm1637 GPIO Configuration
*/
void gpio_tm1637_config(void);

//-----------------------------------------------------------------------//
#endif
//-----------------------------------------------------------------------//
