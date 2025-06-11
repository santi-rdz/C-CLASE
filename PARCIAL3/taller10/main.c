#include <stdio.h>
#include <stdlib.h>

int **reservarMatriz(int **, int , int);
void capturarMatriz(int **, int, int);
void displayMatriz(int **, int, int);
void liberarMatriz(int **, int);
void multiplyMatriz(int **matrizC, int **, int **, int , int, int);

int getOption();

int main(void){
   int **matrizA = NULL;
   int **matrizB = NULL;
   
   int RENA, COLA;
   int RENB, COLB;

   int **matrizC = NULL;

   while (1){
      switch (getOption()){
         case 1:
            if (matrizA)
               liberarMatriz(matrizA, COLA);
            
            printf("Cantidad de renglones -> ");
            scanf("%d", &RENA);
            printf("Cantidad de columnas -> ");
            scanf("%d", &COLA);

            matrizA = reservarMatriz(matrizA, RENA, COLA);
            capturarMatriz(matrizA, RENA, COLA);

            break;
         case 2:
            if (matrizB)
               liberarMatriz(matrizB, COLB);
            
            printf("Cantidad de renglones -> ");
            scanf("%d", &RENB);
            printf("Cantidad de columnas -> ");
            scanf("%d", &COLB);

            matrizB = reservarMatriz(matrizB, RENB, COLB);
            capturarMatriz(matrizB, RENB, COLB);
            break;
         case 3:
            if(matrizA) displayMatriz(matrizA, RENA, COLA);
            if(matrizB) displayMatriz(matrizB, RENB, COLB);
            // if(matrizC) displayMatriz(matrizC, RENB, COLB);
            break;
         case 4:
            if(matrizC) liberarMatriz(matrizC, RENA);
            if (COLA != RENB){
               printf("No es posible hacer producto de matrices!\n");
               break;
            }
            matrizC = reservarMatriz(matrizC, RENA, COLB);
            multiplyMatriz(matrizC, matrizA, matrizB, RENA, COLA, COLB);
            break;
         case 5:
            if(matrizA) liberarMatriz(matrizA, RENA);
            if(matrizB) liberarMatriz(matrizB, RENB);
            if(matrizC) liberarMatriz(matrizC, RENA);
            return 0;
         default:
            printf("Opcion invalida!\n");
            break;
      }
   }
   return 0;
}

void multiplyMatriz(int **matrizC, int **matrizA, int **matrizB, int RENA, int COLA, int COLB) {
   for (int i = 0; i < RENA; i++) {
       for (int j = 0; j < COLB; j++) {
           matrizC[i][j] = 0;
           for (int k = 0; k < COLA; k++) {
               matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
           }
       }
   }
   displayMatriz(matrizC, RENA, COLB);
}

int **reservarMatriz(int **matriz, int ren, int col){
   matriz = (int **) calloc(ren, sizeof(int *));
   for (int i = 0; i < ren; i++)
      matriz[i] = (int *)calloc(col, sizeof(int));
   
   return matriz;
}

void capturarMatriz(int **matriz, int ren, int col){

   for (int i = 0; i < ren; i++){
      for (int j = 0; j < col; j++){  
         printf("[%d][%d] -> ", i, j);
         scanf("%d", &matriz[i][j]);
      } 
   }
   return;
}

void displayMatriz(int **matriz, int rows, int cols) {
   printf("    ");
   for (int j = 0; j < cols; j++) printf("[%d] ", j);
   printf("\n");

   for (int i = 0; i < rows; i++) {
       printf("[%d] ", i);
       for (int j = 0; j < cols; j++)
           printf("%3d ", matriz[i][j]);
       printf("\n");
   }
}

void liberarMatriz(int **matriz, int rows) {
   for (int i = 0; i < rows; i++) {
       free(matriz[i]);
   }
   free(matriz);
   matriz = NULL;
}
int getOption(){
   int option;
   printf("\n1 - Capturar Matriz A");
   printf("\n2 - Capturar Matriz B");
   printf("\n3 - Desplegar matrices");
   printf("\n4 - Multiplicar matrices");
   printf("\n5 - Terminar programa\nOption -> ");
   scanf("%d", &option);
   while(getchar() != '\n');
   return option;
}