#include <iostream>

using namespace std;

typedef struct TipoItemD{
    int id;
    string nome;
    string saida;
    double valor_passagem;
}TipoItemD;

typedef struct ElementoD* ApontadorD;

typedef struct ElementoD{
    ApontadorD ant,prox;
    TipoItemD item;
}ElementoD;

typedef struct TipoListaD{
    ApontadorD primeiro,ultimo;
    int tamanho = 0;
}TipoListaD;

void criaListaVaziaD(TipoListaD* lista) {
    lista->primeiro = new ElementoD;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = lista->ultimo;
    lista->ultimo->ant = lista->ultimo;
    lista->tamanho = 0;
}

bool listaVaziaD(TipoListaD* lista) {
    if(lista->tamanho == 0 && lista->ultimo == lista->primeiro) {
        return true;
    }
    return false;
}

void insereItemUltimoD(TipoListaD* lista, TipoItemD item) {
    lista->ultimo->prox = new ElementoD;
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = lista->primeiro;
    lista->primeiro->ant = lista->ultimo;
    lista->tamanho++;
}

void insereItemPrimeiroD(TipoListaD* lista, TipoItemD item) {
    ApontadorD inserido = new ElementoD;
    inserido->item = item;

    inserido->prox = lista->primeiro->prox;
    inserido->ant = lista->primeiro;
    lista->primeiro->prox->ant = inserido;
    lista->primeiro->prox = inserido;
    lista->tamanho++;
}

ApontadorD localizaItemPorIdD(TipoListaD* lista ,int id) {
    ApontadorD aux = lista->primeiro->prox;
    while(aux != lista->primeiro) {
        if(aux->item.id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void insereItemAposElementoD(TipoListaD* lista, TipoItemD item, int id) {
    ApontadorD atual = localizaItemPorIdD(lista, id);

    if(atual == NULL) {
        cout << "Id inexistente!" << endl;
        return;
    }

    ApontadorD inserido = new ElementoD;
    inserido->item = item;

    if(atual == lista->ultimo) {
        insereItemUltimoD(lista ,item);
    }
    else {
        inserido->prox = atual->prox;
        inserido->ant = atual;
        inserido->prox->ant = inserido;
    }
    atual->prox = inserido;
    lista->tamanho++;
}

TipoItemD retiraItemPorIdD(TipoListaD* lista, int id) {
    TipoItemD retorno;
    retorno.id = -1;

    if(listaVaziaD(lista)) {
        return retorno;
    }
    ApontadorD atual = localizaItemPorIdD(lista, id);
    
    if(atual != lista->primeiro) {
        atual->ant->prox = atual->prox;     

        if(atual == lista->ultimo) {
            lista->ultimo = atual->ant;
            lista->primeiro->ant = lista->ultimo;
        }
        else {
            atual->prox->ant = atual->ant;
        }

        retorno = atual->item;
        delete atual;
    }
    lista->tamanho--;
    return retorno;
}

void imprimeItemD(TipoItemD item) {
    if(item.id == -1) {
        cout << "Item inexistente!" << endl;
        return;
    }

    cout << endl;
    cout << "Cidade: " << item.nome << endl;
    cout << "Horario de Saida: " << item.saida << endl;
    cout << "Preco da passagem: " << item.valor_passagem << endl;
    cout << "---------------------";
}

void imprimeListaD(TipoListaD* lista) {
    ApontadorD aux = lista->primeiro->prox;
    while(aux != lista->primeiro) {
        imprimeItemD(aux->item);
        aux = aux->prox;
    }
}

void imprimeListaReversaD(TipoListaD* lista) {
    ApontadorD aux = lista->ultimo;
    while(aux != lista->primeiro) {
        imprimeItemD(aux->item);
        aux = aux->ant;
    } 
}