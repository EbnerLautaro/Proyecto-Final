#include "APIParte3.h"
#include "stdio.h"

bool checkear_coloreo(Grafo G, u32 *Color) {
    // O(m)
    for (u32 index = 0; index < NumeroDeVertices(G); ++index) {
        if (Color[index] == NULL_COLOR) { // si hay un vertice que no tiene color esta mal
            return false;
        }
        for (u32 vecino = 0; vecino < Grado(index, G); ++vecino) {
            if (Color[index] == Color[IndiceVecino(vecino, index, G)]) {
                return false;   
            }
        }
    }
    return true;
}

void check(u32 ji, Grafo G, u32* Color) {
        if (checkear_coloreo(G,Color)){
        printf("Coloreo Propio: X(G) ~ %u\n", ji);
    }else{
        printf("Coloreo No propio \n");
    }
}


int main() {
    Grafo G = ConstruirGrafo();
    // DestruirGrafo(g);
    printf("se termino de cargar\n");

    u32 n = NumeroDeVertices(G);
    u32 *Color = calloc(n, sizeof(u32));
    u32 *Orden = calloc(n, sizeof(u32));
    u32 *Orden2 = calloc(n, sizeof(u32));
    char c;
    u32 ji;

    // Se prueba con orden natural al principio 
    for (u32 i = 0; i < n; i++) {
        Orden[i] = i;
        Orden2[i] = i;
    }

    printf("Inicio greedy \n");
    ji = GreedyDinamico(G,Orden, Color, n+1);
    printf("Fin greedy \n");

    check(ji, G, Color);

    for (u32 i = 0; i < 50; i++) {
        for (u32 i = 0; i < 5; i++){
            // printf("FirstOrder\n");
            c = FirstOrder(G, Orden, Color);
            // printf("Reorder hecho una vez: %s\n", c == '0' ? "SUCCESS" : "FAILURE");
            // printf("Inicio greedy\n");
            ji = GreedyDinamico(G, Orden, Color, (n+1));
            // printf("Fin greedy \n");
            check(ji, G, Color);        
        }
        for (u32 i = 0; i < 5; i++){
            // printf("SecondOrder\n");
            c = SecondOrder(G, Orden, Color);
            // printf("Reorder hecho una vez: %s\n", c == '0' ? "SUCCESS" : "FAILURE");
            // printf("Inicio greedy\n");
            ji = GreedyDinamico(G, Orden, Color, (n+1));
            // printf("Fin greedy \n");
            check(ji, G, Color);
        }
    }


    DestruirGrafo(G);
    return 0;
}