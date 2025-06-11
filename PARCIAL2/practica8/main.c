#include <stdio.h>
#include "getch.h"

#define LONGITUD_USUARIOS 3
#define LONGITUD_CAMPOS 5
#define LONGITUD_CADENAS 100


#define CURRENT_YEAR 2025

// MAC
#define RETURN 10
#define DEL 127
// WINDOWS
#define BACKSPACE 8
#define ENTER 13
#define PASS_CHECKS 4

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
int stringsEqual(char *, char *);

int userMatch(char *, char *);
int passMatch(char *, char *);
void registrar(char *,char *,int,  int );

void displayUser(char * );
void imprimirDatos(char *usuario);

void init(char *,int ,int ,int );
int getOption();

int main(void)
{
	char datos[LONGITUD_USUARIOS][LONGITUD_CAMPOS][LONGITUD_CADENAS];
   int run = 1;
   char user[LONGITUD_CADENAS], password[LONGITUD_CADENAS];
   
   init(&datos[0][0][0], LONGITUD_USUARIOS, LONGITUD_CAMPOS, LONGITUD_CADENAS);

   while (run){
      switch (getOption()){
      case 1:
         if (datos[0][0][0] == '\0'){
            printf("\nNo hay usuarios registrados!\n");
            break;
         }
         printf("Ingrese un usuario -> ");
         inputChar(user);
         printf("\nIngrese la contraseña -> ");
         inputPass(password);

         int usuarioEncontrado = 0;
         int userIndex;
         for (int i = 0; i < LONGITUD_USUARIOS; i++){            
            if (userMatch(&datos[i][0][0], user)){
               if (passMatch(&datos[i][0][0], password)){
                  printf("\nUsuario verificado!\n");
                  usuarioEncontrado = 1;
                  userIndex = i;
               }
               break;
            }
         }
         usuarioEncontrado?
         imprimirDatos(&datos[userIndex][0][0])
         :printf("\nUsuario incorrecto o contraseña incorrecta!");
         break;
      case 2:
         for (int i = 0; i < LONGITUD_USUARIOS; i++){
            printf("\n--User %d--",i+1);
            registrar(&datos[i][0][0],&datos[0][0][0],i, LONGITUD_CAMPOS);
         }
         for( int i = 0 ; i<LONGITUD_USUARIOS; i++){
            printf("\n--User %d--",i+1);
            imprimirDatos(&datos[i][0][0]);
         }
         break;
      case 3:
         run = 0;
         break;
      default:
         printf("\nOpcion invalida!\n");
         break;
      }
   }
   

}
void registrar(char *usuario, char *registro, int currentUser, int caracteres){

   do{
      printf("\nIngrese su nombre(s) -> ");
      inputString(&usuario[0]);
   } while (usuario[0] == '\0');
   printf("\nNombre registrado: %s\n", &usuario[0]);

   do{
      printf("\nIngrese apellido(s) -> ");
      inputString(&usuario[100]);
   }while(usuario[100] == '\0');
   printf("\nApeliido registrado: %s\n", &usuario[100]);

   do{
      printf("\nFecha de nacimiento(s) DD/MM/AAAA-> ");
      inputDate(&usuario[200]);
   }while(usuario[200] == '\0' || !isValidDate(&usuario[200]));
   printf("\nFecha nacimiento registrada: %s\n", &usuario[200]);

   int duplicado = 0;
   do{
      printf("\nUsuario -> ");
      inputChar(&usuario[300]);

      if(currentUser!=0 && usuario[300] != '\0'){
         for(int i = 0; i < currentUser; i++){
            duplicado = 0;
            if(userMatch(&registro[i * (LONGITUD_CAMPOS * LONGITUD_CADENAS)], &usuario[300])){
               printf("\nEste usuario ya existe en el registro!\n");
               duplicado = 1;
               break;
            }
         }
      }

   } while (usuario[300] == '\0' || duplicado);
   printf("\nUsuario registrado: %s\n", &usuario[300]);

   do{
      printf("\nContraseña -> ");
      inputPass(&usuario[400]);
   } while (usuario[400] == '\0' || !isValidPass(&usuario[400]));
   printf("\nContra registrada: %s\n", &usuario[400]);

   printf("\nUsuario exitoso!\n");
}
int stringsEqual(char *str1, char *str2){
   printf("\nComparing: %s with %s", str1, str2); 
   
   if (stringLen(str1) != stringLen(str2) )
      return 0;
   
   while(*str1){
      if (*str1 != *str2)
         return 0;
      str1++;
      str2++;
   }
   return 1;
}
int userMatch(char *bd, char *user){
   if (!(stringsEqual(&bd[300], user)))
      return 0;
   return 1;
}
int passMatch(char *bd, char *password){
   if (!(stringsEqual(&bd[400], password)))
      return 0;
   return 1;
}
void imprimirDatos(char *usuario){
	printf("\n Nombre: %s",&usuario[0]);
	printf("\n Apellido: %s",&usuario[100]);
	printf("\n Fecha: %s",&usuario[200]);	
	printf("\n Nombre de usuario: %s",&usuario[300]);
	printf("\n Contraseña: %s\n",&usuario[400]);
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

   char confirmPass[LONGITUD_CADENAS];
   do{
      printf("\nConfirma la contraseña -> ");
      inputPass(confirmPass);

      if(!stringsEqual(password, confirmPass)) printf("\nNo son la misma!\n");
      else break;
   } while(1);
   
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
      if (checks == PASS_CHECKS)
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
            printf("*");
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

void init(char *dato,int x,int y,int z){
	int i,j,k;
	
	for(i = 0;i < x;i++)
	{
		for(j = 0;j < y;j++)
		{
			for(k = 0; k < z; k++)
			{
				dato[(i*y*z)+(j*z)+k] = '\0';
				//printf("\n [%d][%d][%d] %d",i,j,k,(i*y*z)+(j*z)+k);
			}
		}
	}
	
}

int getOption() {
   int option;
   printf("\n[1] Iniciar Sesion\n");
   printf("[2] Registro\n");
   printf("[3] Salir\nOption -> ");
   scanf("%d", &option);
   while (getchar() != '\n'); // Limpiar buffer
   return option;
}