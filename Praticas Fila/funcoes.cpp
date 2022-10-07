#include <iostream>
 
using namespace std;

#define MAXTAM 5

typedef struct item{
    string nome;
    string telefone;
    string solicitacao;
}item;

typedef struct fila{
    item itens[MAXTAM+1];
    int frente, tras, tamanho;
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
    fila->tras = fila->tamanho;
}

item desinfileira(fila *fila){
    item retorno = fila->itens[0];
    for(int i=0; i<fila->tamanho;i++){
        fila->itens[i] = fila->itens[i+1];
    }
    return retorno;
}

void imprimeFila(fila fila){
    for(int i = 0; i<fila.tamanho;i++){
        cout << fila.itens[i].nome << endl;
    }
}