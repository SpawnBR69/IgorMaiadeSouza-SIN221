#ifndef FUNCOES_H
#define FUNCOES_H
#include "funcoeslista.cpp"


typedef struct item;
typedef struct elemento *apontador;
typedef struct elemento;
typedef struct pilha;
void criaPilhaVazia(pilha *pilha);
bool verificaPilhaVazia(pilha pilha);
void empilha(pilha *pilha, item item);
apontador desempilha(pilha *pilha);
void imprimePilha(pilha pilha);
apontador consultaPorId(pilha *pilha,int id);
apontador consultaPorNome(pilha *pilha,string nome);

#endif