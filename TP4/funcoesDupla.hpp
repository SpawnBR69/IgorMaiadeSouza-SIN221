#ifndef DUPLA_H
#define DUPLA_H
#include "funcoesDupla.cpp"

typedef struct TipoItemD;
typedef struct ElementoD* ApontadorD;
typedef struct ElementoD;
typedef struct TipoListaD;
void criaListaVaziaD(TipoListaD* lista);
bool listaVaziaD(TipoListaD* lista);
void insereItemUltimoD(TipoListaD* lista, TipoItemD item);
void insereItemPrimeiroD(TipoListaD* lista, TipoItemD item);
void insereItemAposElementoD(TipoListaD* lista, TipoItemD item, int id);
ApontadorD localizaItemPorIdD(TipoListaD* lista ,int id);
TipoItemD retiraItemPorIdD(TipoListaD* lista, int id);
void imprimeItemD(TipoItemD item);
void imprimeListaD(TipoListaD* lista);
void imprimeListaReversaD(TipoListaD* lista);

#endif