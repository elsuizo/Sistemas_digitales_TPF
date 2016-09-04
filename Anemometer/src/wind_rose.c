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
  global variables
  -------------------------------------------------------------------------*/
wind_states_map wind_states_pins[] = 
{
   /*row    column */
   {0,      DIO12}, /* N state */
   {DIO31,  DIO13}, /* NNO state */
   {DIO30,  DIO13}, /* NO state */
   {DIO29,  DIO13}, /* NOO state */
   {0,      DIO13}, /* O state */
   {DIO31,  DIO14}, /* SOO state */
   {DIO30,  DIO14}, /* SO state */
   {DIO29,  DIO14}, /* SSO state */
   {0,      DIO14}, /* S state */
   {DIO31,  DIO15}, /* SSE state */
   {DIO30,  DIO15}, /* SE state */
   {DIO29,  DIO15}, /* SEE state */
   {0,      DIO15}, /* E state */
   {DIO31,  DIO12}, /* NEE state */
   {DIO30,  DIO12}, /* NE state */
   {DIO19,  DIO12}  /* NNE state */

};
/*-------------------------------------------------------------------------
                              Task implementattions
-------------------------------------------------------------------------*/
void prvWindRoseGetDirection(void *pvParameters)
{
   /* initial state */
   wind_states_t wind_states = N;
   /* task metadata message for the Gatekeeper */
   xMetaData xWindRoseMessage;
   xWindRoseMessage.xSource = SENDER_WIND_ROSE;
   portBASE_TYPE uartBuff[10];
   portBASE_TYPE sample = 0;

   while(1)
   {
      vTaskDelay(WIND_ROSE_POOLING_PERIOD / portTICK_RATE_MS);
      /* read the analog sensor value */
      sample = analogRead(AI0);
      /* convert the sample to decimal number */
      itoa(sample, uartBuff, 10);
      /* N */
      if(CHECK(sample, N_MIN, N_MAX))
      {
         wind_states = N;
         do_state(wind_states);
      }
      /* NNO */
      if(CHECK(sample, NNO_MIN, NNO_MAX))
      {
         wind_states = NNO;
         do_state(wind_states);
      }
      /* NO */
      if(CHECK(sample, NO_MIN, NO_MAX))
      {
         wind_states = NO;
         do_state(wind_states);
      }
      /* NOO */
      if(CHECK(sample, NOO_MIN, NOO_MAX))
      {
         wind_states = NOO;
         do_state(wind_states);
      }
      /* O */
      if(CHECK(sample, O_MIN, O_MAX))
      {
         wind_states = O;
         do_state(wind_states);
      }
      /* SOO */
      if(CHECK(sample, SOO_MIN, SOO_MAX))
      {
         wind_states = SOO;
         do_state(wind_states);
      }
      /* SO */
      if(CHECK(sample, SO_MIN, SO_MAX))
      {
         wind_states = SO;
         do_state(wind_states);
      }
      /* SSO */
      if(CHECK(sample, SSO_MIN, SSO_MAX))
      {
         wind_states = SSO;
         do_state(wind_states);
      }
      /* S */
      if(CHECK(sample, S_MIN, S_MAX))
      {
         wind_states = S;
         do_state(wind_states);
      }
      /* SSE */
      if(CHECK(sample, SSE_MIN, SSE_MAX))
      {
         wind_states = SSE;
         do_state(wind_states);
      }
      /* SE */
      if(CHECK(sample, SE_MIN, SE_MAX))
      {
         wind_states = SE;
         do_state(wind_states);
      }
      /* SEE */
      if(CHECK(sample, SEE_MIN, SEE_MAX))
      {
         wind_states = SEE;
         do_state(wind_states);
      }
      /* E */
      if(CHECK(sample, E_MIN, E_MAX))
      {
         wind_states = E;
         do_state(wind_states);
      }
      /* NEE */
      if(CHECK(sample, NEE_MIN, NEE_MAX))
      {
         wind_states = NEE;
         do_state(wind_states);
      }
      /* NE */
      if(CHECK(sample, NE_MIN, NE_MAX))
      {
         wind_states = NE;
         do_state(wind_states);
      }
      /* NNE */
      if(CHECK(sample, NNE_MIN, NNE_MAX))
      {
         wind_states = NNE;
         do_state(wind_states);
      }

      xWindRoseMessage.xMessage = wind_states;
      xQueueSendToBack(xUARTQueue, (void *)&xWindRoseMessage, ( TickType_t )0);

   }
}

void do_state(wind_states_t wind_state)
{
   wind_states_t i;
   /* iterate over the states */
   for(i = N; i <= NNE; i++)
   {
      if(i == wind_state)
      {
         if(wind_states_pins[i].pin_row == 0)
         {
            digitalWrite(wind_states_pins[i].pin_column, ON);
         }
         else
         {
            digitalWrite(wind_states_pins[i].pin_row, ON);
            digitalWrite(wind_states_pins[i].pin_column, ON);
         }
      }
      else
      {
         digitalWrite(wind_states_pins[i].pin_row, OFF);
         digitalWrite(wind_states_pins[i].pin_column, OFF);

      }

   }
}

