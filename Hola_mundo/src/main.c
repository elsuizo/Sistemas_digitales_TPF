/* -------------------------------------------------------------------------
@file main.c

@date 08/25/16 11:36:42
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Hello world for the enemometer
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
#include "main.h"

/*-------------------------------------------------------------------------
                        prototypes
---------------------------------------------------------------------------*/
static void appIrqHandler(void);

/*-------------------------------------------------------------------------
                        global variables
---------------------------------------------------------------------------*/
uint8_t uiFrequency;
/*-------------------------------------------------------------------------
                        main
---------------------------------------------------------------------------*/
int main(void)
{
   boardConfig();

   /* inicializar el conteo de Ticks con resolucion de 1ms, sin tickHook */
   tickConfig(1, 0);

   digitalConfig(1, ENABLE_DIGITAL_IO);
   /* inicializar DigitalIO */

   /*  configuracion de pines de entrada para Teclas de la CIAA-NXP */
   /* digitalConfig(TEC1, INPUT); */
   /* digitalConfig(TEC2, INPUT); */
   /* digitalConfig(TEC3, INPUT); */
   /* digitalConfig(TEC4, INPUT); */

   // configuracion de pines de salida para Leds de la CIAA-NXP
   digitalConfig(LEDR, OUTPUT);
   digitalConfig(LEDG, OUTPUT);
   digitalConfig(LEDB, OUTPUT);
   digitalConfig(LED1, OUTPUT);
   digitalConfig(LED2, OUTPUT);
   digitalConfig(LED3, OUTPUT);

   digitalConfig(DIO32, INPUT);
   digitalConfig(DIO5, OUTPUT);
   while(1)
   {
      if(digitalRead(DIO32))
      {
         digitalWrite(LEDB, ON);
      }
      else
      {
         digitalWrite(LEDB, OFF);
      }
   }
   return 0;
}


void appIrqHandler(void)
{
   digitalWrite(LEDR, ON);
}
