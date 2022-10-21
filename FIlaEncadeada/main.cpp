#include <iostream>
#include "funcoesfila.hpp"
 
using namespace std;
 
int main() {
    tipoFila fila;
    criaFilaVazia(&fila);
    tipoItem item;
    item.valor = 42069;
    enfileira(&fila,item);
    item.valor = 69420;
    enfileira(&fila,item);
    item.valor = 80085;
    enfileira(&fila,item);
    imprimeFila(fila);
    desenfileira(&fila);
    imprimeFila(fila);
}