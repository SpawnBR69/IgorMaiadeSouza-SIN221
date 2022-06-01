#include <iostream>
#include <cstring>
#include <math.h> 
using namespace std;

//Função usada para checar se a entrada é inteira
int checkInteger(){
    int opcao = 0;
    //Matriz para armazenar a entrada do usuário
    char s[100];
    int i = 0, cont = 0;
    cin >> s;
    //Verifica se a entrada é um digito
    for (i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {
            cont++;
        }
    }
    //Se a entrada não fot um digito, repete o processo
    while(cont != strlen(s)){
        cout << "Numero invalido, digite novamente: ";
        cin >> s;
        cont = 0;
        for (i = 0; i < strlen(s); i++) {
            if(isdigit(s[i])){
                cont++;
            }
        }
    }
    //Converte a entrada para inteiro
    for(i = 0; i < strlen(s); i++){
        opcao = opcao + pow(10, strlen(s)-i-1) * (s[i] - '0');
    }
    //Retorna a entrada convertida
    return opcao;
}

//Função para checar se o jogo acabou
bool gameOver(char board[3][3]){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X'){
            return true;
        }
        if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O'){
            return true;
        }
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
            return true;
        }
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'){
            return true;
        }
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        return true;
    }
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        return true;
    }
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
        return true;
    }
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        return true;
    }
    //Se nenhuma das condições acima for verdadeira, o jogo não acabou
    return false;
}
//Função para imprimir o tabuleiro
void printBoard(char board[3][3]) {
    system("cls");
    cout << "  1  2  3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "| ";
        }
        cout << endl;
        for(int k = 0; k < 3; k++){
            cout << "---";
        }
        cout << "-" << endl;
    }
}
//Função para jogar
int main() {
    int optionl, optionc;
    int i, j, vitoriasX = 0, vitoriasO = 0, empates = 0, turnos = 0;
    bool victory = false, turn = true, game;
    //Matriz para armazenar o tabuleiro
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    //Armazenando o primeiro jogador
    char player = 'X';
    //Imprimindo o tabuleiro
    printBoard(board);
    //Loop para jogar usando uma variavel booleana para verificar se o jogo acabou
    while(game){
        //Loop que verifica se a rodada acabou
        while(victory == false){
                //If para verificar se é o primeiro jogador
                if (turn) {
                    cout << "Player 1: ";
                    cout << "Digite a linha: ";
                    optionl = checkInteger();
                    cout << "Digite a coluna: ";
                    optionc = checkInteger();
                    //Verifica se a entrada é válida
                    if(board[optionl - 1][optionc - 1] == ' '){
                        board[optionl - 1][optionc - 1] = player;
                        printBoard(board);
                        victory = gameOver(board);
                        //Verifica se o player ganhou
                        if(victory == true){
                            cout << "Player 1 venceu!" << endl;
                            vitoriasX++;
                        }
                        turn = false;
                        player = 'O';
                        turnos++;
                    }else{
                        cout << "Jogada invalida!" << endl;
                    }
                //Else para verificar se é o segundo jogador
                }else{
                    cout << "Player 2: ";
                    cout << "Digite a linha: ";
                    optionl = checkInteger();
                    cout << "Digite a coluna: ";
                    optionc = checkInteger();
                    //Verifica se a entrada é válida
                    if(board[optionl - 1][optionc - 1] == ' '){
                        board[optionl - 1][optionc - 1] = player;
                        printBoard(board);
                        victory = gameOver(board);
                        //Verifica se o player ganhou
                        if(victory == true){
                            cout << "Player 2 venceu!" << endl;
                            vitoriasO++;
                        }
                        turn = true;
                        player = 'X';
                        turnos++;
                    }else{
                        cout << "Jogada invalida!" << endl;
                    }
                }
                //Verifica se houve empate
                if(turnos == 9){
                    cout << "Empate!" << endl;
                    empates++;
                    victory = true;
                }
        }
        //Verifica se o jogador quer jogar novamente
        cout << "Deseja jogar novamente? (1 - Sim / 0 - Nao)" << endl;
        cin >> game;
        victory = false;
    }
    //Imprime o placar depois de acabar o jogo
    cout << "Vitorias do Player 1: " << vitoriasX << endl;
    cout << "Vitorias do Player 2: " << vitoriasO << endl;
    cout << "Empates: " << empates << endl;
    return 0;
}