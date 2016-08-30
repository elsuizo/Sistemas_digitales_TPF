/* -------------------------------------------------------------------------
@file UART.c

@date 08/29/16 15:03:17
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
#include"uart.h"
#include"main.h"
/*-------------------------------------------------------------------------
                              functions
-------------------------------------------------------------------------*/

void vUartInit(portBASE_TYPE xBaudRate)
{
   /* initialize the sAPI uart API */
   uartConfig(UART_USB, xBaudRate);
   /* Create a queue for the UART */
   xUARTQueue = xQueueCreate(UART_MAX_QUEUE_ELEMENTS, sizeof( xMetaData ) );
}
/*-------------------------------------------------------------------------
                              tasks
-------------------------------------------------------------------------*/

void vUartGatekeeperTask( void *pvParameters )
{
   xMetaData xReceived;
   portBASE_TYPE xStatus;

   if(xUARTQueue != NULL)
   {
      while(1)
      {
         /* Wait for a message to arrive. */
         xStatus = xQueueReceive(xUARTQueue, &xReceived, portMAX_DELAY);

         if(xStatus == pdPASS)
         {
            switch(xReceivedStruct.iSource)
            {
               case mainSENDER_1:
                  {
                     break;
                  }
               case mainSENDER_2:
                  {
                     break;
                  }
               case mainSENDER_3:
                  {
                     break;
                  }
            }
         }
         else
         {
            vPrintString("Error!!!");
         }

      }
   }
}

