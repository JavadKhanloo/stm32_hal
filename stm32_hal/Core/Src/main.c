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
  tim_TIM3_PWM_GPIO_config();
  tim_TIM3_PWM_config();
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);

  // red
  tim_PWM_set_RGB(255, 0, 0);
  HAL_Delay(1000);
  // green
  tim_PWM_set_RGB(0, 255, 0);
  HAL_Delay(1000);
  // blue
  tim_PWM_set_RGB(0, 0, 255);
  HAL_Delay(1000);
  // cyan
  tim_PWM_set_RGB(0, 255, 255);
  HAL_Delay(1000);
  // magenta
  tim_PWM_set_RGB(255, 0, 255);
  HAL_Delay(1000);


  while (1)
  {

  } // end of while loop
} // end of main

//-----------------------------------------------------------------------//

