#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    char op = 's';
    string nome, telefone;
    ofstream OutF("sheesh.xls");
    while(op == 's'){
        cin >> nome;
        cin >> telefone;
        OutF << nome << "\t" << telefone << endl;
        cout << "Deseja continuar?(s=sim,n=não)";
        cin >> op;
    }
}