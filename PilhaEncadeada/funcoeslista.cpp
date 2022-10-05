#include <iostream>
 
using namespace std;
 
typedef struct item{
    int id;
    string nome;
}item;

typedef struct elemento *apontador;

typedef struct elemento{
    item item;
    apontador prox;
}elemento;

typedef struct pilha{
    apontador topo;
    int tamanho;
}pilha;

void criaPilhaVazia(pilha *pilha){
    pilha->tamanho=0;
    pilha->topo= NULL;
}

bool verificaPilhaVazia(pilha pilha){
    if(pilha.tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}

void empilha(pilha *pilha, item item){
    apontador aux = new elemento;
    aux->item = item;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

apontador desempilha(pilha *pilha){
    apontador aux;
    apontador item;
    if(verificaPilhaVazia){
        return NULL;
    }
    item = pilha->topo;
    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    delete aux;
    pilha->tamanho--;
    
    return item;
}

void imprimePilha(pilha pilha){
    apontador aux = pilha.topo;
    while(aux != NULL){
        cout << aux->item.id << endl;
        aux = aux->prox;
    }
}

apontador consultaPorId(pilha *pilha,int id){
    apontador aux = pilha->topo;
    while(aux != NULL){
        if(aux->item.id == id){
            return aux;
        }
        aux = aux->prox;
    }
}

apontador consultaPorNome(pilha *pilha,string nome){
    apontador aux = pilha->topo;
    while(aux != NULL){
        if(aux->item.nome == nome){
            return aux;
        }
        aux = aux->prox;
    }
}