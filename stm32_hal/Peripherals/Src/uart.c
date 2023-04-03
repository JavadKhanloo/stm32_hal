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
#include "uart.h"
//-----------------------------------------------------------------------//

UART_HandleTypeDef huart1;

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//
/*
// @brief UART1 GPIO configuration
*/
void uart_UART1_GPIO_config(void)
{
    // PA9  => TX
    // PA10 => RX
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitTypeDef gpio_init_struct;

    // PA9  => TX
    gpio_init_struct.Pin = GPIO_PIN_9;
    gpio_init_struct.Mode = GPIO_MODE_AF_PP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &gpio_init_struct);

    // PA10 => RX
    gpio_init_struct.Pin = GPIO_PIN_10;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &gpio_init_struct);




}
/*
// @brief UART1 Peripheral configuration
*/
bool uart_UART1_config(void)
{
  __HAL_RCC_USART1_CLK_ENABLE();

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;

  if(HAL_UART_Init(&huart1) != HAL_OK)
  {
    return false;
  }

  return true;
}
//-----------------------------------------------------------------------//
