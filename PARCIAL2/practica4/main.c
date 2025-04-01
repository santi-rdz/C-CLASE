#include <stdio.h>

#define ARRAY_SIZE 6  

void initArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

//verificar si un número ya ha sido contado
int isAlreadyCounted(int num, int countedNumbers[], int size) {
    for (int i = 0; i < size; i++) {
        if (countedNumbers[i] == num) {
            return 1;  
        }
    }
    return 0; 
}

void showDuplicates(int arr[], int size) {
    int countedNumbers[size];  
    initArray(countedNumbers, size, -1000); 

    printf("\nDuplicados encontrados:\n");
    int foundDuplicates = 0;

    for (int i = 0; i < size; i++) {
        if (!isAlreadyCounted(arr[i], countedNumbers, size)) { 
            int repeatCount = 0;

            for (int j = 0; j < size; j++) {
                if (arr[i] == arr[j]) {
                    repeatCount++;
                }
            }

            if (repeatCount > 1) {
                countedNumbers[i] = arr[i]; // Registra que ya se contó este número
                printf("- %d aparece %d veces\n", arr[i], repeatCount);
                foundDuplicates = 1;
            }
        }
    }

    if (!foundDuplicates) {
        printf("No hay números duplicados en el arreglo.\n");
    }
}
void showComunes(int arr1[],int arr2[], int size){
	int comunCount = 0;
	int countedNumbers[size];  
	initArray(countedNumbers, size, -1000); 

	for (int i = 0; i < size; i++)
	{
		if (!isAlreadyCounted(arr1[i], countedNumbers, size)) { 

			for (int j = 0; j < size; j++)
			{

				if (arr1[i] == arr2[j])
				{
					comunCount++;
					countedNumbers[i] = arr1[i]; 
					break;
				}
				
			
			}
		}
	}
	
	if (comunCount) printf("\nValores en comun -> %d\n", comunCount);
	else printf("\nNo hay valores en comun!\n");

}
void captureArray(int array[]){

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("[%d] -> ", i );
        scanf("%d", &array[i]);
    }
    

}

int getOption() {
    int option;
    printf("\nMenú de Opciones:\n");
    printf("[1] Capturar Arreglo\n");
    printf("[2] Mostrar Duplicados\n");
	 printf("[3] Mostrar Comunes\n");
    printf("[4] Salir\n");
    printf("Opción -> ");
    scanf("%d", &option);
    return option;
}

int main(void) {
    int run = 1;
    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];
    int arrayCaptured = 0; 

    while (run) {
        switch (getOption()) {
            case 1: 
                printf("\n-Array 1- Ingrese %d valores\n", ARRAY_SIZE);
                captureArray(array1);
                printf("\n-Array 2- Ingrese %d valores\n", ARRAY_SIZE);
                captureArray(array2);
                
                arrayCaptured = 1; 
                break;

            case 2: 
                if (arrayCaptured) {
                    showDuplicates(array1, ARRAY_SIZE);
					showDuplicates(array2, ARRAY_SIZE);
                } 
					 else printf("\nPrimero debe capturar un arreglo.\n");
                break;

            case 3: 
					if (arrayCaptured) showComunes(array1,array2, ARRAY_SIZE);
					else printf("\nPrimero debe capturar un arreglo.\n");
                break;
            case 4: // Salir del programa
                run = 0;
                break;
            default:
                printf("\n--Opción inválida--\n");
                break;
        }
    }

    return 0;
}