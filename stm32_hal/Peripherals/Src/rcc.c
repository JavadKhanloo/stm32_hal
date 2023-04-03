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
#include "rcc.h"

//-----------------------------------------------------------------------//

//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//
/*
// rcc clock configuration
*/
bool rcc_system_clock_config(void)
{
    // HSE = 8MHz
    // PLL_M = 9
    // USB Prescaler = 1.5
    // AHB Prescaler = 1
    // Cortex Prescaler = 1

    // APB1 Prescaler = 2 => 36, 72 MHz
    // APB2 Prescaler = 1 => 72, 72 MHz
    // ADC Prescaler = 6 => 12 MHz

    RCC_OscInitTypeDef osc_init_struct = {0};
    RCC_ClkInitTypeDef clk_init_struct = {0};

    osc_init_struct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    osc_init_struct.HSEState = RCC_HSE_ON;
    osc_init_struct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    osc_init_struct.PLL.PLLState = RCC_PLL_ON;
    osc_init_struct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    osc_init_struct.PLL.PLLMUL = RCC_PLL_MUL9;

    if(HAL_RCC_OscConfig(&osc_init_struct) != HAL_OK)
    {
      return false;
    }

    // clock initialization
    clk_init_struct.ClockType = RCC_CLOCKTYPE_HCLK   |
                                RCC_CLOCKTYPE_PCLK1  |
                                RCC_CLOCKTYPE_PCLK2  |
                                RCC_CLOCKTYPE_SYSCLK ;

    clk_init_struct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    clk_init_struct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clk_init_struct.APB1CLKDivider = RCC_SYSCLK_DIV2;
    clk_init_struct.APB2CLKDivider = RCC_SYSCLK_DIV1;
    // 00 - 24MHz => 0
    // 24 - 48MHz => 1
    // 48 - 72MHz => 2
    if(HAL_RCC_ClockConfig(&clk_init_struct, FLASH_LATENCY_2) != HAL_OK)
    {
      return false;
    }

    return true;
}

//-----------------------------------------------------------------------//
