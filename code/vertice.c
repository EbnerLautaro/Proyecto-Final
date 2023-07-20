#include <stdlib.h>
#include <assert.h>
#include "vertice.h"

vertice vertice_empty(u32 nombre) {
  vertice v = malloc(sizeof(struct vertice_t));

  v->vecinos = list_empty();
  v->nombre = nombre;

  return v;
}

u32 vertice_nombre(vertice v){
  assert(v != NULL);
  return v->nombre;
}

u32 vertice_grado(vertice v) {
  assert(v != NULL);
  return list_size(v->vecinos);
}


u32 vertice_get_vecino(vertice v, u32 index){
  return list_by_index(v->vecinos, index);
}

void vertice_set_vecino_name(vertice v, u32 index, u32 newName){
  list_change_elem(v->vecinos, index, newName);
}

vertice vertice_add_vecino(vertice v, u32 vecino) {
  assert(v != NULL);
  v->vecinos = list_push(v->vecinos, vecino); 
  return v;
}

vertice vertice_destroy(vertice v) {
  // TODO: destruir cada vecino de la lista o cambiar la lista para que reciba una funcion destructora para cada vecino
  list_destroy(v->vecinos);
  free(v);
  return NULL;
}
