#include "APIParte3.h"
#include "stdio.h"

// bool checkear_coloreo(Grafo G, u32 *Color) {
//     // O(m)
//     for (u32 index = 0; index < NumeroDeVertices(G); ++index) {
//         if (Color[index] == NULL_COLOR) { // si hay un vertice que no tiene color esta mal
//             return false;
//         }
//         for (u32 vecino = 0; vecino < Grado(index, G); ++vecino) {
//             if (Color[index] == Color[IndiceVecino(vecino, index, G)]) {
//                 return false;   
//             }
//         }
//     }
//     return true;
// }



int main() {
    Grafo g = ConstruirGrafo();
    // DestruirGrafo(g);
    printf("Se termino de cargar\n");

    printf("Vertices: %d\n", NumeroDeVertices(g));
    printf("Lados: %d\n", NumeroDeLados(g));
    printf("Delta: %d\n", Delta(g));






    DestruirGrafo(g);
    return 0;
}