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



/*
// @brief ADC Interrupt enable
 */
void adc_interrupt_config(void)
{
	__HAL_ADC_ENABLE_IT(&adc_1_handle, ADC_IT_EOC);
	HAL_NVIC_SetPriority(ADC1_2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(ADC1_2_IRQn);
}


/*
// @brief ADC Multi-channel configuration
*/
bool adc_multi_channel_config(void)
{
	__HAL_RCC_ADC1_CLK_ENABLE();

	adc_1_handle.Instance = ADC1;
	adc_1_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adc_1_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
	adc_1_handle.Init.ContinuousConvMode = DISABLE;
	adc_1_handle.Init.NbrOfConversion = 3;
	adc_1_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_1_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	if(HAL_ADC_Init(&adc_1_handle) != HAL_OK)
	{
		return false;
	}
	// ADC channel configuration
	// channel-1 => PA1
	ADC_ChannelConfTypeDef channel_config = {0};
	channel_config.Channel = ADC_CHANNEL_1;
	channel_config.Rank = 1;
	channel_config.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	if(HAL_ADC_ConfigChannel(&adc_1_handle, &channel_config) != HAL_OK)
	{
		return false;
	}
	// channel-2 => PA2
	channel_config.Channel = ADC_CHANNEL_2;
	channel_config.Rank = 2;
	channel_config.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	if(HAL_ADC_ConfigChannel(&adc_1_handle, &channel_config) != HAL_OK)
	{
		return false;
	}
	// channel-3 => PA3
	channel_config.Channel = ADC_CHANNEL_3;
	channel_config.Rank = 3;
	channel_config.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	if(HAL_ADC_ConfigChannel(&adc_1_handle, &channel_config) != HAL_OK)
	{
		return false;
	}
	return true;
}

/*
// @brief ADC DMA configuration
*/
void adc_dma_config(void)
{
	__HAL_RCC_DMA1_CLK_ENABLE();
	static DMA_HandleTypeDef dma_1_handle;
	dma_1_handle.Instance = DMA1_Channel1;
	dma_1_handle.Init.Direction = DMA_PERIPH_TO_MEMORY;
	dma_1_handle.Init.PeriphInc = DMA_PINC_DISABLE;
	dma_1_handle.Init.MemInc = DMA_MINC_ENABLE;
	dma_1_handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD; // 16 bit
	dma_1_handle.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
	dma_1_handle.Init.Mode = DMA_CIRCULAR;
	dma_1_handle.Init.Priority = DMA_PRIORITY_MEDIUM;
	HAL_DMA_Init(&dma_1_handle);
	__HAL_LINKDMA(&adc_1_handle, DMA_Handle, dma_1_handle);
	// enable DMA interrupt
	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);



}




//-----------------------------------------------------------------------//
