#include <stdio.h>

int getOption(){
	int opc;
		
	printf("\n[1] Consultar \n");
	printf("[2] Set bit \n");
	printf("[3] Tooggle \n");
	printf("Opcion ->");
	scanf("%d", &opc);
	return opc;
	
}

int main(void){
	unsigned short int numero, ex_bit;
	int bit;
	
	printf("Ingrese un numero ->");
	scanf("%hu", &numero);
	
	for(int i = 15; i>=0; i--){
		printf("%d", (numero & (1<<i) ) >0);
	}

	int opc = getOption();
	printf("Bit -> ");
	scanf("%d", &bit);
		
	if((bit >= 0 && bit <=15) && (opc >=1 && opc <=3)){

		if(opc == 1){
				ex_bit = (numero & (1<<bit)) > 0;
				printf("\nEl bit es -> %u\n",ex_bit);
			

		}
		else if(opc == 2){
				numero = numero | (1<<bit);				
	
		}
		else if(opc == 3){
			ex_bit = numero & (1<<bit);
			
			ex_bit = ex_bit ^ (1<<bit);
			numero = numero & ~(1<<bit);
			numero = numero | ex_bit;

		}
		for(int i = 15; i>=0; i--){
			if(i == bit){
				printf("[%d]", (numero & (1<<i) ) >0);
				continue;
			}
			printf("%d", (numero & (1<<i) ) >0);
			
		}

	}	

	
	printf("\nnumero -> %d", numero);
	
	printf("\n");
	
		

	



	return 0;
}