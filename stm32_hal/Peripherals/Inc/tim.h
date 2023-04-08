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

/*
// @brief TIM3 PWM GPIO Configuration
*/
void tim_TIM3_PWM_GPIO_config(void);

/*
// @brief TIM3 PWM Peripherals Configuration
*/
bool tim_TIM3_PWM_config(void);

/*
// @brief PWM LED Duty 0-100
*/
void tim_PWM_set_duty_cycle_1(uint8_t duty_cycle_0_100);
void tim_PWM_set_duty_cycle_2(uint8_t duty_cycle_0_100);
void tim_PWM_set_duty_cycle_3(uint8_t duty_cycle_0_100);

/*
// @brief PWM RGB (0-255)
*/
void tim_PWM_set_RGB(uint8_t R, uint8_t G, uint8_t B);

//-----------------------------------------------------------------------//
#endif
//-----------------------------------------------------------------------//
