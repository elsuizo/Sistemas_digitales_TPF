/* -------------------------------------------------------------------------
@file time_controller.h

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
#ifndef _TIME_CONTROLLER_H_
#define _TIME_CONTROLLER_H_

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

/*-------------------------------------------------------------------------
                              defines
---------------------------------------------------------------------------*/
#define SIGNAL_MESSAGE_PERIOD 1000

/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/
xSemaphoreHandle xTimeSignal;

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void prvTimeControllerTask(void *pvParameters);


#endif
