#ifndef FILA_H
#define FILA_H
#include "funcoes.cpp"

typedef struct item;
typedef struct fila;
void fazFilaVazia(fila *fila);
bool verificaFilaVazia(fila *fila);
void enfileira(fila *fila, item item);
item desinfileira(fila *fila);

#endif