/* -------------------------------------------------------------------------
@file anemometer.h

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
#ifndef _ANEMOMETER_H_
#define _ANEMOMETER_H_

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

/*-------------------------------------------------------------------------
                        defines
---------------------------------------------------------------------------*/
#define FREQUENCY_ALARM_THRESHOLD_1  4
#define FREQUENCY_ALARM_THRESHOLD_2  5
/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void prvAnemometerTaks(void *pvParameters);


#endif
