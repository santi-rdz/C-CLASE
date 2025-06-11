#pragma once 

#include "../producto/producto.h"

typedef struct
{
	Producto *ref;
	int cantidad;
}Registro;

typedef struct
{
	Registro *registros;
	int cantidad;
}Ticket;

void init_ticket(Ticket *);
void print_ticket(Ticket *);
void newRegister(Ticket*,Producto*);
int findProductInTicket(Ticket *, Producto *);
void remove_from_ticket(Ticket*, Producto* );
void free_ticket(Ticket *);