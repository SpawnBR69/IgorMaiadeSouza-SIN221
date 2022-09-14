#ifndef PILHA_H
#define PILHA_H

#include "funcoespilha.cpp"

typedef struct tipoItem;
typedef struct tipoPilha;
void criaPilhaVazia(tipoPilha* pilha);
bool verificaPilhaVazia(tipoPilha pilha);
bool verificaPilhaCheia(tipoPilha pilha);
bool empilha(tipoPilha* pilha, tipoItem item);
tipoItem desempilha(tipoPilha* pilha);

#endif