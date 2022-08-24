#include <iostream>
#include "funcoeslista.hpp"
 
using namespace std;
 
int main() {
    TipoLista lista;
    TipoItem item1;
    TipoItem item2;
    TipoItem item3;
    TipoItem item4;
    item1.chave=9;
    item2.chave=13;
    item3.chave=19;
    item4.chave=23;
    criaListaVazia(lista);
    insereItem(lista,item1);
    insereItem(lista,item2);
    insereItem(lista,item3);
    insereItem(lista,item4);
    cout << pesquisaItem(lista,item1);
}