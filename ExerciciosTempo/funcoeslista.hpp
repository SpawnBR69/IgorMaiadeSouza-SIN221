#ifndef LISTA_H
#define LISTA_H

#include "funcoeslista.cpp"

void CriaListaVazia(TipoLista *lista);
bool verificaListaVazia(TipoLista lista);
void atualizaUltimo(TipoLista *lista);
void insereListaPrimeiro(TipoLista *lista, TipoItem *item);
string pesquisaItem(TipoLista *lista, string id);
void imprimeLista(TipoLista *lista);
void insereListaUltimo(TipoLista *lista, TipoItem *item);
void insereListaAposElemento(TipoLista *lista, TipoItem *item, string id);
void imprimeItem(TipoLista *lista, string id);
void removeListaPrimeiro(TipoLista *lista);
void removeListaUltimo(TipoLista *lista);
void removeListaUltimo(TipoLista *lista);
void removeItemPorId(TipoLista *lista, string id);


#endif