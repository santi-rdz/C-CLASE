#include <stdio.h>
#include "getch.h"

#define CURRENT_YEAR 2025

// MAC
#define RETURN 10
#define DEL 127
// WINDOWS
#define BACKSPACE 8
#define ENTER 13
#define PASS_CHEKS 4

int getOption();

void inputString(char *);
void inputChar(char *);
void inputPass(char *);
void inputDate(char *);

int isValidPass(char *);
int isValidDate(char *);
int esBisiesto(int );

int checkDate(char *);
int checkPass(char *);
int stringLen(char *);




int main(void) {
    char registro[5][50]; 
    int run = 1;

    while (run) {
        switch (getOption()) {
            case 1:
               do{
                  printf("\nIngrese su nombre(s) -> ");
                  inputString(registro[0]);
               } while (registro[0][0] == '\0');
               printf("\nNombre registrado: %s\n", registro[0]);

               do{
                printf("\nIngrese apellido(s) -> ");
                inputString(registro[1]);
               } while (registro[1][0] == '\0');
               printf("\nApeliido registrado: %s\n", registro[1]);
            
               do{
                printf("\nFecha de nacimiento(s) DD/MM/AAAA-> ");
                inputDate(registro[2]);
               } while (registro[2][0] == '\0' || !isValidDate(registro[2]));
               printf("\nFecha nacimiento registrada: %s\n", registro[2]);

               do{
                printf("\nUsuario -> ");
                inputChar(registro[3]);
               } while (registro[3][0] == '\0');
               printf("\nUsuario registrado: %s\n", registro[3]);

               do{
                printf("\nContraseña -> ");
                inputPass(registro[4]);
               } while (registro[4][0] == '\0' || !isValidPass(registro[4]));
               printf("\nContra registrada: %s\n", registro[4]);

               printf("\nRegistro exitoso!\n");
         
                break;

            case 2:
                run = 0;
                break;

            default:
                printf("Opción no válida.\n");
                break;
        }
    }
    return 0;
}

int isValidPass(char *password){

   if (stringLen(password) < 8){
      printf("\nLongitud minima <8> caracteres\n");
      return 0;
   }
   if(!checkPass(password)){
      printf("No cumple con los requerimientos\n");
      return 0;
   }
   int len = stringLen(password);
   char confirmPass[len];
   
   int i = 0;
   do
   {
      printf("\nConfirma la contraseña -> ");
      inputPass(confirmPass);
   
      while (*password)
      {
         if (*password != confirmPass[i])
         {
            printf("\nNo son la misma!\n");
            break;
         }
         i++;
         password++;
      }
     
      
   } while (*password != confirmPass[i]);
   
   printf("\nContraseña valida!\n");
   return 1;



}
int checkPass(char *password){
   int checks = 0, hasUpper = 0, hasLower = 0, hasNumber = 0, hasSpecial = 0;
   
   while (*password)
   {
      
      if ((hasLower == 0) && (*password >= 'a' && *password <= 'z' ))
      {
         hasLower = 1;
         checks++;
      }
      else if( hasUpper == 0 &&(*password >= 'A' && *password <= 'Z')){
         hasUpper = 1;
         checks++;
      }
      else if(hasNumber == 0 && (*password >= '0' && *password <= '9')){
         
         hasNumber = 1;
         checks++;
      }
      else if(hasSpecial == 0 && ((*password >= '!' && *password <= '/')||( *password >= ':' && *password <= '@') || (*password >= '[' && *password <= '.')|| (*password >= '{' && *password <= '~'))){
         hasSpecial = 1;
         checks++;
      }
      password++;
      if (checks == PASS_CHEKS)
         return 1;     
   }
   printf("\nchecks : %d\n", checks);
   return 0;
   
}
int isValidDate(char *date){
   if ((stringLen(date) == 10) && checkDate(date))
      return 1;
   return 0;
}

