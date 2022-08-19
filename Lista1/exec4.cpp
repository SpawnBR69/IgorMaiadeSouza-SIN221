#include <iostream>
#include <time.h>
#include <fstream>
 
using namespace std;
 
int main() {
    int lado;
    cin >> lado;
    int matriz[lado][lado];
    ofstream OutF("sus.xls");
    srand(time(NULL));
    for(int i=0;i<lado;i++){
        for(int j = 0;j<lado;j++){
            matriz[i][j] = (rand() % 99) + 1;
        }
    }
    for(int i=0;i<lado;i++){
        for(int j = 0;j<lado;j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i=0;i<lado;i++){
        for(int j = 0;j<lado;j++){
            OutF << matriz[i][j] << "\t";
        }
        OutF << endl;
    }
}