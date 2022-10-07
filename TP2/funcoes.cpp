#include <iostream>
#define MAXTAM 7
#define MAXPEDIDOS 10
 
using namespace std;

typedef struct produtos{
    int codigo;
    string nome;
    float preco;
}produtos;
 
typedef struct tipoItem{
    int codigo ;
    int produtos [MAXPEDIDOS];
    int tamanho=0;
    float valor_pedido ;
    float distancia ;
}tipoItem;

typedef struct tipoPilha{
    tipoItem itens[MAXTAM];
    int tamanho;
};

void geraCardapio(produtos prod[]){
    for(int i = 0; i<7;i++){
        prod[i].codigo == i;
    }
    prod[0].nome = "Coxinha";
    prod[0].preco = 3.5;
    prod[1].nome = "Empada";
    prod[1].preco = 3;
    prod[2].nome = "Enroladinho";
    prod[2].preco = 2.5;
    prod[3].nome = "Quibe";
    prod[3].preco = 3;
    prod[4].nome = "Coca-Cola Lata";
    prod[4].preco = 3.5;
    prod[5].nome = "Guraná Lata";
    prod[5].preco = 3.5;
    prod[6].nome = "Suco DelVale";
    prod[6].preco = 4;
}

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

void imprimePilha(tipoPilha pilha){
    int amo = pilha.tamanho;
    for(int i = 0; i<amo; i++){
        cout << "Codigo do Pedido: " << pilha.itens[i].codigo << endl;
        /*if(pilha.itens[i].tamanho > 0){
            cout << "Produtos: ";
            int gus = pilha.itens[i].tamanho + 1;
            for(int j = 0; j<gus;i++){
                cout << prod[pilha.itens[i].produtos[j]].nome  << " ";
            }
            cout << endl;
        }*/
        cout << "Valor do Pedido: " << pilha.itens[i].valor_pedido << endl;
        cout << "Distancia do Pedido: " << pilha.itens[i].distancia << endl;
    }
}