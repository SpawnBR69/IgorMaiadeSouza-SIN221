#include <iostream>
#include <time.h>
#include <windows.h>
 
using namespace std;

int numeros_primos(int maximo){
    time_t tempo,tempo0;
    int cont = 0, cont_primo = 0;
    tempo = time(NULL);
    for(int i = 2;i <= maximo; i++){
        cont = 0;
        for(int j = 2; j<=i;j++){
            if(i%j == 0){
                cont ++;
            }
        }
        if(cont == 1){
            cont_primo ++;
        }
    }
    tempo0 = time(NULL);
    cout << difftime(tempo0,tempo) << " Segundos!" << endl;
    system("pause");
    return cont_primo;
}
 
int main() {
    cout << numeros_primos(2000);
}