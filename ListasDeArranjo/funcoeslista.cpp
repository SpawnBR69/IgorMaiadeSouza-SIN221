#include <iostream>
#define maxTam 30

struct TipoItem {
    int chave;
};

struct TipoLista {
    TipoItem item[maxTam];
    int tamanho;
};

void criaListaVazia(TipoLista *lista){
    lista->tamanho = 0;
}

bool verificaListaVazia(TipoLista *lista){
    if(lista->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool verificaListaCheia(TipoLista *lista){
    if(lista->tamanho == maxTam){
        return true;
    }else{
        return false;
    }
}

void imprimeLista(TipoLista lista){
    for(int i =0; i<lista.tamanho;i++){
        std::cout << lista.item[i].chave << std::endl;
    }
}

bool insereItem(TipoLista *lista, TipoItem item){
    if(!verificaListaCheia(lista)){
        lista->item[lista->tamanho] = item;
        lista->tamanho++;
        return true;
    }else{
        return false;
    }
}

int pesquisaItem(TipoLista *lista, int chave){
    for(int i=0; i< lista->tamanho;i++){
        if(lista->item[i].chave == chave){
            return i;
        }
    }
    std::cerr << "Item Não Encontrado!!";
    return -1;
}

void removeItem(TipoLista *lista, int item){
    int posicao = pesquisaItem(lista,item);
    for(int i =posicao; i <lista->tamanho;i++){
        lista->item[i] = lista->item[i+1];
    }
    lista->tamanho--;
}