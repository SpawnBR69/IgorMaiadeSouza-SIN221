#include <iostream>

using namespace std;
 
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
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id){
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
        cout << "Item inserido com sucesso!";
        atualizaUltimo(lista);
        lista->tamanho++;
    }
    else{
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void imprimeLista(TipoLista *lista){
    verificaListaVazia(*lista);
    Apontador anterior = lista->primeiro->prox;
    do{
        cout << anterior->item.id << endl;
        anterior = anterior->prox;
    }while(anterior!=NULL);
}

int PesquisaItem(TipoLista *lista, int id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            return aux->item.id;
        }
        aux = aux->prox;
    }
    return -1;
}

void ImprimeItem(TipoLista *lista, int id){
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

void RemoveListaPrimeiro(TipoLista *lista){
    if (verificaListaVazia(*lista)){
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista){
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

void RemoveItemPorId(TipoLista *lista, int id){
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