#include <iostream>
#define maxTam 30

struct TipoItem {
    int chave;
};

struct TipoLista {
    TipoItem item[maxTam];
    int tamanho;
};

void criaListaVazia(TipoLista &lista){
    lista.tamanho = 0;
}

bool verificaListaVazia(TipoLista &lista){
    if(lista.tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool verificaListaCheia(TipoLista &lista){
    if(lista.tamanho == maxTam){
        return true;
    }else{
        return false;
    }
}

void imprimeLista(TipoLista &lista){
    for(int i =0; i<lista.tamanho;i++){
        std::cout << lista.item[i].chave << std::endl;
    }
}

bool insereItem(TipoLista &lista, TipoItem item){
    if(!verificaListaCheia(lista)){
        lista.item[lista.tamanho] = item;
        lista.tamanho++;
        return true;
    }else{
        return false;
    }
    
}

int pesquisaItem(TipoLista &lista, TipoItem item){
    for(int i=0; i< lista.tamanho;i++){
        if(lista.item[i].chave == item.chave){
            return i;
        }
    }
    return 0;
}

void removeItem(TipoLista &lista, TipoItem item){
    int posicao = pesquisaItem(lista,item);
    delete &lista.item[posicao];
    for(int i =posicao; i <lista.tamanho-1;i++){
        lista.item[i] = lista.item[i+1];
    }
    delete &lista.item[maxTam-1];
    lista.tamanho--;
}