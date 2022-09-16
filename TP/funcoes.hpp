#ifndef FUNCOES_H
#define FUNCOES_H

#include "funcoes.cpp"

typedef struct Func;
typedef struct ElementoFunc *ApontadorFunc;
typedef struct ElementoFunc;
typedef struct ListaFunc;
typedef int ApontadorProj;
typedef struct ListaProj;
void criaListaVaziaA(ListaProj *lista);
int verificaListaVaziaA(ListaProj *lista);
int verificaListaCheiaA(ListaProj *lista);
int tamanhoListaA(ListaProj *lista);
int insereItemA(ListaProj *lista, Proj item);
void imprimeListaA(ListaProj lista);
int pesquisaItemA(ListaProj *lista, int chave);
void retiraItemA(ApontadorProj p, ListaProj *lista, Proj *item);
void criaListaVaziaE(ListaFunc *lista);
bool verificaListaVaziaE(ListaFunc *lista);
int tamanhoListaE(ListaFunc *lista);
void insereListaPrimeiroE(ListaFunc *lista, Func *item);
void atualizaUltimo(ListaFunc *lista);
void insereListaUltimoE(ListaFunc *lista, Func *item);
void insereListaAposElementoE(ListaFunc *lista, Func *item, int id);
void imprimeListaE(ListaFunc lista);
int pesquisaItemE(ListaFunc *lista, int id);
void imprimeItemE(ListaFunc *lista, int id);
void removeListaPrimeiroE(ListaFunc *lista);
void removeListaUltimoE(ListaFunc *lista);
void removeItemPorIdE(ListaFunc *lista, int id);



#endif