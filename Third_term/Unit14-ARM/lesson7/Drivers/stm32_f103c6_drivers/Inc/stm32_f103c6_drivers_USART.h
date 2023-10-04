/*
 * stm32_f103c6_drivers_EXTI.h
 *
 *  Created on: Jan 6, 2023
 *      Author: Belal
 */

#ifndef INC_STM32_F103C6_DRIVERS_USART_H_
#define INC_STM32_F103C6_DRIVERS_USART_H_

//includes
#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_GPIO.h"
#include "stm32_f103c6_drivers_RCC.h"


//configration structure
typedef struct{
	uint8_t  mode ;                //specifies Tx/Rx
									// must be set // @ref UART_MODE_define
	uint32_t Baudrate;              //@ref BaudRate_define
	uint8_t  Payload_lenght;         //@ref length_define
	uint8_t  stopBits;                 //@ref UART_stopBits_define
	uint8_t  parity;                  //@ref parity_define
	uint8_t  flowCtrl;                 //@ref Hw_flowCtrl_define
	uint8_t  IRQ_Enable;               //@ref UART_IRQ_define

	void (*P_IRQ_callback)(void);
}UART_config_t;


/*typedef struct{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;

}USART_Typedef;*/


//@ref UART_IRQ_define       //SR reg
#define UART_IRQ_PE                     (uint32_t)(1<<8)
#define UART_IRQ_TXE                    (uint32_t)(1<<7)
#define UART_IRQ_TC                 	(uint32_t)(1<<6)
#define UART_IRQ_RXNE					(uint32_t)(1<<5)     //	1: Received data is ready to be read
#define UART_IRQ_none					(uint32_t)0


// @ref UART_MODE_define
#define UART_MODE_Tx                   (uint32_t)(1<<3)            //Bit 3 TE: Transmitter enable
#define UART_MODE_Rx                   (uint32_t)(1<<2)            //Bit 2 RE: Receiver enable
#define UART_MODE_Rx_Tx                (uint32_t)(1<<2 | 1<<3)

//@ref UART_Payload_lenght_define
#define UART_Payload_lenght_8           (uint32_t) (0)
#define UART_Payload_lenght_9           (uint32_t) (1<<12)


//@ref BaudRate_define
#define BaudRate_2400            2400
#define BaudRate_9600            9600
#define BaudRate_19200           19200
#define BaudRate_57600           57600
#define BaudRate_115200          115200
#define BaudRate_230400          230400
#define BaudRate_460800          460800
#define BaudRate_921600          921600
#define BaudRate_2250000         2250000

//@ref parity_define
#define parity_none                   (uint32_t)0
#define parity_even                   (uint32_t)(1<<10)
#define parity_odd                    (uint32_t)(1<<10  | 1<<9)


//@ref Hw_flowCtrl_define
#define Hw_flowCtrl_none              (uint32_t)0
#define Hw_flowCtrl_CTS               (uint32_t)(1<<9)
#define Hw_flowCtrl_RTS               (uint32_t)(1<<8)
#define Hw_flowCtrl_CTS_RTS           (uint32_t)(1<<9 |1<<8)



//@ref UART_stopBits_define
#define UART_stopBits_1               (uint32_t)0
#define UART_stopBits_half            (uint32_t)(1<<12)
#define UART_stopBits_2               (uint32_t)(2<<12)
#define UART_stopBits_1_half          (uint32_t)(3<<12)

enum polling_mechanism{enable,disable};

///////
#define USART_DIV(Fclk,baudrate)                    (uint32_t) (Fclk/(baudrate*16))
#define USART_DIV_MUL100(Fclk,baudrate)  		    (uint32_t) ((Fclk*25)/(baudrate*4))
#define MANTISSA_MUL100(Fclk,baudrate)              (uint32_t) (USART_DIV(Fclk,baudrate) *100)
#define MANTISSA(Fclk,baudrate)                     (uint32_t) (USART_DIV(Fclk,baudrate))
#define DIV_FRACTION(Fclk,baudrate)                 (uint32_t) (((USART_DIV_MUL100(Fclk,baudrate) - MANTISSA_MUL100(Fclk,baudrate))*16)/100)
#define UART_BRR_Register(Fclk,baudrate)            ( (MANTISSA(Fclk,baudrate)) <<4)|((DIV_FRACTION(Fclk,baudrate)) & 0xF )

//--------------------APIs---------------------//
void Mcal_UART_init(USART_Typedef * USARTx,UART_config_t* UART_conf);
void Mcal_UART_Deinit(USART_Typedef * USARTx);
void Mcal_UART_GPIO_set(USART_Typedef * USARTx);
void Mcal_UART_Tx(USART_Typedef * USARTx,uint16_t* data,enum polling_mechanism pollingEn);
void Mcal_UART_Rx(USART_Typedef * USARTx,uint16_t* data,enum polling_mechanism pollingEn);
void MCAL_UART_WAIT_TC (USART_Typedef * USARTx );

#endif /* INC_STM32_F103C6_DRIVERS_USART_H_ */
