#include <iostream>
#include "funcoes.hpp"
 
using namespace std;
 
int main() {
    TipoItem item;
    TipoLista lista;
    item.id = 10;
    CriaListaVazia(&lista);
    insereListaPrimeiro(&lista,item);
    item.id = 20;
    insereListaPrimeiro(&lista,item);
    item.id = 30;
    insereListaUltimo(&lista,item);
    cout << lista.primeiro->prox->item.id;
    cout << lista.primeiro->prox->prox->item.id;
    cout << lista.ultimo->item.id;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    removeItemPorId(&lista,20);
    cout << lista.primeiro->prox->item.id << endl;
    cout << lista.primeiro->prox->prox->item.id << endl;
    cout << lista.ultimo->item.id << endl;
    
}