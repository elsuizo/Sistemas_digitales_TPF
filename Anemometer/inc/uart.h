/* -------------------------------------------------------------------------
@file uart.h

@date
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
#ifndef _UART_H_
#define _UART_H_

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

/*-------------------------------------------------------------------------
                              defines
---------------------------------------------------------------------------*/
#define  UART_MAX_QUEUE_ELEMENTS 2

/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/
/* queue for the UART */
xQueueHandle xUARTQueue;

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void vUartInit(portBASE_TYPE xBaudRate);

void vUartGatekeeperTask(void *pvParameters);

#endif
