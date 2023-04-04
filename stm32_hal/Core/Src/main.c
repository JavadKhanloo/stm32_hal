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
//-----------------------------------------------------------------------//

bool pb_intertupt_flag = false;

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

  // ADC
  adc_GPIO_config();
  adc_single_config(ADC_single_select_joystick_y);
  uint16_t adc_value;



  while (1)
  {
	  HAL_ADC_Start(&adc_1_handle);
	  if(HAL_ADC_PollForConversion(&adc_1_handle, 10) == HAL_OK)
	  {
		  // read ADC value
		  adc_value = HAL_ADC_GetValue(&adc_1_handle);
		  printf("ADC value : %d\n", adc_value);
		  gpio_LED_toggle_green();
	  }

	  HAL_Delay(250);

  }
}



//-----------------------------------------------------------------------//
