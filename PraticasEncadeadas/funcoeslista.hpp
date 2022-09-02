#ifndef LISTA_H
#define LISTA_H

#include "funcoeslista.cpp"

void CriaListaVazia(TipoLista *lista);
bool verificaListaVazia(TipoLista lista);
void atualizaUltimo(TipoLista *lista);
void insereListaPrimeiro(TipoLista *lista, TipoItem *item);
void imprimeLista(TipoLista *lista);
void insereListaUltimo(TipoLista *lista, TipoItem *item);
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id);
void ImprimeItem(TipoLista *lista, int id);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorId(TipoLista *lista, int id);


#endif