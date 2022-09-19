#include <iostream>
#include "funcoes.hpp"
 
using namespace std;

ListaFunc lista;
 
void incluirFuncionario(){
    Func funcionario;
    char dec;
    int i=0;
    cout << "Insira o ID do funcionário"<< endl;
    cin >> funcionario.id;
    cout << "Insira o nome do funcionário"<< endl;
    cin >> funcionario.nome;
    cout << "Insira o endereço do funcionário"<<endl;
    cin >> funcionario.endereco;
    cout << "Insira o numero de dependentes do funcionário"<<endl;
    cin >> funcionario.dependentes;
    cout << "Está trabalhando em algum projeto no momento?(s/n)"<<endl;
    cin >> dec;
    criaListaVaziaA(&funcionario.projetos);
    while(dec == 's' || dec == 'S' && i < 5){
        Proj projeto;
        cout << "Insira o ID do projeto"<<endl;
        cin >> projeto.chave;
        cout << "Insira o nome do projeto" << endl;
        cin >> projeto.nome;
        cout << "Insira a quantidade de horas semanais do Projeto" << endl;
        cin >> projeto.horas;
        insereItemA(&funcionario.projetos,projeto);
        i++;
        cout << "Mais algum projeto?"<<endl;
        cin >> dec;
    }
    criaListaVaziaE(&lista);
    insereListaPrimeiroE(&lista,&funcionario);
}

void incluirProjetos(int id){
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    while(aux->prox != NULL){
        if(aux->item.id == id){
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereço: " << aux->item.endereco << endl;
            cout << "Número de Dependentes: " << aux->item.dependentes  << endl;
            imprimeListaA(aux->item.projetos);
            Proj projeto;
            char dec;
            cout << "Ainda deseja inserir um projeto?(s/n)";
            cin >> dec;
            if(dec == 's' || dec == 'S'){
                if(aux->item.projetos.tamanho >= 5){
                    cout << "Funcionário já trabalha no número máximo de projetos!";
                    return;
                }
                cout << "Insira o ID do projeto"<<endl;
                cin >> projeto.chave;
                cout << "Insira o nome do projeto" << endl;
                cin >> projeto.nome;
                cout << "Insira a quantidade de horas semanais do Projeto" << endl;
                cin >> projeto.horas;
                insereItemA(&aux->item.projetos,projeto);
                cout << "Projeto inserido com sucesso!";
            }
            return;
        }
    }
    cout << "Id não encontrado";
}

int main() {
    incluirFuncionario();
    imprimeItemE(&lista,1);

}