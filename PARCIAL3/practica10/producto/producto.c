#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "producto.h"

void print_product(Producto *producto){
  long long codigo = producto->codigo;
	char *nombre = producto->nombre;
	float precio = producto->precio;
	printf("\n%lld %s : $%.2f",codigo,nombre,precio);
}


Producto* create_product(long long int code) {
    char nombre[MAX];

    printf("Se creará un nuevo producto!\n");

    Producto *newP = calloc(1, sizeof(Producto));
    if (!newP) {
        printf("Error al asignar memoria para el producto.\n");
        return NULL;
    }
    newP->codigo = code;
    printf("\nNombre del producto -> ");
    fgets(nombre, MAX, stdin);

    size_t len = strlen(nombre);
    if (len > 0 && nombre[len - 1] == '\n') {
        nombre[len - 1] = '\0';
    }
    newP->nombre = strdup(nombre); 
    if (!newP->nombre) {
        printf("Error al asignar memoria para el nombre.\n");
        free(newP);
        return NULL;
    }
    printf("Precio del producto -> ");
    scanf("%f", &newP->precio);
    while (getchar() != '\n'); 

    return newP;
}

void edit_product(Producto *producto){
  printf("Se editara el precio de: %s Precio actual: %.2f", producto->nombre, producto->precio);
  printf("\nNuevo precio ->");
  scanf("%f", &producto->precio);
  while(getchar() != '\n'); 
}
void free_product(Producto *producto){
  if (producto){
    free(producto->nombre);
	  free(producto);  
    }
  
}
