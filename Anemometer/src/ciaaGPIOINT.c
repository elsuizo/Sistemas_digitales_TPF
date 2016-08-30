/* Copyright 2015, Pablo Ridolfi
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief GPIO interrupts source file
 **
 ** This is a simple example of a module using CIAA-Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup GPIOINT	GPIO Interrupts
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * PR			Pablo Ridolfi
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20150930 v0.0.1 PR initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaaGPIOINT.h"
/* #include "chip.h" */
/* #include "os.h" */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

void (*user_callbacks[1])(void);

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

extern int ciaaGpioIntEnable(uint8_t channel, void (*user_callback)(void) )
{
   int rv = -1;

   /* int8_t pinNamePort = 6; */
   /* int8_t pinNamePin  = 4; */
   /*  */
   /* int8_t func        = 1; */
   /*  */
   /* int8_t gpioPort    = 3; */
   /* int8_t gpioPin     = 3; */
   /*  */
   /* Chip_SCU_PinMux( */
   /*    pinNamePort, */
   /*    pinNamePin, */
   /*    SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS, */
   /*    func */
   /* ); */
   /* Chip_GPIO_SetDir( LPC_GPIO_PORT, gpioPort, ( 1 << gpioPin ), INPUT ); */
   /*  */
   /* Chip_PININT_Init(LPC_GPIO_PIN_INT); */

   if(channel == 0)
   {
      /* Set GPIO1[9] to IRQ Channel 0 */
      Chip_SCU_GPIOIntPinSel(channel, 1, 9);

      /* Falling edge IRQ */
      Chip_PININT_SetPinModeEdge(LPC_GPIO_PIN_INT, PININTCH0);
      //Chip_PININT_SetPinModeLevel(LPC_GPIO_PIN_INT, PININTCH0);

      Chip_PININT_EnableIntLow(LPC_GPIO_PIN_INT, PININTCH0);
      //Chip_PININT_EnableIntHigh(LPC_GPIO_PIN_INT, PININTCH0);

      user_callbacks[channel] = user_callback;

      NVIC_EnableIRQ(PIN_INT0_IRQn);
      rv = 0;
   }

   return rv;
}

/*==================[irq handlers]===========================================*/

ISR(GPIOINTHandler0)
{
	if(Chip_PININT_GetFallStates(LPC_GPIO_PIN_INT) & PININTCH0)
	{
		Chip_PININT_ClearIntStatus(LPC_GPIO_PIN_INT, PININTCH0);

		if(user_callbacks[0])
      {
         user_callbacks[0]();
      }

	}
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

