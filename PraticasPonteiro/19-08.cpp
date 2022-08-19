#include <iostream>
#include <time.h>
 
using namespace std;

void preencherVetor(int *vet, int tamanho){
    srand(time(NULL));
    for(int i = 0; i<tamanho;i++){
        vet[i] = (rand() % 10) + 1;
    }
}

void procurarNumero(int *vet, int pes, int tam){
    for(int i = 0; i < tam; i++){
        if(vet[i] == pes){
            cout << "Num encontrado kappa, posição: " << i+1 << endl;
        }
    }
}

void exibeVetor(int *vet, int tam){
    for(int i=0; i< tam;i++){
        cout << vet[i] << endl;
    }
}
 
int main() {
    int tam, pes;
    cout << "Tamanho do Vetor";
    cin >> tam;
    cout << "Numero Pesquisado";
    cin >> pes;
    int *vet;
    vet = new int[tam];
    preencherVetor(vet,tam);
    procurarNumero(vet,pes,tam);
    exibeVetor(vet,tam);
    return 0;
}