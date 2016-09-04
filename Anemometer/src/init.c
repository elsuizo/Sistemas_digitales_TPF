/* -------------------------------------------------------------------------
@file init.c

@date 07/18/16 14:59:25
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
#include"init.h"

void vInitHardware(void)
{

   /* board initialization */
   boardConfig();

   Board_Init(); // <-- NECESARIO PARA QUE COMPILE

   //tickConfig(1, 0);
   /* enable analog input sAPI */
   analogConfig(ENABLE_ANALOG_INPUTS);
   // sAPI digitals pins initilization
   digitalConfig(0, ENABLE_DIGITAL_IO);

   /* digitalConfig( TEC1, INPUT ); */
   /* digitalConfig( TEC2, INPUT ); */
   /* digitalConfig( TEC3, INPUT ); */
   digitalConfig(TEC4, INPUT);
   /* Anemometer input */
   digitalConfig(DIO32, INPUT);

   /* Configuración de pines de salida para
   Leds de la CIAA-NXP */
   digitalConfig(LEDR, OUTPUT);
   digitalConfig(LEDG, OUTPUT);
   digitalConfig(LEDB, OUTPUT);
   digitalConfig(LED1, OUTPUT);
   digitalConfig(LED2, OUTPUT);
   digitalConfig(LED3, OUTPUT);
   /* GPIO OUTPUTS for the wind rose leds */
   /* Rows */
   digitalConfig(DIO31, OUTPUT); /* 2 row */
   digitalConfig(DIO30, OUTPUT); /* 4 row */
   digitalConfig(DIO29, OUTPUT); /* 6 row */
   /* Columns */
   digitalConfig(DIO15, OUTPUT); /* A column */
   digitalConfig(DIO14, OUTPUT); /* B column */
   digitalConfig(DIO13, OUTPUT); /* C column */
   digitalConfig(DIO12, OUTPUT); /* D column */

}
