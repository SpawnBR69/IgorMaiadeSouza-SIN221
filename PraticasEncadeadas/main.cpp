#include <iostream>
#include "funcoeslista.cpp"
 
using namespace std;

void inverteLista(TipoLista *lista){
    if(verificaListaVazia(*lista)){
        return;
    }
    insereListaPrimeiro(lista,&lista->ultimo->item);
    int aux = lista->ultimo->item.id;
    removeListaUltimo(lista);
    for(int i = 0; i< lista->tamanho - 1; i++){
        insereListaAposElemento(lista, &lista->ultimo->item,aux);
        aux = lista->ultimo->item.id;
        removeListaUltimo(lista);
    }
}
 
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
    insereListaUltimo(&lista, &item4);
    imprimeLista(&lista);
    inverteLista(&lista);
    cout << endl;
    cout << endl;
    cout << endl;
    imprimeLista(&lista);
    /*if(verificaListaVazia(lista)){
        cout << "sheesh";
    }else{
        cout << "poggers";
    }*/
    
}