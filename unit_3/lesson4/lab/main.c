#include <stdint.h>
//register address


#define SYSCTL_RCGC2_R    (*((volatile uint32_t*)0x400FE108))
#define GPIO_PORTF_DIR_R  (*((volatile uint32_t*)0x40025400))
#define GPIO_PORTF_DEN_R  (*((volatile uint32_t*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile uint32_t*)0x400253FC))


int main()
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x00000020;
	//delay to make sure GPIO is up
	for(delay_count=0;delay_count <200; delay_count++);
	GPIO_PORTF_DIR_R |= 1<<3;  //dir is output for pin 3port FP_OF
	GPIO_PORTF_DEN_R |= 1<<3;
	

    while(1){
		
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count=0;delay_count <200; delay_count++);
        GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count=0;delay_count <200; delay_count++);
    }
	return 0;
}
