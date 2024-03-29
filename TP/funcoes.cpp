#include <iostream>
#include <windows.h>

#define MAXTAM 5

using namespace std;

typedef int ApontadorProj;

typedef struct Proj
{
    int chave;
    string nome;
    int horas ;
};

typedef struct ListaProj
{
    Proj Item[MAXTAM];
    ApontadorProj Primeiro, Ultimo;
    int tamanho;
};


typedef struct Func
{
    int id;
    string nome;
    string endereco;
    int dependentes;
    ListaProj projetos;
} Func;

typedef struct ElementoFunc *ApontadorFunc;

typedef struct ElementoFunc
{ // Célula
    Func item;
    struct ElementoFunc *prox;
} ElementoFunc;

typedef struct ListaFunc
{
    ApontadorFunc primeiro;
    ApontadorFunc ultimo;
    int tamanho = 0;
} ListaFunc;

bool listaCriada = false;



void criaListaVaziaA(ListaProj *lista)
{
    
        lista->tamanho = 0;
        lista->Primeiro = 0;
        lista->Ultimo = lista->Primeiro;
        cout << "Lista criada com sucesso!";
        //listaCriada = true;
    Sleep(1500);
}

int verificaListaVaziaA(ListaProj *lista)
{
    return (lista->Primeiro == lista->Ultimo);
}

int verificaListaCheiaA(ListaProj *lista)
{
    return (lista->Ultimo == MAXTAM);
}

int tamanhoListaA(ListaProj *lista)
{
    return lista->tamanho;
}

int insereItemA(ListaProj *lista, Proj item)
{
    if (verificaListaCheiaA(lista))
    {
        return -1;
    }
    lista->Item[lista->Ultimo] = item;
    lista->tamanho++;
    lista->Ultimo++;
    return 1; 
}

void imprimeListaA(ListaProj lista)
{
    if (listaCriada)
    {
        int Aux;
        for (Aux = lista.Primeiro; Aux <= (lista.Ultimo - 1); Aux++)
        {
            cout << "Chave: " << lista.Item[Aux].chave << endl;
            cout << "Nome: " << lista.Item[Aux].nome << endl;
            cout << "Horas: " << lista.Item[Aux].horas << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Crie a lista primeiramente.";
        Sleep(1000);
    }
}

int pesquisaItemA(ListaProj *lista, int chave)
{
    for (int i = lista->Primeiro; i < lista->Ultimo; i++)
    {
        if (chave == lista->Item[i].chave)
        {
            return i; // Retorna posição do item encontrado
        }
    }
    return -1;
}

void retiraItemA(ListaProj *lista,int p)
{
    int i=0;
    for(i=0;i < MAXTAM; i++){
        if(p == lista->Item[i].chave){
            for(int j=i;j <=lista->Ultimo;j++){
                lista->Item[j] = lista->Item[j+1];
            }
            lista->Ultimo--;
            lista->tamanho--;
        }
    }
}

void criaListaVaziaE(ListaFunc *lista)
{
    if (!listaCriada)
    {
        lista->primeiro = new ElementoFunc;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        listaCriada = true;
    }
    else
    {
        cout << "Lista já existe!";
    }
}

bool verificaListaVaziaE(ListaFunc *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int tamanhoListaE(ListaFunc *lista)
{
    return lista->tamanho;
}
void atualizaUltimo(ListaFunc *lista)
{
    ApontadorFunc aux;
    aux = lista->primeiro;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void insereListaPrimeiroE(ListaFunc *lista, Func *item)
{
    ApontadorFunc aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new ElementoFunc;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    lista->tamanho++;
    atualizaUltimo(lista);
}

void insereListaUltimoE(ListaFunc *lista, Func *item)
{
    lista->ultimo->prox = new ElementoFunc;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void insereListaAposElementoE(ListaFunc *lista, Func *item, int id)
{
    ApontadorFunc aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL)
    {
        if (pAux->item.id == id)
        {
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new ElementoFunc;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    if (find)
    {
        cout << "Item inserido com sucesso!";
        atualizaUltimo(lista);
        lista->tamanho++;
    }
    else
    {
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void imprimeListaE(ListaFunc lista)
{
    if (verificaListaVaziaE(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        cout << "Endereço: " << aux->item.endereco << endl;
        cout << "Número de Dependentes: " << aux->item.dependentes << endl;
        imprimeListaA(aux->item.projetos);
        aux = aux->prox;
    }
    system("pause");
}

int pesquisaItemE(ListaFunc *lista, int id)
{
    ApontadorFunc aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux->item.id;
        }
        aux = aux->prox;
    }
    return -1;
}

void imprimeItemE(ListaFunc *lista, int id)
{
    ApontadorFunc aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereço: " << aux->item.endereco << endl;
            cout << "Número de Dependentes: " << aux->item.dependentes << endl;
            imprimeListaA(aux->item.projetos);
            system("pause");
            return;
        }
        aux = aux->prox;
    }
    cout << "Funcionário não encontrado";
}

void removeListaPrimeiroE(ListaFunc *lista)
{
    if (verificaListaVaziaE(lista))
    {
        return;
    }
    ApontadorFunc aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void removeListaUltimoE(ListaFunc *lista)
{
    if (verificaListaVaziaE(lista))
    {
        return;
    }
    ApontadorFunc aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
    atualizaUltimo(lista);
}

void removeItemPorIdE(ListaFunc *lista, int id)
{
    if (verificaListaVaziaE(lista))
    {
        return;
    }

    ApontadorFunc aux, anterior, x;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
    atualizaUltimo(lista);
}