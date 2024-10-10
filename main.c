#include "Pilha/libpilha.h"
#include "Fila/libfila.h"
#include "Grafo/listaAdj.h"

int main(){
    Pilha *p = pilhaCria();
    Fila *f = filaCria();
    Grafo *g = criaGrafo(5, 0);

    pilhaPush(p, 1);
    pilhaPush(p, 2);
    pilhaPush(p, 3);

    pilhaImprime(p);

    printf("Topo: %d\n", pilhaTopo(p));

    pilhaPop(p);
    pilhaPop(p);
    
    pilhaImprime(p);

    printf("Topo: %d\n", pilhaTopo(p));


    filaQueue(f, 1);
    filaQueue(f, 2);
    filaQueue(f, 3);

    filaImprime(f);

    filaDequeue(f);
    filaDequeue(f);

    filaImprime(f);

    addAresta(g, 0, 1);
    addAresta(g, 0, 2);
    addAresta(g, 0, 3);

    imprimeGrafo(g);

    liberaGrafo(g);
    filaLibera(f);
    pilhaLibera(p);

    return 0;
}