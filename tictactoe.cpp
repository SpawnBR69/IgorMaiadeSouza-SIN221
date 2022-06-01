#include <iostream>
#include <cstring>
#include <math.h> 
using namespace std;

int checkInteger(){
    int opcao = 0;
    char s[100];
    int i = 0, cont = 0;
    cin >> s;
    for (i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {
            cont++;
        }
    }
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
    for(i = 0; i < strlen(s); i++){
        opcao = opcao + pow(10, strlen(s)-i-1) * (s[i] - '0');
    }
    return opcao;
}

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
    return false;
}

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
 
int main() {
    int optionl, optionc;
    int i, j, vitoriasX = 0, vitoriasO = 0, empates = 0, turnos = 0;
    bool victory = false, turn = true, game;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player = 'X';
    printBoard(board);
    while(game){
        while(victory == false){
                if (turn) {
                    cout << "Player 1: ";
                    cout << "Digite a linha: ";
                    optionl = checkInteger();
                    cout << "Digite a coluna: ";
                    optionc = checkInteger();
                    if(board[optionl - 1][optionc - 1] == ' '){
                        board[optionl - 1][optionc - 1] = player;
                        printBoard(board);
                        victory = gameOver(board);
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
                }else{
                    cout << "Player 2: ";
                    cout << "Digite a linha: ";
                    optionl = checkInteger();
                    cout << "Digite a coluna: ";
                    optionc = checkInteger();
                if(board[optionl - 1][optionc - 1] == ' '){
                    board[optionl - 1][optionc - 1] = player;
                    printBoard(board);
                    victory = gameOver(board);
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
            if(turnos == 9){
                    cout << "Empate!" << endl;
                    empates++;
                    victory = true;
            }
        }
        cout << "Deseja jogar novamente? (1 - Sim / 0 - Nao)" << endl;
        cin >> game;
        victory = false;
    }
    cout << "Vitorias do Player 1: " << vitoriasX << endl;
    cout << "Vitorias do Player 2: " << vitoriasO << endl;
    cout << "Empates: " << empates << endl;
    return 0;
}