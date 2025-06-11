#include <stdio.h>
#include <stdlib.h>

void reservar(int **, int);
void capture(int *, int);
void push(int **, int *);
void pop(int **, int *);

void sort(int *, int);
void display(int *, int);
void limpiar(int **, int *);
int getOption();

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(void){
   int *array = NULL;
   int len = 0;
   
   while (1){
      switch (getOption()){
         case 1:
         if (array){
            free(array);
            printf("\nBorrado existente\n");
         }
         printf("Cantidad de elementos -> ");
         scanf("%d", &len);

         reservar(&array, len);
         capture(array,  len);
         break;
      case 2:
         push(&array, &len);
         break;
      case 3:
         pop(&array, &len);
         break;
      case 4:
         sort(array, len);
         break;
      case 5:
         display(array, len);
         break;
      case 6:
         limpiar(&array, &len);
         printf("\nMemoria liberada!\n");
         break;
      case 7:
         limpiar(&array, &len);
         return 0;
      default:
         printf("\nOpcion invalida!\n");
         break;
      }
   }
   return 0;
}
void sort(int *ptr, int len){
   for (int i = 0; i < len-1; i++){
      int minIndex = i;
      for (int j = i + 1; j < len; j++){
         if (ptr[j] < ptr[minIndex])
            minIndex = j;
      }
      int temp = ptr[i];
      ptr[i] = ptr[minIndex];
      ptr[minIndex] = temp;   
   }
   printf("\nArreglo ordenado!\n");
}
void push(int **ptr, int *len){
   int *aux = NULL;
   (*len)++;
   while (!aux) aux = realloc(*ptr, (*len ) * sizeof(int));
   
   *ptr = aux;
   printf("\nIngresa un valor -> ");
   scanf("%d", *ptr + *len-1);
   while(getchar() != '\n');
}
void pop(int **ptr, int *len){

   if (!(*len)){
      printf("\nArreglo vacio!\n");
      return;
   }

   int deleted = (*ptr)[*len - 1];;
   (*len)--;
   int *aux = NULL;
   while (!aux) aux = realloc(*ptr, (*len)  * sizeof(int));
   
   *ptr = aux;
   printf("\n%d Borrado!\n", deleted);
}
void capture(int *ptr, int len){
   for (int i = 0; i < len; i++){
      printf("\nIgresa [%d] -> ",i);
      scanf("%d", &ptr[i]);
      while(getchar() != '\n');
   }
}
void display(int *ptr, int len){
   if (!ptr){
      printf("\nNo arreglo reservado!\n");
      return;
   }
   for (int i = 0; i < len; i++){
      printf("\n[%d]: %d ",i, ptr[i]);

   }
}
void reservar(int **ptr, int len){
   *ptr = (int*) malloc(len * sizeof(int));
}

void limpiar(int **array, int *len){
   if (*array) free(*array);
   *array = NULL;
   *len = 0;
}

int getOption(){
   int option;
   clear();
   printf("\n\n1 - Reservar memoria");
   printf("\n2 - Agregar elemento");
   printf("\n3 - Elimar ultimo");
   printf("\n4 - Ordenar");
   printf("\n5 - Desplegar elementos");
   printf("\n6 - Liberar Memoria");
   printf("\n7 - Terminar programa\nOption -> ");
   scanf("%d", &option);
   while(getchar() != '\n');
   return option;
}