#include <iostream>
#include "funcoesfila.hpp"

using namespace std;


int main() {
    upa upa;
    cadastraUpa(&upa);
    cadastro(&upa);
    cout << endl << endl << upa.medicos[0].disponibilidade;
    cout << endl << endl << upa.medicos[1].disponibilidade;
    system("pause");
}