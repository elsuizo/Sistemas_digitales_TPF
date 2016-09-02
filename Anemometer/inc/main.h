/* -------------------------------------------------------------------------
@file main.h

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
#ifndef _MAIN_H_
#define _MAIN_H_

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
#include "init.h"
#include "uart.h"
#include "anemometer.h"
#include "time_controller.h"
#include "wind_rose.h"

int main(void);
/*-------------------------------------------------------------------------
                        defines
---------------------------------------------------------------------------*/
/* priority tasks values */
#define  PRIORITY_TASK_TIME_CONTROLLER  5
#define  PRIORITY_TASK_GATEKEEPER       4
#define  PRIORITY_TASK_TIME_ANEMOMETER  2
#define  PRIORITY_TASK_TIME_WIND_ROSE   2

/* ID Message */
#define  SENDER_ANEMOMETER  1
#define  SENDER_WIND_ROSE   2
#define  SENDER_PC          3

/*-------------------------------------------------------------------------
  global variables
  ---------------------------------------------------------------------------*/
typedef struct
{
   portBASE_TYPE  xSource;
   portBASE_TYPE  xMessage;
}xMetaData;


#endif
