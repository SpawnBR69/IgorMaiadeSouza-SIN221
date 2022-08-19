#include <iostream>
#include <fstream>

using namespace std;
 
int main() {
    ofstream OutF("exec3.txt");
    int decimal[10], binary = 0, remainder, product = 1;
    for(int i = 0; i<10;i++){
        cout << "Digite o decimal desejado: ";
        cin >> decimal[i];
        OutF << decimal[i] << "\t";
        while (decimal[i] != 0) {
            remainder = decimal[i] % 2;
            binary = binary + (remainder * product);
            decimal[i] = decimal[i] / 2;
            product *= 10;
        }
        OutF << binary << endl;
        binary = 0;
        product = 1;
    }
}