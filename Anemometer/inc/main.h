/* -------------------------------------------------------------------------
@file main.h

@date 08/29/16 13:58:21
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
#ifndef _MAIN_H
#define _MAIN_H
/*-------------------------------------------------------------------------
                        includes
---------------------------------------------------------------------------*/
/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"
/* sAPI includes */
#include "sAPI.h"
#include "board.h"
/* proyect includes */
#include "utils.h"
#include "uart.h"
#include "init.h"

#include "ciaaGPIOINT.h"
#include "portmacro.h"
/*-------------------------------------------------------------------------
                        defines
---------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
                        global variables
---------------------------------------------------------------------------*/
typedef struct
{
   int      iSource;
   uint8_t  uiMessage;
}xMetaData;


#endif
