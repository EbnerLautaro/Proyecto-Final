#ifndef vertice_H
#define vertice_H

#include "./EstructuraGrafo23.h"
#include "./list.h"

struct vertice_t{
  u32 nombre; 
  list vecinos; 
} ;

typedef struct vertice_t* vertice;

vertice vertice_empty(u32 nombre);

u32 vertice_grado(vertice v);

u32 vertice_nombre(vertice v);

vertice vertice_add_vecino(vertice v, u32 vecino);

u32 vertice_get_vecino(vertice v, u32 index);

void vertice_set_vecino_name(vertice v, u32 index, u32 newName);

vertice vertice_destroy(vertice v);

#endif




