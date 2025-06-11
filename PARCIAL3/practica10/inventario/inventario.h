
#pragma once
#include "../producto/producto.h"

typedef struct
{
	Producto **productos;
	int cantidad;
}Inventario;

void init_inventory(Inventario *);
void print_inventory(Inventario *);
void add_edit_product(Inventario *, long long int);
int findProductByCode(Inventario *, long long int);
Producto* remove_product(Inventario *,long long int );
void free_inventory(Inventario *);