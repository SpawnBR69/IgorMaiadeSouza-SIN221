#include <iostream>
#include "funcoeslista.cpp"
 
using namespace std;
 
int main() {
    TipoItem item,item1,item2,item3;
    item.id = 1;
    item1.id = 2;
    item2.id = 3;
    item3.id = 4; 
    TipoLista lista;
    CriaListaVazia(&lista);
    insereListaPrimeiro(&lista, &item);
    insereListaPrimeiro(&lista, &item1);
    insereListaPrimeiro(&lista, &item2);
    insereListaPrimeiro(&lista, &item3);
    atualizaUltimo(&lista);
    imprimeLista(&lista);
    if(verificaListaVazia(lista)){
        cout << "sheesh";
    }else{
        cout << "poggers";
    }
    
}