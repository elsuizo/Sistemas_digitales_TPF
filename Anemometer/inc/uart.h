/* -------------------------------------------------------------------------
@file UART.h

@date 08/29/16 15:24:31
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#ifndef __UART_H
#define __UART_H
/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

/*-------------------------------------------------------------------------
                        defines
---------------------------------------------------------------------------*/
#define  UART_MAX_QUEUE_ELEMENTS  9
#define  mainSENDER_1             1
#define  mainSENDER_2             2
/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/
/* maximum message length for the queue */
/* queue for the UART */
xQueueHandle xUARTQueue;
/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void vUartInit(portBASE_TYPE xBaudRate);

void vUartGatekeeperTask(void *pvParameters);

#endif
