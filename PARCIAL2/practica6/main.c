#include <stdio.h>

#define LONG 1024

int getOption(){
   int option;
   printf("\n[1] Capturar frase");
   printf("\n[2] Rempazar palanra");
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
   while (palabra[i])
   {
      j=0;
      equal = 0;
      //hasta encontrar una coincidencia o la frase haya terminado
      while (palabra[i] != target[j]){
         while (palabra[i] != ' ') {
            i++;
            if (palabra[i]== '\0') return -1;
         }
         i++;
      }

      printf("\ncoincidencia:\n-----\n");
      //compara la palabra hasta que acabe o haya un caracter diferente
      while (palabra[i] != ' ' && palabra[i] != '\0' && palabra[i] != ',' && palabra[i] != '.'){
         
         printf("%c == %c ?\n", palabra[i], target[j]); 
         if (palabra[i] == target[j])  equal++;
         else {
            equal  = 0;
            break;} //caracter diferente, salimos del bucle
         i++; j++;
      }

      if (equal == targetChar) return i-(targetChar);
      
   }

   return -1;

}

int contarDepues(char *palabraFin) {
   int cant = 0;
   while (*palabraFin != '\0') { // Recorre hasta el final de la cadena
       cant++;
       palabraFin++;
   }
   return cant;
}

int main(void){

   int run = 1;
   char* palabraFin;
   char* palabraIn;
   char* reemplazoIn, reemplazoFin;
   char frase[LONG], palabraObj[LONG], reemplazo[LONG];

   while (run)
   {
      switch (getOption())
      {
      case 1:
         printf("Ingrese una frase ->");
         fgets(frase, LONG, stdin);
         frase[len(frase)-1] = '\0';
         printf("Longitud: %d\n", len(frase));
         break;
      
      case 2:
         printf("Plabra a busar -> ");
         fgets(palabraObj, LONG, stdin);
         // printf("len con salto': %d", len(palabraObj));
         int lenObjetivo = len(palabraObj);
         palabraObj[ lenObjetivo - 1 ] = '\0';
         lenObjetivo = len(palabraObj);
         int pos = isInArray(frase, palabraObj);
         if (pos >= 0 ){
            
            printf("\n'%s', existe en la frase - Index: [%d]", palabraObj, pos);
            printf(" - Valor: '%c'\n", frase[pos]);

            printf("Ingrese la palabra reemplazo -> ");
            fgets(reemplazo, LONG, stdin);
            
            
            int lenRemplazo = len(reemplazo);
            reemplazo[ lenRemplazo - 1 ] = '\0';
            lenRemplazo = len(reemplazo);
            
          
            printf("\nPalabra reemplazo: %s - len: %d\n", reemplazo, lenRemplazo);
            palabraIn = &frase[pos];
            palabraFin = palabraIn;
            
            while (*palabraFin!='\0' && *palabraFin!=' ' && *palabraFin!=',' && *palabraFin!='.')
               palabraFin++;
            
             
            int i = 0;
            int diferencia = lenRemplazo - lenObjetivo;

            printf("inicio valor: %c - fin valor:  %c", *palabraIn, *palabraFin);
            if (diferencia > 0)
            {
               char temp[LONG];
               int cantidad = contarDepues(palabraFin);
               for (i = cantidad; i >= 0; i--)
                  palabraFin[i + diferencia] = palabraFin[i];
               
               
            }
            else if(diferencia < 0){
               int cantidad = contarDepues(palabraFin);
               for (i = 0; i <= cantidad; i++)
                  palabraFin[i + diferencia] = palabraFin[i];

               palabraFin[i] = '\0';
               
            }
            
            reemplazoIn = &reemplazo[0];
            for (i = 0; i < lenRemplazo; i++, palabraIn++, reemplazoIn++)
               *palabraIn = *reemplazoIn;
               
            
            printf("\n\nFrase con reemplazo:\n----\n%s\n-----\nlongitud: %d\n", frase, len(frase));
            

         }
         else
            printf("\n'%s' no existe en la frase\n", palabraObj);

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