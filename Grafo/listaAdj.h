#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_g{
    int vertice;
    struct nodo_g *prox;
}Nodo_G;

typedef struct grafo{
    int numVertices;
    Nodo_G **listaAdj;
    int direcionado;
}Grafo;


// Funções de criação e liberação de grafo e nodos
Nodo_G* criaNodo(int v);
Grafo* criaGrafo(int vertices, int direcionado);
void liberaGrafo(Grafo* grafo);

// Adiciona aresta entre origem e destino
void addAresta(Grafo* grafo, int origem, int destino);

// Imprime o grafo
void imprimeGrafo(Grafo* grafo);


#endif