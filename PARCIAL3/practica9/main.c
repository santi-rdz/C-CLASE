#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "producto.h"

int getOption();

int main(void){
   int code, size;
   float precio, total = 0;
   char nombre[100];
   Producto inventory[MAX];
   Registro ticket[100];
   init_inventory(inventory);
   init_ticket(ticket);

   while (1){
      switch (getOption()){
         case 1:
            printf("Ingrese codigo de barras -> ");
            scanf("%d", &code);
            while(getchar() != '\n');
            int index = findProductByCode(inventory, code);
         
            if(index == -1){
               index = countProducts(inventory);
               if (index == MAX){
                  printf("Inventario lleno, no es posible agregar mas productos!\n");
                  break;
               }
         
               inventory[index].codigo = code;
               printf("Se agregara un nuevo producto!\n");
               printf("\nNombre del producto -> ");
               fgets(nombre, sizeof(nombre), stdin);
      
               size_t len = strlen(nombre);
               if (len > 0 && nombre[len - 1] == '\n') {
                  nombre[len - 1] = '\0';
               }
               strcpy(inventory[index].nombre, nombre);
               
               printf("Precio del producto -> ");
               scanf("%f", &inventory[index].precio);
               while(getchar() != '\n');
               break;
            }
      
         printf("Se editara el precio del producto: %s Precio actual: %.2f", inventory[index].nombre, inventory[index].precio);
         printf("\nNuevo precio ->");
         scanf("%f", &inventory[index].precio);
         while(getchar() != '\n');
         break;
      
         case 2:
            
            printf("Presione -1 para dejar de scanear productos!\n");
            for (int i = 0; i < MAX; i++){
               printf("\nIngrese codigo de barras -> ");
               scanf("%d", &code);
               while(getchar() != '\n');
               if (code == -1)
                  break;
         
               int index = findProductInTicket(ticket, code);
               if (index != -1)
                  ticket[index].cantidad++;

               else{
                  size = countTicketsProducts(ticket);
                  if (size == MAX){
                     printf("Ticket lleno!\n");
                     break;
                  }
                  index = findProductByCode(inventory, code);
                  if (index == -1){
                     printf("Producto no existente en el inventario!\n");
                     continue;
                  }
               
                  ticket[size].ref = &inventory[index];
                  ticket[size].cantidad = 1;
               }
               total+= inventory[index].precio;
               printf("\n----------\n""%s se agrego al ticket!\n", inventory[index].nombre);
               printf("%.2f Subtotal de ticket!\n""----------\n", total);

            }
            break;   
            
         case 3:
            printf("\n----------");
            print_inventory(inventory);
            printf("\n----------\n");
            break;
         case 4: 
            printf("\n----------");
            print_ticket(ticket);
            printf("\n\n$%.2f total de ticket!\n""----------\n", total);

            break;
         case 5: 
            total = 0;
            init_ticket(ticket);
            break;
         case 6:
            return 0;
         default:
            break;
      }
   }
   


   return 0;
}
int getOption(){
   int option;
   
   printf("\n[1] - Agregar/Editar producto");
   printf("\n[2] - Escanear codigo");
   printf("\n[3] - Mostrar lista de productos");
   printf("\n[4] - Mostrar ticket de compra");
   printf("\n[5] - Borrar ticket de compra");
   printf("\n[6] - Salir\nOption ->");
   scanf("%d", &option);
   while(getchar() != '\n');
   return option;
}