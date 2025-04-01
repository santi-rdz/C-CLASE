#include <stdio.h>

#define M 3
#define N 3

int lenCadena(char cadena[]){
   int i = 0;
   while (cadena[i] && cadena[i] != '\n')
      i++;
   return i;
}
void counters(char cadena[], int *vowels,int  *consonant, int *digit,int *other){
   int i = 0;
   

   while (cadena[i])
   {
      if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        cadena[i] += 32;
      
      if (cadena[i]>= 'a' && cadena[i] <= 'z')
      {
         if (cadena[i] == 'a' || cadena[i] == 'e'|| cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u')
             (*vowels)++;
         else (*consonant)++;      
      }
      else if (cadena[i] >= '0' && cadena[i] <= '9')
         (*digit)++;
      
      else (*other)++;
      
      i++;
      
   }
   
}

void captureMatriz(int matriz[M][N]){

   for (int i = 0; i < M; i++)
   {
      for (int j = 0; j < N; j++)

      {
         printf("Ingrese [%d][%d] -> ", i,j);
         scanf("%d", &matriz[i][j]);
      }
      
   }

}
void printMatriz(int matriz[M][N]) {
   printf("    ");

   for (int j = 0; j < N; j++) printf("[%d] ", j); 

   printf("\n");

   for (int i = 0; i < M; i++) {
       printf("[%d] ", i); 

       for (int j = 0; j < N; j++)  printf("%3d ", matriz[i][j]);
 
       printf("\n");
   }
}
void multiplyMatriz(int matrizC[M][N], int matrizA[M][N], int matrizB[M][N]){
   int acum = 0;
   

   for (int i = 0; i < M; i++)
   {
      for (int j = 0; j < N; j++)
      {
         acum = 0;

         for (int k = 0; k < M; k++)
            acum += matrizA[i][k] * matrizB[k][j];
         
         matrizC[i][j] = acum;

      }
      
   }
}

int main(void){
   char cadena[256];
   int vowels = 0, consonant = 0, digit = 0, other = 0, run =1, option;
   int matrizA[M][N],matrizB[M][N], matrizC[M][N];

   while (run)
   {

      printf("\n[0] Ingresar Matricez  y multiplicar\n");
      printf("[1] Ingresar Cadena\n");
      printf("[2] Salir\nOpcion -> ");
      scanf("%d", &option);
      while(getchar()!='\n');


      switch (option)
      {
         case 0:
            captureMatriz(matrizA);
            captureMatriz(matrizB);
            printMatriz(matrizA);
            printf("\tX\n");
            printMatriz(matrizB);

            multiplyMatriz(matrizC,matrizA,matrizB);
            printf("\t===\n");
            printMatriz(matrizC);
            break;
         case 1:
            vowels = 0, consonant = 0, digit = 0, other = 0;
            printf("Ingrese una cadena de texto (max 256 c) -> ");
            fgets(cadena, 256, stdin);
         
            counters(cadena, &vowels, &consonant, &digit, &other);
            
            printf("Cantidad de caracteres: %d \n", lenCadena(cadena));
            printf("Cantidad de vocales: %d\n", vowels);
            printf("Cantidad de consonantes : %d\n", consonant);
            printf("Cantidad de digitos : %d\n", digit);
            printf("Otros: %d\n", other-1);
            break;
         case 2:
            run = 0;
            break;
         default:
            printf("Opcion invalida!\n");
            break;
      }
   }
   
   

   return 0;
}