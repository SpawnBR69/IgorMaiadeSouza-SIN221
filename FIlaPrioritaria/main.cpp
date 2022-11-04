#include <iostream>
#include "funcoesfila.hpp"
 
using namespace std;
 
int main() {
    tipoFila fila;
    tipoItem item;
    criaFilaVazia(&fila);
    item.valor = 69420;
    item.prioridade = 5;
    enfileira(&fila,item);
    item.valor = 80085;
    enfileira(&fila,item);
    item.valor = 42069;
    item.prioridade = 4;
    enfileiraPrioridade(&fila,item);
    item.valor =12345;
    item.prioridade = 4;
    enfileiraPrioridade(&fila,item);
    item.valor = 54321;
    enfileiraPrioridade(&fila,item);
    item.valor = 32145;
    item.prioridade = 3;
    enfileiraPrioridade(&fila,item);
    item.valor = 40985;
    enfileiraPrioridade(&fila,item);
    item.valor=11111;
    item.prioridade = 5;
    enfileira(&fila,item);
    imprimeFila(fila);
}