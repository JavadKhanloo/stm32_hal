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
#include "tim.h"

//-----------------------------------------------------------------------//

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim1;

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief TIM3 Configuration
*/
bool tim_TIM3_config(uint32_t ms_period)
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	htim3.Instance = TIM3;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 7200 - 1; // 10KHz
	htim3.Init.Prescaler = (ms_period * 10) - 1;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if(HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		return false;
	}


	// clock source configuration
	TIM_ClockConfigTypeDef clock_src_config = {0};
	clock_src_config.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if(HAL_TIM_ConfigClockSource(&htim3, &clock_src_config) != HAL_OK)
	{
		return false;
	}

	// Master Output Trigger
	TIM_MasterConfigTypeDef master_clock_config = {0};
	master_clock_config.MasterOutputTrigger = TIM_TRGO_UPDATE;
	master_clock_config.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if(HAL_TIMEx_MasterConfigSynchronization(&htim3, &master_clock_config) != HAL_OK)
	{
		return false;
	}

	HAL_NVIC_SetPriority(TIM3_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);

	return true;

}


/*
// @brief TIM1 Output GPIO
*/
void tim_TIM1_GPIO_config(void)
{
	GPIO_InitTypeDef gpio_config = {0};
	__HAL_RCC_GPIOB_CLK_ENABLE();
	// PB13, PB14
	gpio_config.Mode = GPIO_MODE_AF_PP;
	gpio_config.Pin = GPIO_PIN_13 | GPIO_PIN_14;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &gpio_config);

}

/*
// @brief TIM1 Output Compare Peripherals Configuration
*/
bool tim_TIM1_OC_config(uint32_t ms_period)
{
	__HAL_RCC_TIM1_CLK_ENABLE();

	htim1.Instance = TIM1;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 7200 - 1; // 10KHz
	htim1.Init.Prescaler = (ms_period * 10) - 1;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if(HAL_TIM_Base_Init(&htim1) != HAL_OK)
	{
		return false;
	}
	if(HAL_TIM_OC_Init(&htim1) != HAL_OK)
	{
		return false;
	}
	// output compare channel settings
	TIM_OC_InitTypeDef oc_config = {0};
	oc_config.OCMode = TIM_OCMODE_TOGGLE;
	oc_config.Pulse = 2000 - 1;
	oc_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	oc_config.OCNPolarity = TIM_OCPOLARITY_HIGH;
	oc_config.OCFastMode = TIM_OCFAST_DISABLE;
	oc_config.OCIdleState = TIM_OCIDLESTATE_RESET;
	oc_config.OCNIdleState = TIM_OCIDLESTATE_RESET;
	if(HAL_TIM_OC_ConfigChannel(&htim1, &oc_config, TIM_CHANNEL_1) != HAL_OK)
	{
		return false;
	}

	oc_config.Pulse = 5000 - 1;
	if(HAL_TIM_OC_ConfigChannel(&htim1, &oc_config, TIM_CHANNEL_2) != HAL_OK)
	{
		return false;
	}

	return true;
}


//-----------------------------------------------------------------------//
