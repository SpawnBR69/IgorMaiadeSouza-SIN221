#include <iostream>
#include "funcoes.hpp"
#include <fstream>

using namespace std;

ListaFunc lista;
int teste = 1;

void incluirFuncionario(){
    Func funcionario;
    char dec;
    int i=0;
    cout << "Insira o ID do funcionário"<< endl;
    //cin >> funcionario.id;
    funcionario.id = teste;
    teste++;
    cout << "Insira o nome do funcionário"<< endl;
    //cin >> funcionario.nome;
    funcionario.nome = "Igor";
    cout << "Insira o endereço do funcionário"<<endl;
    //cin >> funcionario.endereco;
    funcionario.endereco = "sex";
    cout << "Insira o numero de dependentes do funcionário"<<endl;
    //cin >> funcionario.dependentes;
    funcionario.dependentes = 3;
    cout << "Está trabalhando em algum projeto no momento?(s/n)"<<endl;
    //cin >> dec;
    dec = 's';
    criaListaVaziaA(&funcionario.projetos);
    while(dec == 's' || dec == 'S' && i < 5){
        Proj projeto;
        cout << "Insira o ID do projeto"<<endl;
        //cin >> projeto.chave;
        projeto.chave = 1;
        cout << "Insira o nome do projeto" << endl;
        //cin >> projeto.nome;
        projeto.nome = "sexo";
        cout << "Insira a quantidade de horas semanais do Projeto" << endl;
       // cin >> projeto.horas;
       projeto.horas = 40;
        insereItemA(&funcionario.projetos,projeto);
        i++;
        cout << "Mais algum projeto?"<<endl;
        //cin >> dec;
        dec = 'n';
    }
    insereListaPrimeiroE(&lista,&funcionario);
}

void incluirProjetos(int id){
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    while(aux != NULL){
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
        aux = aux->prox;
    }
    cout << "Id não encontrado";
}

void excluirProjeto(int id){
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    while(aux != NULL){
        if(aux->item.id == id){
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereço: " << aux->item.endereco << endl;
            cout << "Número de Dependentes: " << aux->item.dependentes  << endl;
            imprimeListaA(aux->item.projetos);
            cout << "Deseja excluir algum projeto?(s/n)" << endl;
            char dec;
            cin >> dec;
            if(dec == 's' || dec == 'S'){
                cout << "Qual o id do Projeto que deseja excluir?" << endl;
                int id;
                cin >> id;
                retiraItemA(&aux->item.projetos,id);
                return;
            }
        }
        aux = aux->prox;
    }
    cout << "Id não encontrado";
}

void excluirFuncionario(){
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    while(aux != NULL){
        if(verificaListaVaziaA(&aux->item.projetos) == 1){
            removeItemPorIdE(&lista,aux->item.id);
        }
        aux = aux->prox;
    }
}

void lerArquivo(ListaFunc *liil){
    ifstream entrada("funcionarios.bin");
    if(entrada.is_open()){
        char indicador;
        entrada.get(indicador);
        while(indicador == '$'){
            Func funcionario;
            entrada >> funcionario.id;
            entrada.get();
            entrada >> funcionario.nome;
            entrada >> funcionario.endereco;
            entrada >> funcionario.dependentes;
            entrada.get();
            ListaProj projetos;
            criaListaVaziaA(&projetos);

            entrada.get(indicador);
            while(indicador == '?'){
                Proj projeto;
                entrada >> projeto.chave;
                entrada.get();
                entrada >> projeto.nome;
                entrada.get();
                entrada >> projeto.horas;
                entrada.get(indicador);
                insereItemA(&projetos,projeto);
                entrada.get(indicador);
            }
            funcionario.projetos = projetos;
            insereListaUltimoE(liil,&funcionario); 
        }
    }
}

void salvaArquivo(ListaFunc *liil){
    ofstream saida("funcionarios.bin");
    ApontadorFunc aux;
    aux = liil->primeiro->prox;
    while(aux != NULL){
        saida << "$" << endl;
        saida << aux->item.id << endl;
        saida << aux->item.nome << endl;
        saida << aux->item.endereco << endl;
        saida << aux->item.dependentes << endl;
        for(int i=0;i<aux->item.projetos.tamanho;i++){
            saida << "?" << endl;
            saida << aux->item.projetos.Item[i].chave << endl;
            saida << aux->item.projetos.Item[i].nome << endl;
            saida << aux->item.projetos.Item[i].horas << endl;
        }
        aux = aux->prox;
    }
}

void imprimeContracheque(int id, ListaFunc *liil){
    ApontadorFunc aux;
    float soma=0, inss,ir;
    aux = liil->primeiro->prox;
    while (aux != NULL)
    {
        if(aux->item.id == id){
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereço: " << aux->item.endereco << endl;
            cout << "Número de Dependentes: " << aux->item.dependentes  << endl;
            cout << "Sálario bruto: ";
            for(int i=0;i<aux->item.projetos.tamanho;i++){
                soma = soma + aux->item.projetos.Item[i].horas;
            }
            cout << aux->item.dependentes * 35 + soma * 45 << ",00 R$" << endl;
            cout << "Desconto do INSS: ";
            inss = (aux->item.dependentes * 35 + soma * 45) * 0.085;
            cout << inss << " R$" << endl;
            cout << "Desconto do Imposto de Renda: ";
            ir = (aux->item.dependentes * 35 + soma * 45) * 0.15;
            cout << ir << "R$" << endl;
            cout << "Sálario Liquido: " << (aux->item.dependentes * 35 + soma * 45) - inss - ir << " R$"<< endl;
            return;
        }
        aux = aux->prox;
    }
    
}


int main() {
    criaListaVaziaE(&lista);
    //lerArquivo(&lista);
    incluirFuncionario();
    incluirFuncionario();
    imprimeContracheque(1,&lista);
    //salvaArquivo(&lista);
    //incluirProjetos(1);
    //excluirProjeto(1);
    //imprimeItemE(&lista,1);
    //excluirFuncionario();
    //imprimeListaE(lista);
}