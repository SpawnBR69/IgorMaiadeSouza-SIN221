#ifndef LISTA_H
#define LISTA_H
#include "funcoesfila.cpp"

typedef struct tipoItem;
typedef struct tipoElemento *apontador;
typedef struct tipoElemento;
typedef struct tipoFila;
void criaFilaVazia(tipoFila *fila);
bool verificaFilaVazia(tipoFila fila);
void enfileira(tipoFila *fila, tipoItem item);
apontador desenfileira(tipoFila *fila);

#endif