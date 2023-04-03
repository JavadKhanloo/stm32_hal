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
#include "gpio.h"

//-----------------------------------------------------------------------//

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief LED GPIO Configuration
*/
void gpio_LED_config(void)
{
	// green LED => PB13
	// red   LED => PB14

  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef gpio_init_struct = {0};
  gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
  gpio_init_struct.Pin = GPIO_PIN_13 | GPIO_PIN_14;
  gpio_init_struct.Pull = GPIO_NOPULL;
  gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &gpio_init_struct);

}

/*
// @brief LED write/toggle (Green/Red)
*/
void gpio_LED_write_green(bool state)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)state);
}
void gpio_LED_write_red(bool state)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (GPIO_PinState)state);
}
void gpio_LED_toggle_green(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
}
void gpio_LED_toggle_red(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
}


/*
// @brief PB GPIO Configuration
*/
void gpio_PB_config(void)
{
	// user button PA0
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init_struct = {0};
	gpio_init_struct.Mode = GPIO_MODE_INPUT;
	gpio_init_struct.Pin = GPIO_PIN_0;
	gpio_init_struct.Pull = GPIO_NOPULL;
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio_init_struct);

}

/*
// @brief PB GPIO read pin
*/
bool gpio_PB_read(void)
{
	return (bool)HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}

//-----------------------------------------------------------------------//
