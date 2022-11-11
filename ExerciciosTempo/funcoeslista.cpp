#include <iostream>
#include <time.h>

using namespace std;
 
typedef struct TipoItem{
    string id;
    time_t inicio;
    time_t entrada;
}TipoItem;

typedef struct Elemento* Apontador;
typedef struct Elemento{
    TipoItem item;
    struct Elemento* prox;
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

void insereListaPrimeiro(TipoLista *lista, TipoItem *item){
    Apontador aux;
    aux = lista ->primeiro->prox;
    lista->primeiro->prox = new Elemento;
    lista -> primeiro -> prox->prox = aux;
    lista -> primeiro ->prox-> item = *item;
    lista->tamanho++;
    atualizaUltimo(lista);
}

void insereListaUltimo(TipoLista *lista, TipoItem *item){
    lista->ultimo->prox = new Elemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox=NULL;
    lista->ultimo->item=*item;
    lista->tamanho++;
}
void insereListaAposElemento(TipoLista *lista, TipoItem *item, string id){
    Apontador aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL){
        if (pAux->item.id == id){
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new Elemento;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    if (find){
        atualizaUltimo(lista);
        lista->tamanho++;
    }
    else{
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void imprimeLista(TipoLista *lista){
    if(verificaListaVazia(*lista)){
        return;
    }
    Apontador anterior = lista->primeiro->prox;
    do{
        cout << "Placa: " << anterior->item.id << endl;
        cout << "Data e Hora de Entrada: " << ctime(&anterior->item.entrada) << endl;
        anterior = anterior->prox;
    }while(anterior!=NULL);
}

time_t retornaTempo(TipoLista *lista, string id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            return aux->item.inicio;
        }
        aux = aux->prox;
    }
    return time(NULL);
}

void imprimeItem(TipoLista *lista, string id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            cout << "ID: " << aux->item.id << endl;
            break;
        }
        aux = aux->prox;
    }
}

void removeListaPrimeiro(TipoLista *lista){
    if (verificaListaVazia(*lista)){
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void removeListaUltimo(TipoLista *lista){
    if (verificaListaVazia(*lista)){
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo){
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void removeItemPorId(TipoLista *lista, string id){
    if (verificaListaVazia(*lista)){
        return;
    }
    Apontador aux, anterior, x;
    x = lista->primeiro;
    while (x != NULL){
        if (x->prox->item.id == id){
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}