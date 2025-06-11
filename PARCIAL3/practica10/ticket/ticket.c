#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"

void init_ticket(Ticket *ticket){
  ticket->registros = NULL;
  ticket->cantidad = 0;
}
void print_ticket(Ticket *ticket){
  float total = 0, sub;

  for (int i = 0; i < ticket->cantidad; i++) {
    Registro *reg = &ticket->registros[i];
    print_product(reg->ref);
    printf(" Cantidad: %d\n", reg->cantidad);
    sub = reg->ref->precio * reg->cantidad;
    total += sub;
}
  printf("Total: %.2f\n", total);
}
void newRegister(Ticket* ticket,Producto* product){
  int index = findProductInTicket(ticket, product);

  if (index != -1){
    ticket->registros[index].cantidad++;
    return;
  }

  Registro *aux;
  aux = NULL;
  ticket->cantidad++;
  while (!aux) aux = realloc(ticket->registros, sizeof(Registro) * ticket->cantidad);
  ticket->registros = aux;
  ticket->registros[ticket->cantidad - 1 ].ref = product;
  ticket->registros[ticket->cantidad - 1 ].cantidad = 1;
  
}
int findProductInTicket(Ticket *ticket, Producto *target) {
    for (int i = 0; i < ticket->cantidad; i++) {
        if (ticket->registros[i].ref == target)
            return i;
    }
    return -1;
}


void remove_from_ticket(Ticket* ticket, Producto* tagetProduct){
  if(tagetProduct == NULL) return;
  int index = findProductInTicket(ticket, tagetProduct);

  if (index != -1){
    Registro lastRegister;

    lastRegister = ticket->registros[ticket->cantidad - 1];
    ticket->registros[index] = lastRegister;
    ticket->cantidad--;
    ticket->registros = realloc(ticket->registros, sizeof(Registro) * ticket->cantidad);

  }
  
}

void free_ticket(Ticket *ticket) {
    for (int i = 0; i < ticket->cantidad; i++) {
        free_product(ticket->registros[i].ref); 
    }
    free(ticket->registros); 
    ticket->registros = NULL;
    ticket->cantidad = 0;
}