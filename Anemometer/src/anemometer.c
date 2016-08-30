/* -------------------------------------------------------------------------
@file anemometer.c

@date 08/30/16 20:01:29
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Anemometer task
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
#include "anemometer.h"

void prvAnemometerTaks(void *pvParameters)
{
   portBASE_TYPE xFreq = 0;
   portBASE_TYPE xCounter = 0;
   pin_state_t pin_state = PIN_DOWN;

   while(1)
   {
      vTaskDelay(ANEMOMETER_POOLING_PERIOD / portTICK_RATE_MS);

      switch(pin_state)
      {
         case PIN_UP:
            {
               if(!digitalRead(DIO32))
                  pin_state = PIN_FALLING;
                  break;
            }
         case PIN_FALLING:
            {
               xCounter +=1;
               if(!digitalRead(DIO32))
               {
                  pin_state = PIN_DOWN;
                  freq++;
                  digitalWrite(LEDR, ON);
               }
               else
                  pin_state = PIN_UP;
                  break;
            }
         case PIN_DOWN:
            {
               if(digitalRead(DIO32))
                  pin_state = PIN_RISING;
                  break;
            }
         case PIN_RISING:
            {
               xCounter += 1;
               if(digitalRead(DIO32))
               {
                  pin_state = PIN_UP;
                  digitalWrite(LEDR, OFF);
               }
            else
               pin_state = PIN_DOWN;
            break;
         }
      }

      if(xSemaphoreTake(xTimeSignal, 0))
      {
         xQueueSendToBack(xUARTQueue, &xFreq, 0);
         xFreq = 0;
         xCounter = 0;
      }
   }

}

