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

  // interrupt
  exti_pb_config();



  while (1)
  {
	  if(pb_intertupt_flag)
	  {
		  pb_intertupt_flag = false;
		  gpio_LED_toggle_green();
		  HAL_Delay(10);
		  EXTI->IMR |= (1UL << 0);
	  }
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_0)
	{
		pb_intertupt_flag = true;
		EXTI->IMR &= ~(1UL << 0);
	}
}

//-----------------------------------------------------------------------//
