/* -------------------------------------------------------------------------
@file main.c

@date 08/29/16 13:55:28
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Anemometer
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
/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/

int main(void)
{
   /* Edu-Ciaa hardware initialization*/
   vInitHardware();
   /* UART initialization @ 115200 bauds */
   vUartInit(115200);
   vUartPrint("Hola desde el main")
   return 0;
}
