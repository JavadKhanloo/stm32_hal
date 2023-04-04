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
#include "adc.h"

//-----------------------------------------------------------------------//

ADC_HandleTypeDef adc_1_handle;

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//


/*
// @brief ADC Channels GPIO Configuration
*/
void adc_GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_init_struct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_init_struct.Mode = GPIO_MODE_ANALOG;
	GPIO_init_struct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_init_struct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_init_struct);


}

/*
// @brief ADC single channel configuration
 */
bool adc_single_config(ADC_single_select_e channel)
{
	__HAL_RCC_ADC1_CLK_ENABLE();

	adc_1_handle.Instance = ADC1;
	adc_1_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adc_1_handle.Init.ScanConvMode = ADC_SCAN_DISABLE;
	adc_1_handle.Init.ContinuousConvMode = DISABLE;
	adc_1_handle.Init.NbrOfConversion = 1;
	adc_1_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_1_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	if(HAL_ADC_Init(&adc_1_handle) != HAL_OK)
	{
		return false;
	}
	// ADC channel configuration
	ADC_ChannelConfTypeDef channel_config = {0};
	channel_config.Channel = channel;
	channel_config.Rank = 1;
	channel_config.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	if(HAL_ADC_ConfigChannel(&adc_1_handle, &channel_config) != HAL_OK)
	{
		return false;
	}

	return true;



}




//-----------------------------------------------------------------------//
