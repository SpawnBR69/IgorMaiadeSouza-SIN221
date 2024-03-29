#include <iostream>

using namespace std;

// Item para armazenar os dados contidos na fila
typedef struct TipoItem
{
    int valor;
} TipoItem;

// Ponteiro para o elemento da fila
typedef struct TipoElemento *Apontador;

// Elemento (célula) da fila
typedef struct TipoElemento
{
    TipoItem item;
    Apontador prox;
} TipoElemento;

// Estrutura da fila
typedef struct TipoFila
{
    Apontador inicio, fim;
    int tamanho;
} TipoFila;

void InicializaFilaCircular(TipoFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila)
{
    return (fila->inicio == NULL);
}

void Enfileira(TipoFila *fila, TipoItem item)
{
    Apontador novo = new TipoElemento;
    novo->item = item;
    novo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->fim->prox = fila->inicio;
    fila->tamanho++;
}

void Desenfileira(TipoFila *fila, TipoItem *item)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    *item = aux->item;
    fila->inicio = aux->prox;
    fila->fim->prox = fila->inicio;
    delete aux;
    fila->tamanho--;
}

void EsvaziaFila(TipoFila *fila)
{
    TipoItem item;
    while (!VerificaFilaVazia(fila))
    {
        Desenfileira(fila, &item);
    }
}

void ImprimeFila(TipoFila *fila)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != fila->fim)
    {
        cout << aux->item.valor << " -> " << aux->prox->item.valor << endl;
        aux = aux->prox;
    }
    cout << aux->item.valor << " -> " << aux->prox->item.valor << endl;
}