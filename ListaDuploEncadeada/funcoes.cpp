#include <iostream>

using namespace std;
 
typedef struct TipoItem{
 int id;
}TipoItem;

typedef struct Elemento* Apontador;
typedef struct Elemento{
    TipoItem item;
    Apontador prox;
    Apontador ant;
}Elemento;

typedef struct TipoLista{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
}TipoLista;

void CriaListaVazia(TipoLista* lista){
    lista -> primeiro = new Elemento;
    lista -> ultimo = lista -> primeiro;
    lista ->ultimo->prox=NULL;
    lista->ultimo->ant =NULL;
}

bool verificaListaVazia(TipoLista lista){
    return lista.primeiro->prox == lista.ultimo->prox;
}

void atualizaUltimo(TipoLista *lista){
    Apontador ant = lista->primeiro;
    while(ant->prox!=NULL){
        ant = ant->prox;
    }
    lista->ultimo=ant;
}

void insereListaPrimeiro(TipoLista* lista, TipoItem item){
    Apontador novo = new Elemento,aux;
    novo->item = item;
    if(verificaListaVazia(*lista)){
        novo->prox = lista->ultimo->prox;
        novo->ant = lista->primeiro;
        lista->primeiro->prox = novo;
        lista->ultimo = novo;
        return;
    }
    aux = lista->primeiro->prox;
    lista->primeiro->prox = novo;
    novo->ant = lista->primeiro;
    novo->prox = aux;
    aux->ant = novo;
    lista->tamanho++;
}

void insereListaUltimo(TipoLista* lista, TipoItem item){
    lista->ultimo->prox = new Elemento;
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void removeUltimo(TipoLista* lista){
    Apontador aux;
    aux = lista->ultimo;
    lista->ultimo = lista->ultimo->ant;
    lista->ultimo->prox = NULL;
    delete aux;
    lista->tamanho--;
}

void removePrimeiro(TipoLista* lista){
    Apontador aux = lista->primeiro->prox;
    lista->primeiro->prox = lista->primeiro->prox->prox;
    lista->primeiro->prox->ant = NULL;
    delete aux;
    lista->tamanho--;
}

void removeItemPorId(TipoLista* lista,int id){
    Apontador aux = lista->primeiro->prox;
    while(aux != NULL){
        if(id == aux->item.id){
            aux->ant->prox = aux->prox;
            if(aux == lista->ultimo){
                lista->ultimo = aux->ant;
                lista->ultimo->prox = NULL;
            }else{
                aux->prox->ant = aux->ant;
                break;
            }
        }
        aux = aux->prox;
    }
    delete aux;
    lista->tamanho--;
}

void insereItemPorId(TipoLista* lista, int id, TipoItem item){
    Apontador aux =  lista->primeiro->prox,novo,aux1;
    while(aux != NULL){
        if(id == aux->item.id){
            if(aux == lista->ultimo){
                novo = new Elemento;
                novo->item = item;
                insereListaUltimo(lista,item);
            }else{
                novo = new Elemento;
                novo->item = item;
                novo->prox = aux->prox;
                novo->ant = aux->prox->ant;
                aux->prox = novo;
                novo->prox->ant = novo;
            }
        }
        aux = aux->prox;
    }
    lista->tamanho++;
}

void pesquisaItem(TipoLista* lista, int id){
    Apontador aux = lista->primeiro->prox;
    while (aux != NULL){
        if(aux->item.id == id){
            cout << aux->item.id << endl;
            break;
        }
        aux = aux->prox;
    }
}

void imprimeLista(TipoLista lista){
    Apontador aux = lista.primeiro->prox;
    while(aux != NULL){
        cout << aux->item.id << endl;
        aux = aux->prox;
    }
}