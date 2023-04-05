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

bool adc_EoC_flag = false;
bool adc_AWDG_flag = false;
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

  tim_TIM3_config(50);
  adc_AWDG_config(ADC_single_select_potentiometer);

  HAL_ADC_Start_DMA(&adc_1_handle, (uint32_t *)adc_value, 3);
  HAL_TIM_Base_Start(&htim3);

  while (1)
  {

	  if(adc_EoC_flag)
	  {
		  adc_EoC_flag = false;
		  printf("adc values:\r\n");
		  printf("PA1 : %d\tPA2 : %d\tPA3 : %d\r\n", adc_value[0], adc_value[1], adc_value[2]);
		  gpio_LED_toggle_green();

		  if(adc_AWDG_flag)
		  {
			  adc_AWDG_flag = false;
			  printf("ADC Watchdog threshold triggered\r\n");
			  gpio_LED_toggle_red();
		  }
	  }



  } // end of while loop
} // end of main

//-----------------------------------------------------------------------//
/*
// @brief ADC Handler
*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adc_EoC_flag = true;
}

void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc)
{
	if(hadc->Instance == ADC1)
	{
		adc_AWDG_flag = true;
	}
}

