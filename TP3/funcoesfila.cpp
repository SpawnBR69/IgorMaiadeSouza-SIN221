#include <iostream>
#include <time.h>

using namespace std;

typedef struct paciente {
    string nome;
    int prioridade;
    string endereco;
    string idade;
    string sexo;
    char respostas[18];
}paciente;

typedef struct medico{
    string nome;
    string crm;
    string especialidade;
    bool disponibilidade =  true;
    paciente paciente;
    time_t tempo;
}medico;

typedef struct tipoElemento *apontador;

typedef struct tipoElemento {
    paciente item;
    apontador prox;
}tipoElemento;

typedef struct tipoFila{
    apontador inicio, fim;
    int tamanho;
}tipoFila;

typedef struct upa{
    int atendimentos;
    medico medicos[5];
    tipoFila fila;
}upa;

string perguntas[18] = {"Comprometimento da via aérea","Respiração ineficaz","Choque","Não responde a estímulos","Em convulsão","Dor Severa","Grande hemorragia incontrolável","Alteração do estado de consciência","Temperatura maior ou igual a 39°C","Trauma craniano severo","Dor moderada","Pequena hemorragia incontrolável","Vômito persistente","Temperatura entre 38°C e 39°C","Idoso ou grávida","Dor leve","Náuseas","Temperatura entre 37°C e 38°C"};

void criaFilaVazia(tipoFila *fila){
    fila->inicio = NULL;
    fila->fim = fila->inicio;
    fila->tamanho = 0;
}

bool verificaFilaVazia(tipoFila fila){
    if(fila.tamanho == 0 && fila.inicio == NULL){
        return true;
    }
    return false;
}

void enfileira(tipoFila *fila, paciente item){
    apontador aux =  new tipoElemento;
    aux->item = item;
    aux->prox = NULL;
    if(verificaFilaVazia(*fila)){
        fila->inicio = aux;
        fila->fim = aux;
        fila->tamanho++;
    }else{
        fila->fim->prox = aux;
        fila->fim = aux;
        fila->tamanho++;
    }
}

void enfileiraPrioridade(tipoFila *fila, paciente item){
    apontador aux = fila->inicio, in = new tipoElemento, ant;
    bool i = 1;
    int cont = 0;
    if(verificaFilaVazia(*fila)){
        enfileira(fila,item);
        return;
    }
    while(i){
        if(aux == NULL){
            break;
        }
        if(aux->item.prioridade <= item.prioridade){
            ant = aux;
            aux = aux->prox;
            cont++;
        }else{
            i = 0;
        }
    }
    if(cont > 0){
        in->item = item;
        in->prox = ant->prox;
        ant->prox = in;
        fila->tamanho++;
    }else{
        in->item = item;
        in->prox = aux;
        fila->inicio = in;
        fila->tamanho++;
    }
}

paciente desenfileira(tipoFila *fila){
    apontador del;
    paciente retorno;
    if(!verificaFilaVazia(*fila)){
        del = fila->inicio;
        retorno = del->item;
        fila->inicio = fila->inicio->prox;
        fila->tamanho--;
        delete del;
        return retorno;
    }else{
    }
}

void esvaziaFila(tipoFila *fila){
    apontador aux = fila->inicio;
    while(aux != NULL){
        apontador del = aux;
        aux = aux->prox;
        delete del;
    }
    criaFilaVazia(fila);
}

void imprimeFila(tipoFila fila){
    if(verificaFilaVazia(fila)){
        return;
    }
    apontador aux = fila.inicio;
    while(aux != NULL){
        aux = aux->prox;
    }
}

void verificaDisponibilidade(upa* upa){
    for(int i = 0; i<5;i++){
        if(upa->medicos[i].disponibilidade){
            continue;
        }else if(upa->medicos[i].paciente.prioridade == 0){
            if(((clock() - upa->medicos[i].tempo)/CLOCKS_PER_SEC)/60 >= 60){
                upa->medicos[i].disponibilidade = true;
            }
        }else if(upa->medicos[i].paciente.prioridade == 1){
            if(((clock() - upa->medicos[i].tempo)/CLOCKS_PER_SEC)/60 >= 25){
                upa->medicos[i].disponibilidade = true;
            }
        }else if(upa->medicos[i].paciente.prioridade == 2){
            if(((clock() - upa->medicos[i].tempo)/CLOCKS_PER_SEC)/60 >= 20){
                upa->medicos[i].disponibilidade = true;
            }
        }else if(upa->medicos[i].paciente.prioridade == 3){
            if(((clock() - upa->medicos[i].tempo)/CLOCKS_PER_SEC)/60 >= 12){
                upa->medicos[i].disponibilidade = true;
            }
        }else if(upa->medicos[i].paciente.prioridade == 4){
            if(((clock() - upa->medicos[i].tempo)/CLOCKS_PER_SEC)/60 >= 8){
                upa->medicos[i].disponibilidade = true;
            }
        }
    }
}

void imprimePerguntas(int i){
    cout << perguntas[i] << "?" << endl;
}

