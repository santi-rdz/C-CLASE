#include <stdio.h>

#define LONGITUD 100

int getOption();
int stringLen(char *);
void inputString(char *,int );
int countChar(char *);
int replaceChar(char , char , char *);
void stringToUpper(char *);
void stringToLower(char *);

int main(void){

   char cadena[LONGITUD], target, replace;
   int run = 1;

   while (run){
      switch (getOption()){
      case 1:
         inputString(cadena, LONGITUD);
         break;
      case 2:
         printf("\nCantidad de caractetes: %d\n", countChar(cadena));
         break;
      case 3:
         printf("Ingrese el caracter objetivo -> ");
         scanf(" %c", &target);
         printf("Ingrese el caracter remplazo -> ");
         scanf(" %c", &replace);
         
         if (replaceChar(target, replace, cadena)){
            printf("Se remplazo correctamente!\n");
            puts(cadena);
         }
         else printf("\nNo se encontro el caracter objetivo!\n");
         break;
      case 4:
         stringToUpper(cadena);
         printf("\nCadena en mayusculas: %s\n",cadena);
         break;
      case 5:
         stringToLower(cadena);
         printf("\nCadena en minusculas: %s\n",cadena);
         break;
      case 6:
         run = 0;
         break;
      default:
         printf("Opcion invalida!!\n");
         break;
      }
   }
   return 0;
}

int stringLen(char *cadena){
   int cant = 0;
   while (*cadena){
      cant++;
      cadena++;
   }
   return cant;
}

void inputString(char *cadena, int size){
   printf("Ingrese una cadena de texto: ");
   fgets(cadena, size, stdin);
   cadena[ stringLen(cadena) - 1] = '\0';
}

int countChar(char *cadena){
   int cant = 0;
   while (*cadena){
      if (*cadena != ' ') cant++;
      cadena++;
   }  
   return cant;
}

int replaceChar(char target, char replace, char *cadena){
   while (*cadena){
      if (*cadena == target){  
         *cadena = replace;
         return 1;
      }
      cadena++;
   }
   return 0;
}

void stringToUpper(char *cadena){
   while (*cadena){
      if (*cadena >= 97 && *cadena <= 122)
         *cadena -= 32;
      cadena++;
   }
}

void stringToLower(char *cadena){
   while (*cadena){
      if (*cadena >= 65 && *cadena <= 90)
         *cadena += 32;
      cadena++;  
   }
}

int getOption(){
   int option;
   printf("\n[1] Capturar cadena\n");
   printf("[2] Contar caracteres\n");
   printf("[3] Reemplazar caracter\n");
   printf("[4] Convertitr a Mayusculas\n");
   printf("[5] Convertir Minusculas\n");
   printf("[6] Salir\nOption ->");
   scanf("%d", &option);
   while(getchar()!='\n');
   return option;
}

