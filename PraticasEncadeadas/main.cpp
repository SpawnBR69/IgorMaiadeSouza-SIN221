#include <iostream>
#include "funcoeslista.cpp"
 
using namespace std;
 
int main() {
    TipoItem item;
    item.id = 1;
    TipoLista lista;
    CriaListaVazia(&lista);
    insereListaPrimeiro(&lista, &item);
    atualizaUltimo(&lista);
    if(verificaListaVazia(lista)){
        cout << "sheesh";
    }else{
        cout << "poggers";
    }
}