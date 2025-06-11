#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

void init_inventory(Producto *inventory){
   for (int i = 0; i < MAX; i++)
      inventory[i].codigo = -1;

}

void init_ticket(Registro *ticket){
   for (int i = 0; i < MAX; i++){
      ticket[i].ref = NULL;
      ticket[i].cantidad = 0;
   }
}
void print_product(Producto *producto){
   long long codigo = producto->codigo;
	char *nombre = producto->nombre;
	float precio = producto->precio;
	printf("\n%lld %s : $%.2f",codigo,nombre,precio);
}

void print_inventory(Producto *invertory){
   int i = 0;
   while (i < MAX && invertory->codigo != -1){
      print_product(invertory);
      invertory++;
      i++;
   }
}
void print_ticket(Registro *ticket){
   float total = 0, sub;
   int i = 0;
   while (i < MAX && ticket->ref != NULL){
      print_product(ticket->ref);
      printf(" Cantidad: %d", ticket->cantidad);
      sub = ticket->ref->precio * ticket->cantidad;
      total+= sub;
      ticket++;
      i++;
   }
   
}

int findProductByCode(Producto *inventory, int targetCode){
   int i = 0;
   while (i < MAX && inventory->codigo != -1){
      if (inventory-> codigo == targetCode){
         return i;
      }
      inventory++;
      i++;
      
   }
   return -1;
   
}
int findProductInTicket(Registro *ticket, int targetCode) {
   for (int i = 0; i < MAX && ticket[i].ref != NULL; i++) {
       if (ticket[i].ref->codigo == targetCode) {
           return i;
       }
   }
   return -1;
}
int countProducts(Producto *inventory){
   int i = 0;
   while (i < MAX && inventory->codigo != -1){
      inventory++;
      i ++;
   }
   return i;
}

int countTicketsProducts(Registro *ticket){
   int i = 0;
   while (i < MAX && ticket[i].ref != NULL){
      ticket++;
      i ++;
   }
   return i;
}