int checkDate(char *date) {
   int day = ((date[0] - '0') * 10 + (date[1] - '0'));
   int month = ((date[3] - '0') * 10 + (date[4] - '0'));
   int year = ((date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0'));

   if ((day < 1) || (month < 1 || month > 12) || (year > CURRENT_YEAR)){   
      printf("\nFecha fuera del limite valido!\n");
      return 0;
   }
   int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

   if (month == 2 && esBisiesto(year)) 
      diasPorMes[1] = 29;
   
   if (day > diasPorMes[month-1]) {
      printf("\nDía inválido para el mes ingresado!\n");
      return 0;
   }
  return 1;
}
int esBisiesto(int year){
   int esBisiesto = 0;
   if (year % 4 == 0) {
       if (year % 100 == 0) {
           if (year % 400 == 0) 
               esBisiesto = 1;
           else 
               esBisiesto = 0;
       } else 
           esBisiesto = 1;
   } else 
       esBisiesto = 0;

   return esBisiesto;
}

void inputString(char *string) {
   char tecla;
   int i = 0;
   
   // RETURN MAC: 10 | ENTER WINDOWS: 13
   while ((tecla = getch()) != ENTER && tecla != RETURN) {  
      // Validar letras y espacios
      if ((tecla >= 'a' && tecla <= 'z') || (tecla >= 'A' && tecla <= 'Z') || tecla == ' ') {
         if (i < 49) { 
            printf("%c", tecla);
            string[i++] = tecla;
         }
      }
      
      // Backspace (Windows) o Delete (Mac)
      if (i > 0 && (tecla == BACKSPACE || tecla == DEL)) {
         printf("\b \b");
         string[i--] = '\0'; 

      }
   }
   string[i] = '\0'; 
}
void inputChar(char *string) {
   char tecla;
   int i = 0;
   
   // RETURN MAC: 10 | ENTER WINDOWS: 13
   while ((tecla = getch()) != ENTER && tecla != RETURN) {  
      // Validar letras y espacios
      if ((tecla >= 'a' && tecla <= 'z') || (tecla >= 'A' && tecla <= 'Z') || (tecla >= '0' && tecla <= '9') || tecla == ' ') {
         if (i < 49) { 
            printf("%c", tecla);
            string[i++] = tecla;
         }
      }
      
      // Backspace (Windows) o Delete (Mac)
      if (i > 0 && (tecla == BACKSPACE || tecla == DEL)) {
         printf("\b \b");
         string[--i] = '\0'; 
      }
   }
   string[i] = '\0'; 
}
void inputPass(char *string) {
   char tecla; 
   int i = 0;
   
   // RETURN MAC: 10 | ENTER WINDOWS: 13
   while ((tecla = getch()) != ENTER && tecla != RETURN) {  
     
      
      if (tecla >= '!' && tecla <= '~') {
         if (i < 49) { 
            printf("%c", tecla);
            string[i++] = tecla;
         }
      }
      
      // Backspace (Windows) o Delete (Mac)
      if (i > 0 && (tecla == BACKSPACE || tecla == DEL)) {
         printf("\b \b");
         string[--i] = '\0'; 
      }
   }
   string[i] = '\0'; 
}
void inputDate(char *string) {
   char tecla;
   int i = 0;
   
   // RETURN MAC: 10 | ENTER WINDOWS: 13
   while ((tecla = getch()) != ENTER && tecla != RETURN) {  
       if ((tecla >= '0' && tecla <= '9')){
          if (i <= 9) { 
             printf("%c", tecla);
             string[i++] = tecla;
            }
         }
         
      if (i == 2 || i == 5){
         printf("/");
         string[i++] = '/';
         continue;
      }
      // Backspace (Windows) o Delete (Mac)
      if (i > 0 && (tecla == BACKSPACE || tecla == DEL)) {
         printf("\b \b");
         string[--i] = '\0'; 
      }
   }
   string[i] = '\0'; 
}
int stringLen(char *cadena){
   int cant = 0;
   while (*cadena){
      cant++;
      cadena++;
   }
   return cant;
}


int getOption() {
    int option;
    printf("\n[1] Registrar\n");
    printf("[2] Salir\nOption -> ");
    scanf("%d", &option);
    while (getchar() != '\n'); // Limpiar buffer
    return option;
}

