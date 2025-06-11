#include <stdio.h>

#define ROWS 3
#define COLS 3

int getOption();
void captureMatriz(int *, int, int);
void initMatriz(int *, int, int);
void printMatriz(int *, int, int);
int maxInMatriz(int *,int, int);
void productoMatriz(int *, int *, int*, int, int);

int main(void){
   int matrizA[ROWS][COLS], matrizB[ROWS][COLS], matrizC[ROWS][COLS];
   int run = 1;
   initMatriz(&matrizA[0][0],ROWS,COLS);
   initMatriz(&matrizB[0][0],ROWS,COLS);
   initMatriz(&matrizC[0][0],ROWS,COLS);

   while (run)
   {
      switch (getOption())
      {
      case 1:
         printf("Ingrese Matriz A:\n");
         captureMatriz(&matrizA[0][0], ROWS,COLS);
         printf("Ingrese Matriz B:\n");
         captureMatriz(&matrizB[0][0], ROWS,COLS);
         break;
      case 2:

         printMatriz(&matrizA[0][0], ROWS,COLS);
         printf("Matriz B valores:\n");
         printMatriz(&matrizB[0][0], ROWS,COLS);
         break;
      
      case 3:
         printf("Valor maximo de MatrizA -> %d\n",maxInMatriz(&matrizA[0][0], ROWS, COLS));
         printf("Valor maximo de MatrizB -> %d\n",maxInMatriz(&matrizB[0][0], ROWS, COLS));
         break;   

      case 4:
         productoMatriz(&matrizA[0][0], &matrizB[0][0], &matrizC[0][0], ROWS, COLS);
         printMatriz(&matrizC[0][0], ROWS, COLS);
         break;
      case 5:
         initMatriz(&matrizA[0][0],ROWS,COLS);
         initMatriz(&matrizB[0][0],ROWS,COLS);
         initMatriz(&matrizC[0][0],ROWS,COLS);
         printf("\nMatrices inicalizadas en 0!\n");
         break;
      case 6:

         break;
      default:
         printf("Opcion invalida!\n");
         break;
      }
   }
}
void productoMatriz(int *matrizA, int *matrizB, int* matrizC, int rows, int cols){
   int acum = 0;
   

   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         acum = 0;

         for (int k = 0; k < rows; k++)
            acum += matrizA[i*rows+k] * matrizB[k*rows+j];
         
         matrizC[i*rows+j] = acum;

      }
      
   }
}


int maxInMatriz(int *matriz, int rows, int cols){
   
   int max = matriz[0];
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {  
         if (matriz[i*rows+j] > max)
            max = matriz[i*rows+j];
      }
   }
   return max;
}
void captureMatriz(int *matriz, int rows, int cols){

   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         printf("Ingrese i[%d][%d] -> ", i,j);
         scanf("%d", &matriz[i*rows+j]);
         
      }
      
   }
   

}
void printMatriz(int *matriz, int rows, int cols){

   printf("    ");
   for (int j = 0; j < cols; j++) printf("[%d] ", j); 
   printf("\n");
   
   for (int i = 0; i < rows; i++) {
      printf("[%d] ", i); 
      for (int j = 0; j < cols; j++)  
         printf("%3d ",matriz[i*rows+j]);

      printf("\n");
   }
}

void initMatriz(int *matriz, int rows, int cols){
   for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
         matriz[i*rows+j] = 0;
}




int getOption(){
   int option;
   printf("\n[1] Capturar Martriz A y B\n");
   printf("[2] Imprimir Matiriz A y B\n");
   printf("[3] Valor maxio de A y B\n");
   printf("[4] Multiplicar A y B\n");
   printf("[5] Limpiar matrices A, B y C\n");
   printf("[6] Salir\nOption ->");
   scanf("%d", &option);
   while(getchar()!='\n');
   return option;
}