#include <iostream>
#include "funcoes.hpp"
#include <fstream>

using namespace std;

ListaFunc lista;
int teste = 1;
int idProjeto = 0, idFunc = 0;

void incluirFuncionario(){
    Func funcionario;
    char dec;
    int i=0;
    system("cls");
    idFunc += 1;
    funcionario.id = idFunc;
    cout << "Insira o nome do funcionário"<< endl;
    cin >> funcionario.nome;
    cout << "Insira o endereço do funcionário"<<endl;
    cin >> funcionario.endereco;
    cout << "Insira o numero de dependentes do funcionário"<<endl;
    cin >> funcionario.dependentes;
    cout << "Está trabalhando em algum projeto no momento?(s/n)"<<endl;
    cin >> dec;
    criaListaVaziaA(&funcionario.projetos);
    while((dec == 's' || dec == 'S') && i < 5){
        Proj projeto;
        idProjeto += 1;
        projeto.chave = idProjeto;
        cout << "Insira o nome do projeto" << endl;
        cin >> projeto.nome;
        cout << "Insira a quantidade de horas semanais do Projeto" << endl;
        cin >> projeto.horas;
        insereItemA(&funcionario.projetos,projeto);
        i++;
        cout << "Mais algum projeto?"<<endl;
        cin >> dec;
    }
    insereListaPrimeiroE(&lista,&funcionario);
}

void incluirProjetos(int id){
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    system("cls");
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
                projeto.chave = idProjeto;
                idProjeto++;
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
    system("pause");
}

void excluirProjeto(int id){
    ApontadorFunc aux;
    aux = lista.primeiro->prox;
    system("cls");
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
    system("pause");
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

            if(funcionario.id > idFunc){
                idFunc = funcionario.id;
            }

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
                if(projeto.chave > idProjeto){
                    idProjeto = projeto.chave;
                }
                entrada.get(indicador);
            }
            funcionario.projetos = projetos;
            insereListaUltimoE(liil,&funcionario); 
        }
    }
}

void desalocaLista(ListaFunc *lista) {
    ApontadorFunc aux, excluido;
    aux = lista->primeiro->prox;
    while(aux != NULL) {
        excluido = aux;
        aux = aux->prox;
        delete excluido;
    }
    delete aux;
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
    cout << "Id não encontrado!";
    system("pause");
}

int imprimirMenu(){
    system("cls");
    cout << "_____________________________________" << endl;
    cout << "|1. Cadastrar Funcionário           |" << endl;
    cout << "|2. Cadastrar Projetos              |" << endl;
    cout << "|3. Excluir Projetos                |" << endl;
    cout << "|4. Pesquisar Funcionários          |" << endl;
    cout << "|5. Excluir Funcionários s/ Projetos|" << endl;
    cout << "|6. Imprimir Contra Cheque          |" << endl;
    cout << "|7. Sair                            |" << endl;
    cout << "_____________________________________" << endl;
    cout << "Digite sua escolha: ";
    int escolha;
    cin >> escolha;
    return escolha;
}


int main() {
    criaListaVaziaE(&lista);
    lerArquivo(&lista);
    cout << idFunc;
    system("pause");
    int escolha=0, id;
    while(escolha!=7){
        escolha = imprimirMenu();
        switch (escolha){
        case 1:
            incluirFuncionario();
            break;
        case 2:
            cout << "Qual o id do Funcionário? " << endl;
            cin >> id;
            incluirProjetos(id);
            break;
        case 3:
            cout << "Qual o id do Funcionário? " << endl;
            cin >> id;
            excluirProjeto(id);
            break;
        case 4:
            cout << "Qual o id do Funcionário? " << endl;
            cin >> id;
            imprimeItemE(&lista,id);

            break;
        case 5:
            int esc;
            esc = 0;
            while(esc != 1 && esc !=2){
                cout << "Deseja excluir todos os funcionários sem projetos(1) ou algum especifico(2)?" << endl;
                cin >> esc;
                if(esc == 1){
                    excluirFuncionario();
                }else if(esc == 2){
                    cout << "Qual o id do funcionário em questão?" << endl;
                    cin >> id;
                    removeItemPorIdE(&lista,id);
                    cout << "penis";
                    system("pause");
                }
            }
            break;
        case 6:
            cout << "Qual o id do Funcionário? " << endl;
            cin >> id;
            imprimeContracheque(id,&lista);
            system("pause");
            break;
        default:
            cout << "Deseja sair do programa?(s/n)" << endl;
            char dec;
            cin >> dec;
            if(dec == 's'){
                escolha = 7;
            }
            break;
        }
    }
    salvaArquivo(&lista);
    desalocaLista(&lista);
}