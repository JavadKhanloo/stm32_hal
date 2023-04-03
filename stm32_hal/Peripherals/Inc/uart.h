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
// header gaurd                                                          //
//-----------------------------------------------------------------------//
#ifndef _UART_H_
#define _UART_H_

#include "main.h"

extern UART_HandleTypeDef huart1;
//-----------------------------------------------------------------------//
// function definition                                                   //
//-----------------------------------------------------------------------//

/*
// @brief UART1 GPIO configuration
*/
void uart_UART1_GPIO_config(void);
/*
// @brief UART1 Peripheral configuration
*/
bool uart_UART1_config(void);
//-----------------------------------------------------------------------//
#endif
//-----------------------------------------------------------------------//
