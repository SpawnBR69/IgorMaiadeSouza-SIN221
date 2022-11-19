#include <iostream>
#include "funcoesfila.hpp"

using namespace std;

void imprimeMenu(){
    system("cls");
    cout << "____________________________________________" << endl;
    cout << "|                                          |" << endl;
    cout << "|                                          |" << endl;
    cout << "|            Sistema da UPA                |" << endl;
    cout << "|                                          |" << endl;
    cout << "|                                          |" << endl;
    cout << "____________________________________________" << endl;
    cout << "|1. Imprimir medicos da UPA                |" << endl;
    cout << "|2. Cadastro de pacientes                  |" << endl;
    cout << "|3. Esvaziar lista de espera               |" << endl;
    cout << "|4. Liberar medico                         |" << endl;
    cout << "|5. Imprimir atendimentos atuais           |" << endl;
    cout << "|6. Verifica se as consultas ja terminaram |" << endl;
    cout << "____________________________________________" << endl;
}


int main() {
    upa upa;
    cadastraUpa(&upa);
    int dec;
    
    while(dec != 7){
        imprimeMenu();
        cout << "Digite a opção desejada: ";
        cin >> dec;
        string nome;
        switch (dec)
        {
        case 1:
            imprimeMedicos(upa);
            break;
        case 2:
            cadastro(&upa);
            break;
        case 3:
            triagemSemCadastro(&upa);
        case 4:
            cout << "Digite o nome do médico a ser liberado: ";
            cin >> nome;
            liberaMedico(&upa,nome);
            break;
        case 5:
            imprimeAtendimentos(&upa);
        case 6:
            verificaDisponibilidade(&upa);
        default:
            break;
        }
    }
}