
#ifndef FILA_H
#define FILA_H

#include "funcoes.cpp"

// Funções da fila
void InicializaFilaCircular(TipoFila *fila);
bool VerificaFilaVazia(TipoFila *fila);
void Enfileira(TipoFila *fila, TipoItem item);
void Desenfileira(TipoFila *fila, TipoItem *item);
void EsvaziaFila(TipoFila *fila);
void ImprimeFila(TipoFila *fila);

#endif