/* -------------------------------------------------------------------------
@file time_controller.c

@date 08/30/16 19:28:40
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Implementation of time Controller Task
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

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "time_controller.h"

/*-------------------------------------------------------------------------
                              Task implementattions
-------------------------------------------------------------------------*/
void prvTimeControllerTask(void *pvParameters)
{
   portTickType xLastWakeTime;
   xLastWakeTime = xTaskGetTickCount();
   while(1)
   {
      vTaskDelayUntil( &xLastWakeTime, (SIGNAL_MESSAGE_PERIOD / portTICK_RATE_MS));
      //vPrintString("HOLA");
      xSemaphoreGive(xTimeSignal);

   }

}
