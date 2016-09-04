/* -------------------------------------------------------------------------
@file alarm.c

@date 09/04/16 18:20:04
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
/* TODO(elsuizo): hacer la alarma un poco mas alarmante :) */
#include "alarm.h"


prvAlarmActivateTask(void *pvParameters)
{
   portBASE_TYPE xTemp;

   while(1)
   {
      vTaskDelay(ALARM_POOLING_PERIOD / portTICK_RATE_MS);
      xQueueReceive(xALARMQueue, &xTemp,  portMAX_DELAY);
      if(xTemp == ALARM_MESSAGE_1)
      {
         digitalWrite(DIO11, ON);
         vTaskDelay(ALARM_BEEP_WARNIG_PERIOD / portTICK_RATE_MS);
         digitalWrite(DIO11, OFF);
      }
      if(xTemp == ALARM_MESSAGE_2)
      {
         digitalWrite(DIO11, ON);
         vTaskDelay(ALARM_BEEP_DESASTER / portTICK_RATE_MS);
         digitalWrite(DIO11, OFF);
      }
   }


}

