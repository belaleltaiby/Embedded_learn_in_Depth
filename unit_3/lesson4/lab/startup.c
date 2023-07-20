#include <stdint.h>
#define STACK_START_SP 0x20001000
extern int main(void);
void REST_HANDLER(void);

void DEFAULT_HANDLER(void){
	REST_HANDLER();
}
//booking 1024 b located .bss through uninitialized array of 256 elements

static unsigned long Stack_top[256];


void NMI_HANDLER(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;
void H_Fault_HANDLER(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;


void(* const g_p_fun_vectors[])() __attribute__((section(".vectors"))) =
{
   (void(*)()) (Stack_top + sizeof(Stack_top)),
   &REST_HANDLER,
   &NMI_HANDLER,
   &H_Fault_HANDLER,
};

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void REST_HANDLER(void)
{
	//copy data section from flash to ram
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char * P_src = (unsigned char*)&_E_text;
	unsigned char * P_dst = (unsigned char*)&_S_DATA;
	int j=0;
	for( j; j<DATA_SIZE; j++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	//init .bss section in sram =0
	unsigned int bss_SIZE = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss ;
	int i=0;
	for(i; i<bss_SIZE; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	
	//jump main
	main();
}