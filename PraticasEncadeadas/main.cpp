#include <iostream>
#include "funcoeslista.cpp"
 
using namespace std;
 
int main() {
    TipoItem item,item1,item2,item3,item4;
    item.id = 1;
    item1.id = 2;
    item2.id = 3;
    item3.id = 4;
    item4.id = 5; 
    TipoLista lista;
    CriaListaVazia(&lista);
    insereListaUltimo(&lista, &item);
    insereListaUltimo(&lista, &item1);
    insereListaUltimo(&lista, &item2);
    insereListaUltimo(&lista, &item3);
    insereListaAposElemento(&lista, &item4, 3);
    removeListaPrimeiro(&lista);
    imprimeLista(&lista);
    if(verificaListaVazia(lista)){
        cout << "sheesh";
    }else{
        cout << "poggers";
    }
    
}