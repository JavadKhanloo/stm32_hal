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
#include "exti.h"

//-----------------------------------------------------------------------//

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief EXTI Configuration
*/
void exti_pb_config(void)
{
  	// user button PA0
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init_struct = {0};
	gpio_init_struct.Mode = GPIO_MODE_IT_RISING;
	gpio_init_struct.Pin = GPIO_PIN_0;
	gpio_init_struct.Pull = GPIO_NOPULL;
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio_init_struct);

    HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}





//-----------------------------------------------------------------------//
