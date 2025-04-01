#include <stdio.h>
#include <math.h>

#define RAD_TO_GRAD 57.2957795131
#define GRAD_TO_RAD 0.0174532925

void printOptions(){

	printf("[+] SUMA\n");
	printf("[-] Resta\n");
	printf("[*] Resta\n");
	printf("[/] Division\n");
	printf("[P] Potencia\n");
	printf("[R] Raiz\n");
	printf("[S] Seno\n");
  printf("[C] Coseno\n");
	printf("[T] Tangente\n");
	printf("[Z] Arcoseno\n");
	printf("[K] Arcocoseno\n");
	printf("[G] Arcotangente\n");
	printf("[0] Limpiar\n");
	printf("[X] Salir\n");
	printf("Option -> ");
	return;
	
}

int main(void){
	char option;
	int ban =1;
	double acum=0, valor;

	do{	
		printf("\nAcumulador -> %lf\n", acum);
		printOptions();
		scanf("%c", &option);
		while(getchar()!='\n');

		switch(option){
			case '+': 
				printf("\nCaptura Valor a sumar -> ");
				scanf("%lf", &valor);
				while(getchar()!='\n');
				acum+=valor;
				break;
		
			case '-':	
				printf("\nCaptura Valor a restar -> ");
				scanf("%lf", &valor);
				while(getchar()!='\n');
				acum-=valor;
				break;

			case '*':	
				printf("\nCaptura Valor a multiplicar -> ");
				scanf("%lf", &valor);
				while(getchar()!='\n');
				acum*=valor;
				break;
		
			case '/':	
				printf("\nCaptura Valor a dividir -> ");
				scanf("%lf", &valor);
				while(getchar()!='\n');
				acum/=valor;
				break;

			case 'P':	
				printf("\n%lf ^ -> ", acum);
				scanf("%lf", &valor);
				while(getchar()!='\n');
				acum = pow(acum,valor);
				break;
				
			case 'R':	
				acum = sqrt(acum);
				break;

			case 'S':	
				acum = sin(acum*GRAD_TO_RAD);
				break;
		
			case 'C':	
				acum = cos(acum*GRAD_TO_RAD);
				break;
			
			case 'T':	
				acum = cos(acum*GRAD_TO_RAD);
				break;

			case 'Z':	
				acum = asin(acum)*RAD_TO_GRAD;
				break;
			
			case 'K':	
				acum = acos(acum)*RAD_TO_GRAD;
				break;
		
			case 'G':
				acum = atan(acum)*RAD_TO_GRAD;
				break;
		
			case '0':
				acum = 0;
				break;

			case 'X':
				ban = 0;
				break;
			
			default:
				printf("Opcion invalida");
				break;
		}
	

	}while(ban);



	return 0;
}