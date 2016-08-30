/* -------------------------------------------------------------------------
@file anemometer.h

@date 08/30/16 20:04:11
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
#ifndef _ANEMOMETER
#define _ANEMOMETER
/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"
/*-------------------------------------------------------------------------
                        defines
---------------------------------------------------------------------------*/
#define ANEMOMETER_POOLING_PERIOD 10
/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/
typedef enum{PIN_UP, PIN_FALLING, PIN_DOWN, PIN_RISING} pin_state_t;

#endif
