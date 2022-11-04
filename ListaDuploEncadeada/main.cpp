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
    item.id = 40;
    insereItemPorId(&lista, 10, item);
    imprimeLista(lista);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    removeUltimo(&lista);
    imprimeLista(lista);
    
}