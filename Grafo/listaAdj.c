#include "listaAdj.h"

Nodo_G* criaNodo(int v){
    Nodo_G* novoNodo = (Nodo_G*)malloc(sizeof(Nodo_G));
    novoNodo->vertice = v;
    novoNodo->prox = NULL;
    return novoNodo;
}

Grafo* criaGrafo(int vertices, int direcionado){
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    grafo->direcionado = direcionado;

    grafo->listaAdj = malloc(vertices * sizeof(Nodo_G*));

    for (int i = 0; i < vertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void addAresta(Grafo* grafo, int origem, int destino){
    Nodo_G* novoNodo = criaNodo(destino);
    novoNodo->prox = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNodo;

    // Se o grafo não for direcionado, adicionar aresta no sentido contrário
    if (!grafo->direcionado) {
        novoNodo = criaNodo(origem);
        novoNodo->prox = grafo->listaAdj[destino];
        grafo->listaAdj[destino] = novoNodo;
    }
}

void imprimeGrafo(Grafo* grafo){
    for (int v = 0; v < grafo->numVertices; v++) {
        Nodo_G* temp = grafo->listaAdj[v];
        printf("\n Lista de adjacência do vértice %d\n raiz ", v);
        while (temp) {
            printf("-> %d", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void liberaGrafo(Grafo* grafo){
    for (int i = 0; i < grafo->numVertices; i++) {
        Nodo_G* temp = grafo->listaAdj[i];
        while (temp) {
            Nodo_G* apagar = temp;
            temp = temp->prox;
            free(apagar);
        }
    }
    free(grafo->listaAdj);
    free(grafo);
}