void cadastro(upa* upa){
    verificaDisponibilidade(upa);
    char dec = 's';
    do{
        paciente pa;
        system("cls");
        cout << "Digite o nome do paciente: " << endl;
        cin >> pa.nome;
        system("cls");
        cout << "Digite a idade do paciente: " << endl;
        cin >> pa.idade;
        system("cls");
        cout << "Digite o sexo do paciente: " << endl;
        cin >> pa.sexo;
        system("cls");
        cout << "Digite o endereço do paciente: " << endl;
        system("cls");
        int j = 18;
        for(int i = 0; i<18;i++){
            cout << "O paciente possui ";
            imprimePerguntas(i);
            cin >> pa.respostas[i];
            system("cls");

            if(pa.respostas[i] == 's' && i < j){
                j = i;
            }
        }
        if(j < 5){
            pa.prioridade = 0;
        }else if(j < 10){
            pa.prioridade = 1;
        }else if(j < 15){
            pa.prioridade = 2;
        }else if(j<18){
            pa.prioridade = 3;
        }else{
            pa.prioridade = 4;
        }
        enfileiraPrioridade(&upa->fila,pa);
        cout << "Existe mais algum paciente esperando triagem?(s/n)" << endl;
        cin >> dec;
    }while(dec !='n');
    int tamanhoincio = upa->fila.tamanho;
    for(int i = 0; i<5;i++){
        if(!upa->medicos[i].disponibilidade){
            continue;
        }if(verificaFilaVazia(upa->fila)){
            break;
        }
        upa->medicos[i].paciente = desenfileira(&upa->fila);
        upa->medicos[i].disponibilidade = false;
        upa->medicos[i].tempo = clock();
        upa->atendimentos++;
    }
    if(tamanhoincio == upa->fila.tamanho){
        cout << "UPA lotada, espere um médico desocupar e tente novamente";
        return;
    }else{
        cout << "Pacientes encaminhados!";
        return;
    }
}

void triagemSemCadastro(upa* upa){
    if(verificaFilaVazia(upa->fila)){
        cout << "Fila de espera vazia!";
        return;
    }
    verificaDisponibilidade(upa);
    int tamanhoincio = upa->fila.tamanho;
    for(int i = 0; i<5;i++){
        if(!upa->medicos[i].disponibilidade){
            continue;
        }if(verificaFilaVazia(upa->fila)){
            break;
        }
        upa->medicos[i].paciente = desenfileira(&upa->fila);
        upa->medicos[i].disponibilidade = false;
        upa->medicos[i].tempo = clock();
        upa->atendimentos++;
    }
    if(tamanhoincio == upa->fila.tamanho){
        cout << "UPA lotada, espere um médico desocupar e tente novamente";
        return;
    }else{
        cout << "Pacientes encaminhados!";
        return;
    }

}

void cadastraUpa(upa* upa){
    upa->atendimentos = 0;
    criaFilaVazia(&upa->fila);
    upa->medicos[0].nome = "Igor";
    upa->medicos[0].especialidade = "Oftalmo";
    upa->medicos[0].crm = "123";
    upa->medicos[1].nome = "Lucas";
    upa->medicos[1].especialidade = "Oftalmo";
    upa->medicos[1].crm = "321";
    upa->medicos[2].nome = "Tiago";
    upa->medicos[2].especialidade = "Oftalmo";
    upa->medicos[2].crm = "132";
    upa->medicos[3].nome = "Thales";
    upa->medicos[3].especialidade = "Oftalmo";
    upa->medicos[3].crm = "231";
    upa->medicos[4].nome = "Henrique";
    upa->medicos[4].especialidade = "Oftalmo";
    upa->medicos[4].crm = "213";
}

void imprimeAtendimentos(upa* upa){
    verificaDisponibilidade(upa);
    int cont = 0;
    cout << "Atendimentos ocorrendo no momento: ";
    for(int i = 0; i < 5; i++){
        if(upa->medicos[i].disponibilidade){
            continue;
        }
        cout << "Médico: " << upa->medicos[i].nome << endl;
        cout << "Paciente: " << upa->medicos[i].paciente.nome << endl;
        cout << "Nuâncias: " << endl;
        int cont2 = 0;
        for(int j = 0; j < 18; j++){
            if(upa->medicos[i].paciente.respostas[j] == 's'){
                cout << perguntas[j] << endl;
                cont2++;
            }
        }
        if(cont2 == 0){
            cout << "Nenhuma.";
        }
        cont++;
        cout << endl << endl;
    }
    if(cont == 0){
        cout << "Nenhum.";
    }
    system("pause");
}

void liberaMedico(upa* upa, string nome){
    for(int i = 0; i < 5; i++){
        if(upa->medicos[i].nome == nome){
            upa->medicos[i].disponibilidade = true;
            system("cls");
            cout << "Médico liberado!";
            return;
        }
    }
    cout << "Médico não encontrado!";
}

void imprimeMedicos(upa upa){
    system("cls");
    for(int i = 0; i < 5; i++){
        cout << "Nome: " << upa.medicos[i].nome << endl;
        cout << "Especiealidade: " << upa.medicos[i].especialidade << endl;
        cout << "CRM: " << upa.medicos[i].crm << endl;
        if(upa.medicos[i].disponibilidade){
            cout << "Disponibilidade: Disponivel" << endl;
        }else{
            cout << "Disponibilidade: Indisponivel" << endl;
            cout << "Paciente: " << upa.medicos[i].paciente.nome << endl;
            cout << "Tempo de consulta: " << ((clock() - upa.medicos[i].tempo)/CLOCKS_PER_SEC)/60 << "min." << endl;
        }
    }
    system("pause");
}