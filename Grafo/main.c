#include "listaAdj.h"

int main () {
    // Cria um grafo com 10 vértices
    Grafo* grafo = criaGrafo(10, 0);

    // Adiciona arestas
    addAresta(grafo, 0, 1);
    addAresta(grafo, 0, 2);
    addAresta(grafo, 1, 2);
    imprimeGrafo(grafo);

    liberaGrafo(grafo);
    return 0;
}
