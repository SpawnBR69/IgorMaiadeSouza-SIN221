#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    string nome;
    cin >> nome;
    ifstream IntF(nome);
    if(!IntF.is_open()) {
        cout << "Arquivo nao encontrado" << endl;
        return 0;
    }else{
        cout << "Arquivo encontrado" << endl;
        return 0;
    }
}