#include <iostream>
#include "funcoespilha.hpp"
 
using namespace std;
 
int main() {
    tipoPilha sheesh;
    criaPilhaVazia(&sheesh);

    string nome = "Bruh";

    for(int i=0; i < nome.length(); i++){
        tipoItem item;
        item.letra = nome.at(i);
        empilha(&sheesh,item);
    }

    int aux = sheesh.tamanho + 1;

    for(int i=0;i<aux;i++){
        cout << desempilha(&sheesh).letra;
    }

}