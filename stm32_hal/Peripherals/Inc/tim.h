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
#ifndef _TIM_H_
#define _TIM_H_

#include "main.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim1;

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief TIM3 Configuration
*/
bool tim_TIM3_config(uint32_t ms_period);

/*
// @brief TIM1 Output GPIO
*/
void tim_TIM1_GPIO_config(void);

/*
// @brief TIM1 Output Compare Peripherals Configuration
*/
bool tim_TIM1_OC_config(uint32_t ms_period);
//-----------------------------------------------------------------------//
#endif
//-----------------------------------------------------------------------//
