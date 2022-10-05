#include <iostream>
#include "funcoeslista.hpp"
 
using namespace std;
 
int main() {
    pilha divisoes,binario;
    criaPilhaVazia(&divisoes);
    criaPilhaVazia(&binario);
    int num;
    item div, bin;
    cin >> num;
    div.id = num/2;
    bin.id = num%2;
    empilha(&divisoes,div);
    empilha(&binario,bin);
    while(div.id != 0){
        bin.id = div.id%2;
        div.id = div.id/2;
        empilha(&divisoes,div);
        empilha(&binario,bin);
    }
    desempilha(&divisoes);
    imprimePilha(divisoes);
    cout << endl << endl << endl;
    imprimePilha(binario);
    cout << endl << endl << endl;

    pilha sla;
    criaPilhaVazia(&sla);
    item sheesh;
    sheesh.id = 2;
    sheesh.nome = "BigFloppa";
    empilha(&sla,sheesh);
    cout << consultaPorNome(&sla,"BigFloppa")->item.id << endl;
    cout << consultaPorId(&sla,2)->item.nome << endl;
}