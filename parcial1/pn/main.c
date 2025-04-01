#include <stdio.h>

int getOption(){
	int option;
	printf("\n[1] Capturar arreglo\n");
	printf("[2] Mostrar arreglo\n");
	printf("[3] Encontrar maximo\n");
	printf("[4] Encontrar minimo\n");
	printf("[5] Ordenar arreglo\n");
	printf("[6] Salir\nOpcion-> ");
	scanf("%d", &option);
	return option;

	

}


int main(void){
	
	const int arraySize = 6;
	float numbers[arraySize], nMayor=-1000, nMenor = 9999, ban=0;
	int run=1;
		
	while(run){
		nMayor=-1000;
		nMenor = 9999;
		switch(getOption()){
			case 1:
				for(int i = 0; i < arraySize; i++){
					printf("Ingrese valor en indice [%d] ->", i);
					scanf("%f", &numbers[i]);
					while(getchar()!='\n');

					
				}
				break;
			case 2:
				printf("------\n");
				for(int i = 0; i < arraySize; i++){
					printf("[%d] -> '%f' \n", i, numbers[i]);
					
				}
				printf("------\n");
				break;
			case 3:
				
				for(int i = 0; i < arraySize; i++){
					if(numbers[i] > nMayor) nMayor = numbers[i];
					
				}
				printf("Numero maximo del arreglo -> %f\n", nMayor);
				break;
			case 4:
				
				for(int i = 0; i < arraySize; i++){
					if(numbers[i] < nMenor) nMenor = numbers[i];
					
				}
				printf("Numero menor del arreglo -> %f\n", nMenor);
				break;
			case 5:
				
				for(int i = 0; i < arraySize; i++){
					for(int j = i; j < arraySize-1; j++){
						if(numbers[i] > numbers[j+1]){
							ban = numbers[i];
							numbers[i] = numbers[j+1];
							numbers[j+1] = ban;

						};
					
						
					}
				}
				break;

			case 6:
				run = 0;
				break;
	
		
		
		}


	}

	
	


	return 0;
}