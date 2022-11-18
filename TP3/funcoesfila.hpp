#ifndef LISTA_H
#define LISTA_H
#include "funcoesfila.cpp"

typedef struct paciente;
typedef struct medico;
typedef struct tipoElemento *apontador;
typedef struct tipoElemento;
typedef struct tipoFila;
typedef struct upa;
void criaFilaVazia(tipoFila *fila);
bool verificaFilaVazia(tipoFila fila);
void enfileira(tipoFila *fila, paciente item);
void enfileiraPrioridade(tipoFila *fila, paciente item);
paciente desenfileira(tipoFila *fila);
void esvaziaFila(tipoFila *fila);
void imprimeFila(tipoFila fila);
void verificaDisponibilidade(upa* upa);
void imprimePerguntas(int i);
void cadastro(upa* upa);
void triagemSemCadastro(upa* upa);

#endif