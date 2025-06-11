#include <stdio.h>

#define LONG 1024

// Prototipos de funciones
int getOption();
int len(char palabra[]);
int contarCaracteres(char palabra[]);
int isInArray(char palabra[], char target[]);
int contarDepues(char *palabraFin);
void capturarFrase(char frase[]);
void reemplazarPalabra(char frase[]);

int main(void){
   int run = 1;
   char frase[LONG];

   while (run){
      switch (getOption()){
         case 1:
            capturarFrase(frase);
            break;
         case 2:
            reemplazarPalabra(frase);
            break;
         case 3:
            run = 0;
            break;
         default:
            printf("Opcion invalida!\n");
            break;
      }
   }

   return 0;
}

// Funciones

int getOption(){
   int option;
   printf("\n[1] Capturar frase");
   printf("\n[2] Reemplazar palabra");
   printf("\n[3] Salir\nOption -> ");
   scanf("%d", &option);
   while(getchar() != '\n');
   return option;
}

int len(char palabra[]){
   int i = 0;
   while (palabra[i]) i++;
   return i;
}

int contarCaracteres(char palabra[]){
   int cant = 0;
   int i = 0;
   while(palabra[i]){
      if (palabra[i] != ' ')  cant++;
      i++;
   }
   return cant;
}

int isInArray(char palabra[], char target[]){
   int equal = 0, j = 0, i = 0;
   int targetChar = contarCaracteres(target);
   
   printf("\nLa palabra a buscar tiene: %d caracteres\n", targetChar); 
   while (palabra[i]){
      j=0;
      equal = 0;

      while (palabra[i] != target[j]){
         while (palabra[i] != ' ') {
            i++;
            if (palabra[i]== '\0') return -1;
         }
         i++;
      }

      printf("\ncoincidencia:\n-----\n");
      while (palabra[i] != ' ' && palabra[i] != '\0' && palabra[i] != ',' && palabra[i] != '.'){
         printf("%c == %c ?\n", palabra[i], target[j]); 
         if (palabra[i] == target[j])  
            equal++;
         else {
            equal  = 0;
            break;
         }
         i++; j++;
      }

      if (equal == targetChar) 
         return i - targetChar;
   }

   return -1;
}

int contarDepues(char *palabraFin) {
   int cant = 0;
   while (*palabraFin != '\0') {
       cant++;
       palabraFin++;
   }
   return cant;
}

void capturarFrase(char frase[]){
   printf("Ingrese una frase -> ");
   fgets(frase, LONG, stdin);
   frase[len(frase)-1] = '\0'; // eliminar salto de línea
   printf("Longitud: %d\n", len(frase));
}

void reemplazarPalabra(char frase[]){
   char palabraObj[LONG], reemplazo[LONG];
   char *palabraIn, *palabraFin, *reemplazoIn;

   printf("Palabra a buscar -> ");
   fgets(palabraObj, LONG, stdin);
   palabraObj[len(palabraObj)-1] = '\0'; // eliminar salto de línea
   int lenObjetivo = len(palabraObj);

   int pos = isInArray(frase, palabraObj);
   if (pos >= 0){
      printf("\n'%s', existe en la frase - Index: [%d]", palabraObj, pos);
      printf(" - Valor: '%c'\n", frase[pos]);

      printf("Ingrese la palabra reemplazo -> ");
      fgets(reemplazo, LONG, stdin);
      reemplazo[len(reemplazo)-1] = '\0'; // eliminar salto de línea
      int lenReemplazo = len(reemplazo);

      palabraIn = &frase[pos];
      palabraFin = palabraIn;

      while (*palabraFin!='\0' && *palabraFin!=' ' && *palabraFin!=',' && *palabraFin!='.')
         palabraFin++;

      int diferencia = lenReemplazo - lenObjetivo;
      int i = 0;

      if (diferencia > 0){
         int cantidad = contarDepues(palabraFin);
         for (i = cantidad; i >= 0; i--)
            palabraFin[i + diferencia] = palabraFin[i]; 
      } else if (diferencia < 0){
         int cantidad = contarDepues(palabraFin);
         for (i = 0; i <= cantidad; i++)
            palabraFin[i + diferencia] = palabraFin[i]; 
         palabraFin[i] = '\0';
      }

      reemplazoIn = reemplazo;
      for (i = 0; i < lenReemplazo; i++, palabraIn++, reemplazoIn++)
         *palabraIn = *reemplazoIn;

      printf("\n\nFrase con reemplazo:\n----\n%s\n-----\nlongitud: %d\n", frase, len(frase));
   }
   else {
      printf("\n'%s' no existe en la frase\n", palabraObj);
   }
}