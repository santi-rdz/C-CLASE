#include <stdio.h>

int getOPtion(){
	int opt;
	printf("[1] Evaluar desempeno\n");
	printf("[2] Salir\n");
	printf("Ingrese opcion ->");
	scanf("%d", & opt);
	return opt;
	
}



int main(void){
	
	float prom = 0,acumCalif = 0, currentCal, calMasBaja=100;
	int cantC, run = 1;

	do{
		acumCalif = 0;
		calMasBaja = 100;
		switch(getOPtion()){
		
			case 1:
				printf("Cantidad de cursos -> ");
				scanf("%d", &cantC);
				
				for(int i = 0; i<cantC; i++){
				
					printf("Ingrese calificacion curso %d ->", (i+1));
					scanf("%f", &currentCal);
					acumCalif += currentCal;
					
					if(currentCal < calMasBaja ){
						calMasBaja = currentCal;
					}
			
				}	
				prom = acumCalif/cantC;
				printf("\nPromedio de calificacion -> %.2f ", prom);
	
    		if (prom >= 93)       printf("A\n");
    		else if (prom >= 90)  printf("A-\n");
    		else if (prom >= 87)  printf("B+\n");
    		else if (prom >= 83)  printf("B\n");
    		else if (prom >= 80)  printf("B-\n");
    		else if (prom >= 77)  printf("C+\n");
    		else if (prom >= 73)  printf("C\n");
    		else if (prom >= 70)  printf("C-\n");
    		else if (prom >= 67)  printf("D+\n");
    		else if (prom >= 60)  printf("D\n");
    		else                  printf("F\n");

				printf("Su calificion menor -> %.2f\n", calMasBaja);
				break;
			case 2:
				run = 0;
				break;
			
			default:
					printf("Opcion invalida\n");
					break;


		}

	}while(run);





	return 0;
}