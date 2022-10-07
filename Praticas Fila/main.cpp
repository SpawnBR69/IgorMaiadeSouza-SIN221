#include <iostream>
#include "funcoes.hpp"
 
using namespace std;
 
int main() {
    fila fila;
    item item,item1,item2,item3,item4;
    item.nome = "LeBron James";
    item1.nome = "The Prom Day";
    item2.nome = "The Long Jade";
    item3.nome = "The Bronze Age";
    item4.nome = "The Bomb Gate";
    fazFilaVazia(&fila);
    enfileira(&fila, item);
    enfileira(&fila, item1);
    enfileira(&fila, item2);
    enfileira(&fila, item3);
    enfileira(&fila, item4);
    imprimeFila(fila);
    desinfileira(&fila);
    cout << endl << endl;
    imprimeFila(fila);
}