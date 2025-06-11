#pragma once

typedef struct{
   long long int codigo;
   char nombre[100];
   float precio;
}Producto;

typedef struct{
   Producto *ref;
   int cantidad;
}Registro;

#define MAX 100

void init_inventory(Producto *);
void init_ticket(Registro *);
void print_product(Producto *);
void print_inventory(Producto *);
void print_ticket(Registro *);
int findProductByCode(Producto *, int);
int countProducts(Producto *);
int findProductInTicket(Registro *, int );
int countTicketsProducts(Registro *);