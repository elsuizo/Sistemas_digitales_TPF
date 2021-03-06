/* -------------------------------------------------------------------------
@file main.c

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

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

int main(void)
{
   /*-------------------------------------------------------------------------
                              Inits
   -------------------------------------------------------------------------*/
   /* Edu-Ciaa hardware initialization*/
   vInitHardware();
   /* UART initialization @ 115200 bauds */
   vUartInit(115200);
   vSemaphoreCreateBinary(xTimeSignal);
   /* create a ALARM queue */
   xALARMQueue = xQueueCreate(2, sizeof(portBASE_TYPE));
   /*-------------------------------------------------------------------------
                              Task creation
   -------------------------------------------------------------------------*/
   /* Time Controller Task */
   xTaskCreate(
               prvTimeControllerTask,
               (const char *)"Time_controller",
               configMINIMAL_STACK_SIZE*2,
               NULL,
               tskIDLE_PRIORITY + PRIORITY_TASK_TIME_CONTROLLER,
               NULL
               );
   /* Gatekeeper Task */
   xTaskCreate(
               vUartGatekeeperTask,
               (const char *)"Gatekeeper",
               configMINIMAL_STACK_SIZE*2,
               NULL,
               tskIDLE_PRIORITY + PRIORITY_TASK_GATEKEEPER,
               NULL
               );
   /* Anemometer Task */
   xTaskCreate(
               prvAnemometerTaks,
               (const char *)"Anemometer",
               configMINIMAL_STACK_SIZE*2,
               NULL,
               tskIDLE_PRIORITY + PRIORITY_TASK_TIME_ANEMOMETER,
               NULL
               );
   /* Wind rose Task */
   xTaskCreate(
               prvWindRoseGetDirection,
               (const char *)"Wind_rose",
               configMINIMAL_STACK_SIZE*2,
               NULL,
               tskIDLE_PRIORITY + PRIORITY_TASK_TIME_WIND_ROSE,
               NULL
               );
   /* Alarm Task */
   xTaskCreate(
               prvAlarmActivateTask,
               (const char *)"Alarm",
               configMINIMAL_STACK_SIZE*2,
               NULL,
               tskIDLE_PRIORITY + PRIORITY_TASK_ALARM,
               NULL
               );
   /* Start Scheduler */
   vTaskStartScheduler();

   while(1)
   {

   }

   return 0;
}
