#include <iostream>
#include "funcoes.hpp"
 
using namespace std;

tipoPilha pedidos;
int codigos = 1;
produtos prod[7];

void arrumaPilha(){
    tipoPilha aux,aux1;
    criaPilhaVazia(&aux);
    criaPilhaVazia(&aux1);
    int tamanhos = pedidos.tamanho;
    for(int i=0;i<pedidos.tamanho;i++){
        empilha(&aux,desempilha(&pedidos));
    }
    float sus = aux.itens[0].distancia;
    float amo = aux.tamanho;
    for(int k=0;k<amo;k++){
        for(int i=0;i<aux.tamanho;i++){
            if(sus < aux.itens[i].distancia)
                sus = aux.itens[i].distancia;
        }
        for(int j = 0; j<amo;j++){
            if(aux.itens[j].distancia == sus){
                empilha(&aux1,aux.itens[j]);
                aux.itens[j].distancia = 200000000000;
            }
        }
    }
    amo = aux1.tamanho;
    for(int i=0;i<amo;i++){
        empilha(&pedidos,desempilha(&aux1));
    }
}

void incluiPedidos(){
    tipoItem item;
    item.codigo = codigos;
    codigos++;
    char dec = 's';
    int i=0;
    while(dec == 's' && i<7){
        cout << "Insira o produto a ser entregue: ";
        //cin >> item.produtos[i];
        item.produtos[i] = 0;
        item.tamanho++;
        cout << "Deseja cadastrar mais produtos?";
        //cin >> dec;
        dec = 'n';
        i++;
    }
    cout << "Qual é a distância a ser percorrida? (em metros)";
    //cin >> item.distancia;
    item.distancia = 1500 + codigos * 10;
    item.valor_pedido = 0;
    for(i=0;i<item.tamanho;i++){
        item.valor_pedido = item.valor_pedido+prod[item.produtos[i]].preco;
    }
    empilha(&pedidos,item);
}

void imprimeMenu(){
    system("cls");
    cout << "______________________________" << endl;
    cout << "|1. Incluir Pedido           |" << endl;
    cout << "|2. Listar Pedidos           |" << endl;
    cout << "|3. Imprimir Cardapio        |" << endl;
    cout << "|4. Despachar Pedido         |" << endl;
    cout << "|5. Sair                     |" << endl;
    cout << "______________________________" << endl;
}
 
int main() {
    geraCardapio(prod);
    int opcao = 0;
    criaPilhaVazia(&pedidos);
    while(opcao != 5){
        imprimeMenu();
        
        cin >> opcao;
        switch (opcao){
        case 1:
            incluiPedidos();
            break;
        case 2:
            arrumaPilha();
            imprimePilha(pedidos);
            system("pause");
            break;
        case 3:
            system("cls");
            for(int i=0; i<7; i++){ 
                cout << prod[i].nome << endl;
                cout << prod[i].preco << " R$"<< endl;
                cout << endl << endl;

            }
            system("pause");
            break;
        case 4:
            cout << "Pedido " << desempilha(&pedidos).codigo << " despachado!";
            break;
        case 5:
            cout << "Deseja mesmo fechar o programa?(s/n)";
            char dec;
            cin >> dec;
            if(dec == 's'){
                opcao = 5;
            }
            break;
        }
    }
}