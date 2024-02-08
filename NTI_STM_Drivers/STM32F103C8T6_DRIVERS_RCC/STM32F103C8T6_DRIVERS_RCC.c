/*
 * STM32F103C8T6_DRIVERS_RCC.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Belal
 */



#include "RCC_int.h"
#include "RCC_config.h"
#include "RCC_registers.h"
#include "STD_TYPES.h"
#include "Bit_math.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize RCC	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void MRCC_voidInit(void)
{


		#if 	CLOCK_TYPE == HSI
		/* internal 8 MHZ RC oscillator 			*/
		/*	HSI clock enable						*/
		//Bit 0 HSION: Internal high-speed clock enable
		setBit(MRCC->CR,0);
		while((getbit(MRCC->CR,1)==0) );
		/*HSI selected as system clock		*/


		/*	HSI Ready Flag					*/
		//Bit 16 HSEON: HSE clock enable





		#elif	CLOCK_TYPE == HSE
				/*	HSE clock enable				*/
				setBit(MRCC->CR, 16);
				while((getbit(MRCC->CR,17)==0) );
				/*HSE selected as system clock		*/
				setBit(MRCC->CFGR, 0);

				/*	HSE Ready Flag					*/
				//if((MRCC->CFGR)& 0x0 ){}

		#elif	CLOCK_TYPE == PLL
				/*	The PLL output frequency must not exceed 72 MHz */
				/*PLL selected as system clock		*/


		/*PLL multiplication factor*/
		#if CLOCK_FACTOR == MULTIPLY_BY_2


		#elif CLOCK_FACTOR == MULTIPLY_BY_3


		#elif CLOCK_FACTOR == MULTIPLY_BY_4


		#elif CLOCK_FACTOR == MULTIPLY_BY_5



		#elif CLOCK_FACTOR == MULTIPLY_BY_6



		#elif CLOCK_FACTOR == MULTIPLY_BY_7

		#elif CLOCK_FACTOR == MULTIPLY_BY_8


		#elif CLOCK_FACTOR == MULTIPLY_BY_9


		#elif CLOCK_FACTOR == MULTIPLY_BY_10


		#elif CLOCK_FACTOR == MULTIPLY_BY_11



		#elif CLOCK_FACTOR == MULTIPLY_BY_12


		#elif CLOCK_FACTOR == MULTIPLY_BY_13


		#elif CLOCK_FACTOR == MULTIPLY_BY_14


		#elif CLOCK_FACTOR == MULTIPLY_BY_15


		#elif CLOCK_FACTOR == MULTIPLY_BY_16


		#else
			#warning	"Wrong Multiplication factor!"

		#endif

					#if 	PLL_SOURCE	==	PLL_HSI_DIVIDED_BY_2
							/*PLL entry clock source is HSI divdided by 2		*/

					#elif	PLL_SOURCE	==	PLL_HSE
							/*PLL entry clock source is HSE						*/

							/*HSE divider for PLL entry : clock not divided 	*/

					#elif	PLL_SOURCE	==	PLL_HSE_DIVIDED_BY_2
							/*PLL entry clock source is HSE						*/

							/*HSE divider for PLL entry : clock divided		 	*/

					#endif

				/*	PLL clock enable				*/

				/*	PLL Ready Flag					*/

		#else

			#error		"Wrong Clock System type congiguration!"

		#endif
		/*FOR Clock Security System				*/
		#if		CLOCK_SECURITY_SYSTEM	==	OFF


		#elif	CLOCK_SECURITY_SYSTEM	==	ON

		#else
				#warning	"Wrong clock security system configuration choice!"
		#endif

}

ErrorStatus MRCC_enumSetPeripheralClock(uint8 Copy_u8PeripheralBus , uint8 Copy_u8PeripheralName , uint8 Copy_u8PeripheralState )
{
	ErrorStatus	LOC_enumstate = Rcc_no_error ;
	switch( Copy_u8PeripheralState )
	{
		case	RCC_ENABLE 	:
							switch( Copy_u8PeripheralBus )
							{
								case AHB  :	setBit((MRCC->AHBENR) , Copy_u8PeripheralName );break;
								case APB1 :	setBit( (MRCC->APB1ENR) ,  Copy_u8PeripheralName );break;
								case APB2 : setBit( (MRCC->APB2ENR) , Copy_u8PeripheralName  );break;
								default	  :	break;
							}
							break;
		case	RCC_DISABLE :
							switch( Copy_u8PeripheralBus )
							{
								case AHB  :	clearBit( (MRCC->AHBENR) ,  Copy_u8PeripheralName );
								break;
								case APB1 :	clearBit( (MRCC->APB1ENR) , Copy_u8PeripheralName  );
								break;
								case APB2 : clearBit( (MRCC->APB2ENR) , Copy_u8PeripheralName  );
								break;
								default	  :
								break;
							}
							break;
		case	RCC_RESET	:
							switch( Copy_u8PeripheralBus )
							{
								case APB1 :	setBit( (MRCC->APB1ENR) ,  Copy_u8PeripheralName );break;
								case APB2 : setBit( (MRCC->APB2ENR) , Copy_u8PeripheralName   );break;
								default	  :	break;
							}
							break;
	}
	return LOC_enumstate;
}
