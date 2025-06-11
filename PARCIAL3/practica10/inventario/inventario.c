#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

void init_inventory(Inventario *inv){
  inv->productos = NULL;
  inv->cantidad = 0;
}

void print_inventory(Inventario *invertory){
   for (int i = 0; i < invertory->cantidad; i++){
      print_product(invertory->productos[i]);
   }
}
void add_edit_product(Inventario *inventory, long long int code){
    int index = findProductByCode(inventory, code);
         
    if(index == -1){
        Producto **aux = realloc(inventory->productos, sizeof(Producto*) * (inventory->cantidad + 1));
        if (!aux) {
            printf("Error al reallocar memoria\n");
            return;
        }
        inventory->productos = aux;

        Producto *nuevo = create_product(code);
        if (!nuevo) {
            printf("Error al crear el producto\n");
            return;
        }

        printf("Producto creado -> Código: %lld, Nombre: %s, Precio: %.2f\n", nuevo->codigo, nuevo->nombre, nuevo->precio);

        inventory->productos[inventory->cantidad] = nuevo;
        inventory->cantidad++;
        return;
    }

    edit_product(inventory->productos[index]);
}
int findProductByCode(Inventario *inventory, long long int targetCode){
  for (int i = 0; i < inventory->cantidad ; i++){
    if (inventory->productos[i]->codigo == targetCode)
        return i;
  }
  return -1;
}

Producto *remove_product(Inventario *invetory, long long int code){
  Producto *lastProduct;
  Producto *productToRemove;
  int index = findProductByCode(invetory, code);
  if (index != -1){
    lastProduct = invetory->productos[invetory->cantidad - 1];
    productToRemove = invetory->productos[index];
    invetory->productos[index] = lastProduct;
    invetory->cantidad--;
    invetory->productos = realloc(invetory->productos, sizeof(Producto *) * invetory->cantidad);
    printf("Se elimino -> %s del inventario!\n", productToRemove->nombre);

    return productToRemove;
  }
  printf("No existe en el invetario!\n");
  return NULL;
}
void free_inventory(Inventario *inv) {
    if (inv->productos) {
        for (int i = 0; i < inv->cantidad; i++) {
            free_product(inv->productos[i]);
        }
        free(inv->productos); 
    }
    inv->productos = NULL;
    inv->cantidad = 0;
}