#ifndef APIG23_H
#define APIG23_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//el .h de abajo debe tener definida GrafoSt y u32.
#include "EstructuraGrafo23.h"
//#include "vertice/vertice.h"

typedef unsigned int u32;

//Grafo es un puntero a una estructura GrafoSt, la cual debe estar definida en el .h de arriba

typedef struct GrafoSt *Grafo;





//construcci'on/destrucci'on

//debe leer desde stdin
Grafo ConstruirGrafo();

void DestruirGrafo(Grafo G);



//funciones para extraer datos del grafo. u32 debe estar definida en el .h de arriba

u32 NumeroDeVertices(Grafo G);
u32 NumeroDeLados(Grafo G);
u32 Delta(Grafo G);


//funciones de extraccion de informacion de vertices 

u32 Nombre(u32 i,Grafo G);
u32 Grado(u32 i,Grafo G);
u32 IndiceVecino(u32 j,u32 i,Grafo G);



#endif
