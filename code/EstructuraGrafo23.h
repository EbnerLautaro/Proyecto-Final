
#ifndef ESTRUCTURA
#define ESTRUCTURA 

typedef unsigned int u32;
#include "./vertice.h"
typedef struct vertice_t* vertice;

typedef struct GrafoSt {
  u32 deltaMin;
  u32 deltaMax;
  u32 n;
  u32 m;
  vertice * vertices;
}GrafoSt;

#endif