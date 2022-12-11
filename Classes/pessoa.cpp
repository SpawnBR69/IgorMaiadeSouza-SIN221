#include <iostream>
 
using namespace std;
 
class Pessoa{
    public:
        Pessoa(string nome, int idade, float altura){
            this->nome = nome;
            this->idade =  idade;
            this->altura = altura;
        }
        void mostraDados(){
            cout << nome << endl;
            cout << idade << endl;
            cout << altura << endl;
        }
    private: 
        string nome;
        int idade;
        float altura;
};
