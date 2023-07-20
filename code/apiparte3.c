#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "apig23.h"
#include "apiparte3.h"


u32 GreedyDinamico(Grafo G, u32* Orden, u32* Color, u32 p) {



    return 0;
}



// Returns min between 2 elements
u32 min(u32 a, u32 b) {
    if (a<=b){
        return a;
    } else {
        return b;
    } 
}

// Returns max between 2 elements
u32 max(u32 a, u32 b) {
    if (a<=b){
        return b;
    } else {
        return a;
    } 
}

struct F0_St {
    u32 vertice;            
    u32 E_value;
    u32 color_value;
};

int compareF0 (void* a, void* b) {

    // The comparison function must return an integer less than, equal to, or greater than
    // zero if the first argument is considered to be respectively less  than,  equal  to,  
    // or greater than the second.  If two members compare as equal, their order in the 
    // sorted array is undefined.

    struct F0_St v1 = *(struct F0_St*) a; 
    struct F0_St v2 = *(struct F0_St*) b; 

    if (v1.E_value > v2.E_value) {
        return -1;
    } 
    else if (v1.E_value == v2.E_value) {
        
        if (v1.color_value >= v2.color_value) {
            return -1;
        } else {
            return 1;
        }
    } else if (v1.E_value < v2.E_value) {
        return 1;
    }
    


}




char FirstOrder(Grafo G, u32* Orden, u32* Color) {
    /* 
    RESUMEN:

        '0' -> no error
        '1' -> error
        Color -> array [0..n-1]   
        Orden -> array [0..n-1]

        m(x) = min(Grado(i,G): Color[i]=x)
        M(x) = max(Grado(i,G): Color[i]=x)
        E(x) = {
            0x7fffffff + m(x)   si (x+2)%3 = 0
            0x1fff + M(x)       si (x+1)%3 = 0
            M(x) + m(x)         si (x+0)%3 = 0
        } 

        Se ponen primero los indices i tal que Color[i] sea igual al color x tal que E(x) es el maximo de E,
        luego los indices i tal que Color[i] es el color x tal que E(x) es el segundo mayor valor de E luego del maximo, etc.
    */ 

    // Calculo de m(x) y M(x)

    u32 max_color = 0;      
    // O(n)
    for (u32 i = 0; i < NumeroDeVertices(G); i++) {                     
        max_color = max(max_color,Color[i]);
    }
    if (Delta(G)!=0 && max_color==0) {
        return '1';
    }
    u32* m_list = calloc(max_color, sizeof(u32)); 
    u32* M_list = calloc(max_color, sizeof(u32));
    //O(r) = O(n)
    for (u32 i = 0; i < max_color; i++) {                               
        m_list[i] = MAX_U32;
        // M_list[i] = 0; esto lo hace el calloc 
    }

    // O(n)
    for (u32 i = 0; i < NumeroDeVertices(G); i++) {                     
        m_list[Color[i]] = min(m_list[Color[i]], Grado(i,G));
        M_list[Color[i]] = max(m_list[Color[i]], Grado(i,G));
    }
    
    // Calculo de E(x)
    // O(n)
    u32* E_list = calloc(max_color, sizeof(u32)); 
    for (u32 i = 0; i < NumeroDeVertices(G); i++) {                     
        
        if (((Color[i]+2)%3) == 0) {
            E_list[Color[i]] = 0x7fffffff + m_list[Color[i]];
        } 

        else if (((Color[i]+1)%3) == 0) {
            E_list[Color[i]] = 0x1fff + m_list[Color[i]];
        } 

        else if (((Color[i])%3) == 0) {
            E_list[Color[i]] = M_list[Color[i]] + m_list[Color[i]];
        }
    }
    // Tenemos calculado M(x), m(x) y E(x) para todo color x in [0, max_color]

    // Entonces se ponen primero los indices i tal que Color[i] sea igual al color x tal que E(x) es el maximo de E,
    // luego los indices i tal que Color[i] es el color x tal que E(x) es el segundo mayor valor de E luego del maximo, etc.
    // Es decir, ordenar de forma descendente con respecto a E(x), desempatar por colores.

    // Lista de estructura temporal
    struct F0_St* FO_list = calloc(NumeroDeVertices(G), sizeof(u32)); 
    for (u32 i = 0; i < NumeroDeVertices(G); i++) {
        FO_list[i].vertice = i;
        FO_list[i].E_value = E_list[Color[i]];
        FO_list[i].color_value = Color[i];
    }

    // O(n log n)
    qsort(FO_list, NumeroDeVertices(G), sizeof(u32), compareF0); 

    // O(n)
    for (u32 i = 0; i < NumeroDeVertices(G); i++) {     
        Orden[i] = FO_list[i].vertice;        
    }

    free(m_list);
    free(M_list);
    free(E_list);
    free(FO_list);

    return '0';



    /*
    Complejidad total:
        O(n)+ O(n)+ O(n)+ O(n)+ O(n)+ O(n)+ O(n log n) =  
        O(6n + n log n) = 
        O(n log n)
    */
}














char SecondOrder(Grafo G,u32* Orden,u32* Color) {
    return '0';
}

