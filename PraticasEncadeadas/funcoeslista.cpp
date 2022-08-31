#include <iostream>
 
typedef struct TipoItem{
 int id;
}TipoItem;

typedef struct Elemento* Apontador;
typedef struct Elemento{
    TipoItem item;
    struct Elemento* prox;
}Elemento;

typedef struct TipoLista{
    Apontador primeiro;
    Apontador ultimo;
}TipoLista;

void CriaListaVazia(TipoLista* lista){
    lista -> primeiro = new Elemento;
    lista -> ultimo = lista -> primeiro;
    lista ->ultimo->prox=NULL;
}

void insereListaPrimeiro(TipoLista *lista, TipoItem *item){
    Apontador aux;
    aux = lista ->primeiro->prox;
    lista->primeiro->prox = new Elemento;
    lista -> primeiro -> prox->prox = aux;
    lista -> primeiro ->prox-> item = *item;
}

bool verificaListaVazia(TipoLista lista){
    return lista.primeiro->prox == lista.ultimo->prox;
}

void imprimeLista(TipoLista lista){
    std::cout << lista.primeiro->prox->item.id<< std::endl;
    std::cout << lista.ultimo->prox->item.id << std::endl;
}

void atualizaUltimo(TipoLista *lista){
    Apontador anterior = lista->primeiro;
    while(anterior->prox!=NULL){
        anterior = anterior->prox;
    }
    lista->ultimo=anterior;
}