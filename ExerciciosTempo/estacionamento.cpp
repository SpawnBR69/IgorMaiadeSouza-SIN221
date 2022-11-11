#include <iostream>
#include <time.h>
#include <windows.h>
#include "funcoeslista.hpp"
 
using namespace std;

void entra(TipoLista* lista){
    TipoItem aux;
    cout << "Insira a placa do carro";
    cin >> aux.id;
    time(&aux.entrada);
    aux.inicio = clock();
    insereListaPrimeiro(lista,&aux);
}

void sai(TipoLista* lista, string id){
    time_t tempo = retornaTempo(lista,id);
    if(tempo == time(NULL)){
        cout << "Carro Não Encontrado!!";
        return;
    }else{
        tempo = (clock() - tempo) / CLOCKS_PER_SEC;
        imprimeItem(lista,id);
        if(tempo < 15){
            cout << "Total a pagar 2.00";
        }else if(tempo >= 15 && tempo < 30){
            cout << "Total a pagar 4.00";
        }else if(tempo >=30 && tempo < 60){
            cout << "Total a pagar 8.00";
        }else if(tempo >= 60){
            float preco = 800 + ((tempo-60) * 10);
            cout << "Total a pagar " << preco/100;
        }
        removeItemPorId(lista, id);
        return;
    }
}

int main() {
    TipoLista lista;
    CriaListaVazia(&lista);
    int num = 0;
    string id;
    char dec;
    while(num != 4){
        switch (num){
        case 1:
            entra(&lista);
            break;
        case 2:
            imprimeLista(&lista);
            break;
        case 3:
            cout << "Qual carro está saindo?" << endl;
            cin >> id;
            sai(&lista,id);
        default:
            cout << "Deseja mesmo sair?(s/n)";
            cin >> dec;
            if(dec == 's'){
                num = 4;
            }
            break;
        }
    }
}