#include <iostream>
#include "funcoesSimples.hpp"
#include <windows.h>

using namespace std;

//Cadastro da linha inicial para testes.
void cadastraLinhasInicio(TipoLista* lista){
    TipoItem linha;
    TipoItemD parada;
    linha.companhia = "Saritur";
    linha.id = "00121";
    criaListaVaziaD(&linha.cidades);
    //Cadastro das paradas da linha
    parada.id = 1;
    parada.nome = "SJE";
    parada.valor_passagem = 13.0;
    parada.saida = "00:15";
    insereItemUltimoD(&linha.cidades,parada);

    parada.id = 2;
    parada.nome = "GHS";
    parada.valor_passagem = 19.0;
    parada.saida = "00:50";
    insereItemUltimoD(&linha.cidades,parada);

    parada.id = 3;
    parada.nome = "ITA";
    parada.valor_passagem = 23.4;
    parada.saida = "04:05";
    insereItemUltimoD(&linha.cidades,parada);

    parada.id = 4;
    parada.nome = "BHZ";
    parada.valor_passagem = 17.0;
    parada.saida = "05:30";
    insereItemUltimoD(&linha.cidades,parada);

    insereListaPrimeiro(lista,&linha);
}
 
//Pesquisa linhas de acordo com o código.
void pesquisaLinhaPorCodigo(TipoLista* lista){
    string codigo;
    cout << "Digite o código a ser pesquisado: ";
    cin >> codigo;
    imprimeItem(lista,codigo);
}

//Pesquisa pelas linhas de acordo com uma origem e um destino.
void pesquisaLinhaPorOrigemDestino(TipoLista* lista){
    Apontador aux = lista->primeiro->prox;
    string origem,destino,chegada,saida;
    //Variaveis para checagem se foram encontrados a origem e o destino.
    bool dest = FALSE , orig = FALSE;
    //Variavel do valor da passagem.
    double valor_real = 0;
    //Variavel que diz quantas linhas foram encontradas.
    int rodou = 0;
    cout << "Digite a origem: ";
    getline(cin,origem);
    cout << "Digite o destino: ";
    getline(cin,destino);
    while(aux != NULL){
        valor_real = 0;
        ApontadorD auxP = aux->item.cidades.primeiro->prox;
        dest = FALSE; 
        orig = FALSE;
        while(auxP != aux->item.cidades.primeiro){
            if(auxP->item.nome == destino){
                dest = !dest;
                chegada = auxP->item.saida;
                while(auxP != aux->item.cidades.primeiro){
                    valor_real += auxP->item.valor_passagem;
                    auxP = auxP->ant;
                    if(auxP->item.nome == origem){
                        orig = !orig;
                        saida = auxP->item.saida;
                        break;
                    }
                }
                break;
            }
            auxP = auxP->prox;
        }
        if(orig && dest){
            cout << "ID: " << aux->item.id << endl;
            cout << "Companhia: " << aux->item.companhia << endl;
            cout << "Chegada/Saída: " << chegada << "/" << saida; 
            cout << "Valor da Passagem: " << valor_real << endl;
            rodou++;
        }
        aux = aux->prox;
    }
    if(rodou == 0){
        cout << "Nenhuma Linha Encontrada!";
    }
}

//Insere uma nova linha de onibus.
void insereLinha(TipoLista* lista){
    TipoItem linha;
    TipoItemD parada;
    string comp,id;
    char dec = 's';
    cout << "Digite o id da linha: ";
    getline(cin,id);
    linha.id = id;
    cout << "Digite a companhia: ";
    getline(cin,comp);
    linha.companhia = comp;
    while(dec == 's'){
        int i=1;
        string nome,hora;
        double valor;
        cout << "Digite o nome da " << i <<"ª parada: ";
        getline(cin,nome);
        parada.nome = nome;
        cout << "Digite o valor da passagem da parada: ";
        cin >> valor;
        cin.ignore();
        parada.valor_passagem = valor;
        cout << "Digite o horário de saida da parada(hh:mm): ";
        getline(cin,hora);
        parada.saida = hora;
        parada.id = i;
        if(i >= 2){
            cout << "Deseja cadastrar mais paradas?(s/n)";
            cin >> dec;
            cin.ignore();
        }
        i++;
    }
}

//Insere uma parada em uma linha existente.
void incluirParada(TipoLista* lista){
    string id;
    cout << "Qual o id da linha que deseja incluir uma parada?";
    getline(cin,id);
    Apontador aux = lista->primeiro->prox;
    while(aux != NULL){
        if(aux->item.id == id){
            imprimeListaD(&aux->item.cidades);
            TipoItemD parada;
            string nome,hora,pAnterior;
            double valor;
            cout << "Digite o nome da parada: ";
            getline(cin,nome);
            parada.nome = nome;
            cout << "Digite o valor da passagem da parada: ";
            cin >> valor;
            cin.ignore();
            parada.valor_passagem = valor;
            cout << "Digite o horário de saida da parada(hh:mm): ";
            getline(cin,hora);
            parada.saida = hora;
            cout << "Digite o nome da parada antes da que está sendo adicionada: ";
            getline(cin,pAnterior);
            int id =  aux->item.cidades.ultimo->item.id + 1;
            parada.id = id;
            ApontadorD auxP = aux->item.cidades.primeiro->prox;
            while(auxP != aux->item.cidades.primeiro){
                if(auxP->item.nome == pAnterior){
                    insereItemAposElementoD(&aux->item.cidades,parada,auxP->item.id);
                    cout << "PARADA INSERIDA COM SUCESSO";
                    return;
                }
                auxP = auxP->prox;
            }
            cout << "PARADA NÂO ENCONTRADA!";
            return;
        }
        aux = aux->prox;
    }
    cout << "LINHA NÂO ENCONTRADA";
}

