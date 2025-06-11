#include <stdio.h>
#include <stdlib.h>
#include "producto/producto.h"
#include "inventario/inventario.h"
#include "ticket/ticket.h"

int getOption();

int main(void){
  long long int code; 
  int index;
  Inventario inventory;
  Ticket ticket;
  init_inventory(&inventory);
  init_ticket(&ticket);

  while (1){
    switch (getOption())
    {
    case 1:
        printf("Ingrese codigo de barras -> ");
        scanf("%lld", &code);
        while(getchar() != '\n');
        add_edit_product(&inventory, code); 
        break;
    case 2:
        printf("Ingrese codigo de barras -> ");
        scanf("%lld", &code);
        Producto *producto =  remove_product(&inventory, code);
        remove_from_ticket(&ticket, producto);
        break;
    case 3:
        while (1){
          printf("Presione -1 para dejar de scanera productos!\n");
          printf("Codigo producto a registrar -> ");
          scanf("%lld", &code);
          while(getchar() != '\n');
          if(code == -1 )break;
          
          index = findProductByCode(&inventory, code);
          if (index == -1){
            printf("Este producto no existe!\n");
            continue;
          }
          newRegister(&ticket, inventory.productos[index]);
          
        }
        break;
    case 4:
        printf("\n----------");
        print_inventory(&inventory);
        printf("\n----------\n");
        break;
    case 5:
        printf("\n----------");
        print_ticket(&ticket);
        printf("----------\n");
        break;
    case 6:
        init_ticket(&ticket);
        break;
    case 7:
      printf("Saliendo del programa...\n");
      free_ticket(&ticket);
      free_inventory(&inventory);
      return 0;
    break;
    }
  }
  

  return 0;
}

int getOption(){
   int option;
   
   printf("\n[1] - Agregar/Editar producto");
   printf("\n[2] - Eliminar producto");
   printf("\n[3] - Escanera codigo");
   printf("\n[4] - Mostrar lista de productos");
   printf("\n[5] - Mostrar ticket de compra");
   printf("\n[6] - Borrar ticket de compra");
    printf("\n[7] - Salir\nOption ->");
   scanf("%d", &option);
   while(getchar() != '\n');
   return option;
}