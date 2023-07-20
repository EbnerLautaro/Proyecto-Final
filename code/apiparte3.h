#ifndef APIParte3_H
#define APIParte3_H

#include "apig23.h"

// MACROS
#define ERROR_CODE ((2^(32)) -1)    
#define NULL_COLOR __UINT32_MAX__    
#define MAX_U32 __UINT32_MAX__




u32 GreedyDinamico(Grafo G, u32* Orden, u32* Color, u32 p);

char FirstOrder(Grafo G, u32* Orden, u32* Color);

char SecondOrder(Grafo G,u32* Orden,u32* Color);

#endif