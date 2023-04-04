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
#ifndef _ADC_H_
#define _ADC_H_

#include "main.h"

extern ADC_HandleTypeDef adc_1_handle;

// select adc single channel
typedef enum ADC_single_select_tab {
	ADC_single_select_potentiometer = 1,
	ADC_single_select_joystick_x,
	ADC_single_select_joystick_y,
} ADC_single_select_e;
//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief ADC Channels GPIO Configuration
*/
void adc_GPIO_config(void);

/*
// @brief ADC single channel configuration
 */
bool adc_single_config(ADC_single_select_e channel);




//-----------------------------------------------------------------------//
#endif
//-----------------------------------------------------------------------//
