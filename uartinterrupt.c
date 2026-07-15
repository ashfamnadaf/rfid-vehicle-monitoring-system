/*uart0_interrupt.c */
#include <LPC21xx.H>
#include"header.h"
 unsigned int i;
 char temp[60];
void UART0_handler(void)__irq{
int r=U0IIR;
if(r&4){
temp[i]=U0RBR;
i++;
//U0THR=i;
}
if(r&2){
}
VICVectAddr =0;
}
void config_vic(void){
VICIntSelect=0;
VICVectCntl0=6|(1<<5);
VICVectAddr0=(int)UART0_handler;
VICIntEnable|=(1<<6);
}
void en_uart0_interrupt(void){
U0IER=0x03;
}
