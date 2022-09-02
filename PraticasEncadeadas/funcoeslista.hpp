#ifndef LISTA_H
#define LISTA_H

#include "funcoeslista.cpp"

void CriaListaVazia(TipoLista *lista);
bool verificaListaVazia(TipoLista lista);
void atualizaUltimo(TipoLista *lista);
void insereListaPrimeiro(TipoLista *lista, TipoItem *item);
void imprimeLista(TipoLista *lista);
void insereListaUltimo(TipoLista *lista, TipoItem *item);
void insereListaAposElemento(TipoLista *lista, TipoItem *item, int id);
void imprimeItem(TipoLista *lista, int id);
void removeListaPrimeiro(TipoLista *lista);
void removeListaUltimo(TipoLista *lista);
void removeListaUltimo(TipoLista *lista);
void removeItemPorId(TipoLista *lista, int id);


#endif