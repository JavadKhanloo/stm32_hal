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

	return true;

}


//-----------------------------------------------------------------------//
