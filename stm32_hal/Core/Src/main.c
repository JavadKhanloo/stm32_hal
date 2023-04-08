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
// header section                                                        //
//-----------------------------------------------------------------------//
#include "main.h"
#include "rcc.h"
#include "uart.h"
#include "gpio.h"
#include "tm1637.h"
#include "exti.h"
#include "adc.h"
#include "tim.h"
//-----------------------------------------------------------------------//


//-----------------------------------------------------------------------//
// main function                                                         //
//-----------------------------------------------------------------------//
int main()
{
  HAL_Init();
  // clock
  rcc_system_clock_config();

  // uart
  uart_UART1_GPIO_config();
  uart_UART1_config();

  // led
  gpio_LED_config();

  // pb
  gpio_PB_config();

  //sw
  gpio_SW_config();

  // tim_oc
  tim_TIM1_GPIO_config();
  tim_TIM1_OC_config(500);

  // start channel 1 inverted
  HAL_TIMEx_OCN_Start(&htim1, TIM_CHANNEL_1);
  // start channel 1 inverted
  HAL_TIMEx_OCN_Start(&htim1, TIM_CHANNEL_2);

  while (1)
  {

  } // end of while loop
} // end of main

//-----------------------------------------------------------------------//
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM3)
	{
		gpio_LED_toggle_red();
	}
}
