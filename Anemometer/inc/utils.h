/* -------------------------------------------------------------------------
@file utils.h

@date 07/18/16 15:01:59
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

#ifndef __UTILS_H
#define __UTILS_H

/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include"main.h"

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void vPrintString(uint8_t * string);
void vPrintNumber(uint32_t number);
void vPrintStringAndNumber(char * string, uint32_t number);

char* itoa(uint32_t value, char * result, int base);

#endif
