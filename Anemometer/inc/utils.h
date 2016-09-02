/* -------------------------------------------------------------------------
@file utils.h

@date
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Utilitys functions
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

#ifndef UTILS_H
#define UTILS_H

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include"main.h"

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void vPrintString(uint8_t * string);

void vPrintNumber(portBASE_TYPE number);

void vPrintStringAndNumber(char * string, portBASE_TYPE number);

char* itoa(portBASE_TYPE value, char * result, int base);

#endif
