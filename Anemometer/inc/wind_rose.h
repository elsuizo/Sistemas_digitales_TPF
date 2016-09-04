/* -------------------------------------------------------------------------
@file wind_rose.h

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
#ifndef _WIND_ROSE_H_
#define _WIND_ROSE_H_


/*-------------------------------------------------------------------------
                              includes
-------------------------------------------------------------------------*/
#include "main.h"

/*-------------------------------------------------------------------------
                              defines
---------------------------------------------------------------------------*/
/* macro for check the range states */
#define CHECK(x,limit1, limit2) ((x) > (limit1) && (x) < (limit2) ? 1 : 0)
#define WIND_ROSE_POOLING_PERIOD 10


/*-------------------------------------------------------------------------
Max and Min sensor states
+-------+-------+-------+
| State |  Max  |  Min  |
+-------+-------+-------+
| N     |   114 |     0 |
| NNO   |   487 |   408 |
| NO    |   407 |   358 |
| NOO   |   809 |   758 |
| O     |   757 |   680 |
| SOO   |   914 |   870 |
| SO    |   869 |   810 |
| SSO   |  1023 |   950 |
| S     |   934 |   915 |
| SSE   |   949 |   935 |
| SE    |   589 |   488 |
| SEE   |   679 |   590 |
| E     |   281 |   220 |
| NEE   |   357 |   282 |
| NE    |   169 |   115 |
| NNE   |   219 |   170 |
+-------+-------+-------+
-------------------------------------------------------------------------*/
/* N state */
#define  N_MAX    114
#define  N_MIN    0
/* NNO state */
#define  NNO_MAX  487
#define  NNO_MIN  408
/* NO state */
#define  NO_MAX   407
#define  NO_MIN   358
/* NOO state */
#define  NOO_MAX  809
#define  NOO_MIN  758
/* O state */
#define  O_MAX    757
#define  O_MIN    680
/* SOO state */
#define  SOO_MAX  914
#define  SOO_MIN  870
/* SO state */
#define  SO_MAX   869
#define  SO_MIN   810
/* SSO state */
#define  SSO_MAX  1023
#define  SSO_MIN  950
/* S state */
#define  S_MAX    934
#define  S_MIN    915
/* SSE state */
#define  SSE_MAX  949
#define  SSE_MIN  935
/* SE state */
#define  SE_MAX   589
#define  SE_MIN   488
/* SEE state */
#define  SEE_MAX  679
#define  SEE_MIN  590
/* E state */
#define  E_MAX    281
#define  E_MIN    220
/* NEE state */
#define  NEE_MAX  357
#define  NEE_MIN  282
/* NE state */
#define  NE_MAX   169
#define  NE_MIN   115
/* NEE state */
#define  NNE_MAX  219
#define  NNE_MIN  170

/*-------------------------------------------------------------------------
  global variables
  -------------------------------------------------------------------------*/
typedef enum{N, NNO, NO, NOO, O, SOO, SO, SSO, S, SSE, SE, SEE, E, NEE, NE, NNE} wind_states_t;

typedef struct
{
   DigitalIOMap_t pin_row;
   DigitalIOMap_t pin_column;
}wind_states_map;

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void prvWindRoseGetDirection(void *pvParameters);

void do_state(wind_states_t wind_state);

#endif
