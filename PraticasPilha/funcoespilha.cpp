#include <iostream>
#define MAXTAM 10
 
using namespace std;
 
typedef struct tipoItem{
    char letra;
}tipoItem;

typedef struct tipoPilha{
    tipoItem itens[MAXTAM];
    int tamanho;
};

void criaPilhaVazia(tipoPilha* pilha){
    pilha->tamanho=0;
}

bool verificaPilhaVazia(tipoPilha pilha){
    if(pilha.tamanho == 0){
        return true;
    }
    return false;
}

bool verificaPilhaCheia(tipoPilha pilha){
    if(pilha.tamanho == MAXTAM){
        return true;
    }
    return false;
}

bool empilha(tipoPilha* pilha, tipoItem item){
    if(verificaPilhaCheia(*pilha)){
        return false;
    }
    pilha->itens[pilha->tamanho] = item;
    pilha->tamanho++;
    return true;
}

tipoItem desempilha(tipoPilha* pilha){
    tipoItem item;
    item = pilha->itens[pilha->tamanho -1];
    pilha->itens[pilha->tamanho] = pilha->itens[pilha->tamanho + 1];
    pilha->tamanho--;
    return item;
}