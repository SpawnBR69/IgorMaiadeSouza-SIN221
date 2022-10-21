#include <iostream>

using namespace std;

typedef struct tipoItem {
    int valor;
}tipoItem;

typedef struct tipoElemento *apontador;

typedef struct tipoElemento {
    tipoItem item;
    apontador prox;
}tipoElemento;

typedef struct tipoFila{
    apontador inicio, fim;
    int tamanho;
}tipoFila;

void criaFilaVazia(tipoFila *fila){
    fila->inicio = NULL;
    fila->fim = fila->inicio;
    fila->tamanho = 0;
}

bool verificaFilaVazia(tipoFila fila){
    if(fila.tamanho == 0 && fila.inicio == NULL){
        return true;
    }
    return false;
}

void enfileira(tipoFila *fila, tipoItem item){
    apontador aux =  new tipoElemento;
    aux->item = item;
    aux->prox = NULL;
    if(verificaFilaVazia(*fila)){
        fila->inicio = aux;
        fila->fim = aux;
    }else{
        fila->fim->prox = aux;
        fila->fim = aux;
    }
    fila->tamanho++;
}

apontador desenfileira(tipoFila *fila){
    apontador aux;
    apontador del;
    if(verificaFilaVazia(*fila)){
        return NULL;
    }
    aux = fila->inicio;
    del = fila->inicio;
    fila->inicio = fila->inicio->prox;
    fila->tamanho --;
    //delete del;
    return aux;
}

void esvaziaFila(tipoFila *fila){
    apontador aux = fila->inicio;
    while(aux != NULL){
        apontador del = aux;
        aux = aux->prox;
        delete del;
    }
    criaFilaVazia(fila);
}

void imprimeFila(tipoFila fila){
    if(verificaFilaVazia(fila)){
        return;
    }
    apontador aux = fila.inicio;
    while(aux != NULL){
        cout << aux->item.valor << endl;
        aux = aux->prox;
    }
}
