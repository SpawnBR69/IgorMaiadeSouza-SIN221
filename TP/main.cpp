#include <iostream>
#include "funcoes.hpp"
 
using namespace std;
 
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
    while(dec == 's' || i < 5){
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
}


int main() {
    incluirFuncionario();
}