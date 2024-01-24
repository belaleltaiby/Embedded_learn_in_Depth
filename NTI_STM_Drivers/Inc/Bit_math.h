/*
 * Bit_math.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Belal
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define setBit(byte,nbit)        byte |= (1<<nbit)
#define clearBit(byte,nbit)      byte &= ~(1<<nbit)
#define toggleBit(byte,nbit)     byte ^= (1<<nbit)
#define getbit(byte,nbit)         ((byte>>nbit) & 0x01)


#endif /* BIT_MATH_H_ */