//Altera uma parada de uma linha existente.
void alterarParada(TipoLista* lista){
    string id;
    cout << "Qual o id da linha que deseja alterar uma parada?";
    getline(cin,id);
    Apontador aux = lista->primeiro->prox;
    while(aux != NULL){
        if(aux->item.id == id){
            imprimeListaD(&aux->item.cidades);
            string nome;
            cout << "Qual o nome da parada que deseja alterar?";
            getline(cin,nome);
            ApontadorD auxP = aux->item.cidades.primeiro->prox;
            while(auxP != aux->item.cidades.primeiro){
                if(auxP->item.nome == nome){
                    cout << "Insira o novo nome da parada: ";
                    getline(cin, auxP->item.nome);
                    cout << "Digite o novo valor da passagem da parada: ";
                    cin >> auxP->item.valor_passagem;
                    cin.ignore();
                    cout << "Digite o novo horário de saida da parada(hh:mm): ";
                    getline(cin,auxP->item.saida);
                    cout << "PARADA ALTERADA COM SUCESSO!";
                    return;
                }
                auxP = auxP->prox;
            }
            cout << "PARADA NÂO ENCONTRADA";
            return;
        }
        aux = aux->prox;
    }
    cout << "LINHA NÂO ENCONTRADA";
}

//Elimina uma parada de uma linha existente.
void eliminarParada(TipoLista* lista){
    string id;
    cout << "Qual o id da Linha que deseja excluir uma parada?";
    getline(cin,id);
    Apontador aux = lista->primeiro->prox;
    while(aux != NULL){
        if(aux->item.id == id){
            imprimeListaD(&aux->item.cidades);
            string nome;
            cout << "Qual o nome da parada que deseja excluir?";
            getline(cin,nome);
            ApontadorD auxP = aux->item.cidades.primeiro->prox;
            while(auxP != aux->item.cidades.primeiro){
                if(auxP->item.nome == nome){
                    retiraItemPorIdD(&aux->item.cidades,auxP->item.id);
                    cout << "Parada excluida!!!";
                    return;
                }
                auxP = auxP->prox;
            }
            cout << "PARADA NÂO ENCONTRADA";
        }
        aux = aux->prox;
    }
    cout << "LINHA NÃO ENCONTRADA";
}

//Elimina toda uma linha.
void eliminarLinha(TipoLista* lista){
    string id;
    cout << "Qual o id da Linha que deseja excluir?";
    getline(cin,id);
    removeItemPorId(lista,id);
}

int main() {
    UINT CPAGE_UTF8 = 65001;     
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();     
    SetConsoleOutputCP(CPAGE_UTF8);
    TipoLista linhas;
    CriaListaVazia(&linhas);
    cadastraLinhasInicio(&linhas);
    string senha = "123";
    string pass;
    int i = 0,j,k;
    char dec;
    while(i != 3){
        cout << "_________________________" << endl;
        cout << "|1) Consultar uma linha |" << endl;
        cout << "|2) Opções de Manutenção|" << endl;
        cout << "|3) Sair                |" << endl;
        cout << "_________________________" << endl;
        cout << "Digite a opção desejada: ";
        cin >> i;
        switch (i)
        {
        case 1:
            do{
                cout << "Deseja consultar por id(1) ou por origem destino(2)?";
                cin >> j;
            }while(j != 1 && j != 2);
            if(j == 1){
                cin.ignore();
                pesquisaLinhaPorCodigo(&linhas);
            }else{
                cin.ignore();
                pesquisaLinhaPorOrigemDestino(&linhas);
            }
            break;
        case 2:
            cout << "Insira a senha de administrador: ";
            cin.ignore();
            getline(cin,pass);
            if(pass == senha){
                cout << "_________________________" << endl;
                cout << "|1) Inserir uma linha   |" << endl;
                cout << "|2) Inserir uma parada  |" << endl;
                cout << "|3) Alterar uma parada  |" << endl;
                cout << "|4) Excluir uma parada  |" << endl;
                cout << "|5) Excluir uma linha   |" << endl;
                cout << "_________________________" << endl;
                cout << "Digite a opção desejada: ";
                cin >> k;
                switch (k)
                {
                case 1:
                    cin.ignore();
                    insereLinha(&linhas);
                    break;
                case 2:
                    cin.ignore();
                    incluirParada(&linhas);
                    break;
                case 3:
                    cin.ignore();
                    alterarParada(&linhas);
                    break;
                case 4:
                    cin.ignore();
                    eliminarParada(&linhas);
                    break;
                case 5:
                    cin.ignore();
                    eliminarLinha(&linhas);
                    break;
                default:
                    break;
                }
            }else{
                cout << "Senha incorreta";
            }
            break;
        default:
            cout << "Deseja sair do programa?(s/n)";
            cin >> dec;
            if(dec == 's'){
                i = 3;
            }else{
                i = 0;
            }
            break;
        }
    }
}