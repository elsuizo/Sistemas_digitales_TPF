/* -------------------------------------------------------------------------
@file alarm.h

@date 09/04/16 18:31:22
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
#ifndef _ALARM_H_
#define _ALARM_H_
/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

/*-------------------------------------------------------------------------
                              defines
---------------------------------------------------------------------------*/
#define  ALARM_POOLING_PERIOD      10
/* Alarm messages */
#define  ALARM_MESSAGE_1           1
#define  ALARM_MESSAGE_2           2
/* Alarm queue */
#define  ALARM_QUEUE_MAX_ELEMENTS  3
/* Alarm periods */
#define  ALARM_BEEP_WARNIG_PERIOD  300
#define  ALARM_BEEP_DESASTER       100
/*-------------------------------------------------------------------------
                              global variables
-------------------------------------------------------------------------*/
xQueueHandle xALARMQueue;

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
prvAlarmActivateTask(void *pvParameters);

#endif
