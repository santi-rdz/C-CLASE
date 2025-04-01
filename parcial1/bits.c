#include <stdio.h>

int main(void){
	
 	unsigned int valor = 269582464;
	unsigned int mostValor = valor>>16;
	int lessValor = valor & 0xFFFF;
	
	printf("\nIngrese un numero positivo -> %u\n", valor);
		

	printf("Most significant bits -> %u\n", mostValor);
	printf("Less significant bits -> %u\n", lessValor);
	  	

  unsigned int intercambio = 0;
  intercambio |= lessValor << 16;
  intercambio |= mostValor;

	printf("change between most and less -> %u", intercambio);
	

  return 0;

}