#include <iostream>

using namespace std;

/* Revisado por:
   1. Ernesto Cuadros-Vargas
   2. Manuel Arce
   3. Anthonella Fernanda Vegas Villalva
   4. Aldo Jose Aguilar-Alva
   5. Yan Cesar Huallpa Torres 
   6. Fernando Palomino Holgado
   7. Andres Alexander Mayorca Yucra
   8. Xingbeck Caceres  Asto 
*/
// Forma 1 de Compilar: 
// g++ -std=c++17 -Wall -g -pthread -o main main.cpp
// Forma #2 de Compilar (requiere el archivo Makefile)
// make

// int main(){
//     cout << "Hello CS-UNI" << endl;
//     return 0;
// }

int main(int nArgs, char *pArgs[]){
    cout << "Hello Alg y EDA-UNI (forma #2)" << endl;
    int i;
    for(i = 0 ; i < nArgs ; ++i){
        cout << pArgs[i] << endl;
    }
}



