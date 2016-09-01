/* -------------------------------------------------------------------------
@file wind_rose.c

@date 08/31/16 16:51:53
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
   while(1)
   {
      vTaskDelay(WIND_ROSE_POOLING_PERIOD / portTICK_RATE_MS);
      
   }
}
