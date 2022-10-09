#include <iostream>
#include <fstream>
#include "funcoes.hpp"
 
using namespace std;

tipoPilha pedidos;
int codigos = 1;
produtos prod[7];

void lerArquivo(){
    FILE* file = fopen("lanchonete.bin", "r");
    tipoItem pedido;
    if(file != NULL) {
        while(fread(&pedido, sizeof(tipoItem), 1, file)) {
            if(pedido.codigo > codigos) {
                codigos = pedido.codigo;
            }
            empilha(&pedidos, pedido);
        }
    }
}

void salvaArquivo(){
    FILE* file = fopen("lanchonete.bin","w");
    tipoItem pedido;
    while(pedidos.tamanho != 0) {
        pedido = desempilha(&pedidos);
        fwrite(&pedido, sizeof(tipoItem), 1, file);
    }
}

void arrumaPilha(){
    tipoPilha aux,aux1,aux2;
    criaPilhaVazia(&aux);
    criaPilhaVazia(&aux1);
    criaPilhaVazia(&aux2);
    int tamanhos = pedidos.tamanho;
    for(int i=0;i<tamanhos;i++){
        empilha(&aux,desempilha(&pedidos));
    }
    float sus;
    float amo = aux.tamanho;
    while(amo != 0){
        sus = 0;
        for(int i=0;i<aux.tamanho;i++){
            if(sus < aux.itens[i].distancia)
                sus = aux.itens[i].distancia;
        }
        for(int j = 0; j<aux.tamanho;j++){
            if(aux.itens[j].distancia == sus){
                empilha(&aux1,aux.itens[j]);
                aux.itens[j].distancia = 1;
                amo--;
            }
        }
    }
    amo = aux1.tamanho;
    for(int i=0;i<amo;i++){
        empilha(&aux2,desempilha(&aux1));
    }
    for(int i=0;i<amo;i++){
        empilha(&pedidos,desempilha(&aux2));
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
    cin >> item.distancia;
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
    cout << "|5. Colsultar Pedido         |" << endl;
    cout << "|6. Sair                     |" << endl;
    cout << "______________________________" << endl;
}
 
int main() {
    geraCardapio(prod);
    lerArquivo();
    int opcao = 0;
    criaPilhaVazia(&pedidos);
    while(opcao != 6){
        imprimeMenu();
        
        cin >> opcao;
        switch (opcao){
        case 1:
            if(verificaPilhaCheia(pedidos)){
                cout << "FILA DE PEDIDOS CHEIA!";
            }else{
                incluiPedidos();
            }
            break;
        case 2:
            arrumaPilha();
            imprimePilha(pedidos,prod);
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
            cout << "Pedido " << desempilha(&pedidos).codigo << " despachado!" << endl;
            system("pause");
            break;
        case 5:
            int opcao;
            cout << "Qual id você deseja consultar?";
            cin >> opcao;
            for(int i = 0; i<pedidos.tamanho; i++){
                if(pedidos.itens[i].codigo == opcao){
                    system("cls");
                    cout << "Codigo do Pedido: " << pedidos.itens[i].codigo << endl;
                    if (pedidos.itens[i].tamanho > 0){
                        cout << "Produtos: ";
                        int gus = pedidos.itens[i].tamanho;
                        for (int j = 0; j < gus; j++)
                        {
                            cout << prod[pedidos.itens[i].produtos[j]].nome << " ";
                        }
                        cout << endl;
                    }
                    cout << "Valor do Pedido: " << pedidos.itens[i].valor_pedido << endl;
                    cout << "Distancia do Pedido: " << pedidos.itens[i].distancia << endl;
                    system("pause");
                }
            }
            break;
        default:
            cout << "Deseja mesmo fechar o programa?(s/n)";
            char dec;
            cin >> dec;
            if(dec == 's'){
                opcao = 6;
            }else{
                opcao = 7;
            }
            break;
        }
    }
    salvaArquivo();
}