#ifndef LISTA_H
#define LISTA_H

#include "funcoes.cpp"

void CriaListaVazia(TipoLista *lista);
bool verificaListaVazia(TipoLista lista);
void atualizaUltimo(TipoLista *lista);
void insereListaPrimeiro(TipoLista* lista, TipoItem item);
void insereListaUltimo(TipoLista* lista, TipoItem item);
void removeUltimo(TipoLista* lista);
void removeItemPorId(TipoLista* lista,int id);
void removePrimeiro(TipoLista* lista);
void imprimeLista(TipoLista lista);


#endif