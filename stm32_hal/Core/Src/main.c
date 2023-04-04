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

bool adc_EoC_flag = false;
uint16_t adc_value[3];


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



  //ADC DMA
  adc_multi_channel_config();
  adc_dma_config();

  HAL_ADC_Start_DMA(&adc_1_handle, (uint32_t *)adc_value, 3);

  while (1)
  {

	  if(adc_EoC_flag)
	  {
		  adc_EoC_flag = false;
		  printf("adc values:\r\n");
		  printf("PA1 : %d\tPA2 : %d\tPA3 : %d\r\n", adc_value[0], adc_value[1], adc_value[2]);
		  gpio_LED_toggle_green();
		  HAL_ADC_Start_DMA(&adc_1_handle, (uint32_t *)adc_value, 3);
	  }

	  HAL_Delay(250);

  }
}

/*
// @brief ADC Handler
*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adc_EoC_flag = true;
}


//-----------------------------------------------------------------------//
