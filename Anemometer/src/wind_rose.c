/* -------------------------------------------------------------------------
@file wind_rose.c

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
#include "wind_rose.h"

/*-------------------------------------------------------------------------
                              Task implementattions
-------------------------------------------------------------------------*/
void prvWindRoseGetDirection(void *pvParameters)
{
   wind_states_t wind_states = NO;
   xMetaData xWindRoseMessage;
   xWindRoseMessage.xSource = SENDER_WIND_ROSE;
   portBASE_TYPE uartBuff[10];
   portBASE_TYPE sample = 0;

   while(1)
   {
      vTaskDelay(WIND_ROSE_POOLING_PERIOD / portTICK_RATE_MS);
      sample = analogRead(AI0);
      itoa(sample, uartBuff, 10); /* 10 significa decimal */
      /* N */
      if(CHECK(sample, N_MIN, N_MAX))
      {
         wind_states = N;
      }
      /* NNO */
      if(CHECK(sample, NNO_MIN, NNO_MAX))
      {
         wind_states = NNO;
      }
      /* NO */
      if(CHECK(sample, NO_MIN, NO_MAX))
      {
         wind_states = NO;
      }
      /* NOO */
      if(CHECK(sample, NOO_MIN, NOO_MAX))
      {
         wind_states = NOO;
      }
      /* O */
      if(CHECK(sample, O_MIN, O_MAX))
      {
         wind_states = O;
      }
      /* SOO */
      if(CHECK(sample, SOO_MIN, SOO_MAX))
      {
         wind_states = SOO;
      }
      /* SO */
      if(CHECK(sample, SO_MIN, SO_MAX))
      {
         wind_states = SO;
      }
      /* SSO */
      if(CHECK(sample, SSO_MIN, SSO_MAX))
      {
         wind_states = SSO;
      }
      /* S */
      if(CHECK(sample, S_MIN, S_MAX))
      {
         wind_states = S;
      }
      /* SSE */
      if(CHECK(sample, SSE_MIN, SSE_MAX))
      {
         wind_states = SSE;
      }
      /* SE */
      if(CHECK(sample, SE_MIN, SE_MAX))
      {
         wind_states = SE;
      }
      /* SEE */
      if(CHECK(sample, SEE_MIN, SEE_MAX))
      {
         wind_states = SEE;
      }
      /* E */
      if(CHECK(sample, E_MIN, E_MAX))
      {
         wind_states = E;
      }
      /* NEE */
      if(CHECK(sample, NEE_MIN, NEE_MAX))
      {
         wind_states = NEE;
      }
      /* NE */
      if(CHECK(sample, NE_MIN, NE_MAX))
      {
         wind_states = NE;
      }
      /* NNE */
      if(CHECK(sample, NNE_MIN, NNE_MAX))
      {
         wind_states = NNE;
      }

      xWindRoseMessage.xMessage = wind_states;
      xQueueSendToBack(xUARTQueue, (void *)&xWindRoseMessage, ( TickType_t )0);

   }
}
