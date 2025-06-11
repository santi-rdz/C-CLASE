#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct
{
	long long int codigo;
	char *nombre;
	float precio;
}Producto;

void print_product(Producto *);
Producto* create_product(long long int);
void edit_product(Producto *);
void free_product(Producto*);

