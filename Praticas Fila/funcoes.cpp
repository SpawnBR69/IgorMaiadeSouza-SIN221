#include <iostream>
 
using namespace std;

#define MAXTAM 5

typedef struct item{
    int id;
}item;

typedef struct fila{
    item itens[MAXTAM+1];
    int frente, trás,tamanho;
}fila;

void fazFilaVazia(fila *fila){
    fila->tamanho = 0;
}

bool verificaFilaVazia(fila *fila){
    if(fila->tamanho == 0){
        return true;
    }
    return false;
}

void enfileira(fila *fila, item item){
    fila->itens[fila->tamanho] = item;
    fila->tamanho++;
    fila->trás = fila->tamanho;
}

item desinfileira(fila *fila){
    item retorno = fila->itens[0];
    for(int i=0; i<fila->tamanho;i++){
        fila->itens[i] = fila->itens[i+1];
    }
    return retorno;
}