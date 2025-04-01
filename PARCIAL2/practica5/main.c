#include <stdio.h>

int len(char cadena[]){
   int i = 0;
   while (cadena[i] && cadena[i] != '\n')
      i++;
   
   
   return i;
}

int isPalindrome(char palabra[]){

      int longitud = len(palabra);
      palabra[longitud] = '\0';

      char *inicio = &palabra[0];
      char *fin = &palabra[longitud-1];
      
      printf("\n------\n");

      while (inicio < fin)
      {
         if (*inicio == ' ') inicio++;
         if (*fin == ' ') fin--;
      
         *inicio == *fin 
         ?printf("%c == %c \n", *inicio, *fin)
         :printf("%c != %c \n", *inicio, *fin);

         if (inicio >= fin) break;

         if (*inicio != *fin) return 0;

         inicio++;
         fin--;
      }
      printf("------\n""inicio en -> %c %p\n", *inicio, inicio);
      printf("fin en -> %c %p\n\n", *fin, fin);
      return 1;

}

int main(void){
   char palabra[256];
   int longitud, run = 1, opt;
   int espInicio= 0, espFin = 0;

   while (run)
   {
     printf("\n[0] Verificar palindromo\n");
     printf("[1] Salir\nOpcion -> ");
     scanf("%d", &opt);
     while (getchar() != '\n');
     
     if(opt == 0){
         printf("Inhgrese una palabra -> ");
         fgets(palabra, 256, stdin);
         
         if (isPalindrome(palabra))
            printf("La palabra es palindroma!\n");
         else
            printf("------\n""La palabra no es palindroma!\n"); 
      }
      else if(opt == 1) run = 0;
      else printf("Opcion invalida!");
     
   }
   

   
  

   
   
   return 0;
}