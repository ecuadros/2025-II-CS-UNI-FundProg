#include <iostream>
#include "funcion.h"
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
   9. Ruiz Romero Fabrizzio Roberto
*/
// Forma 1 de Compilar: 
// g++ -std=c++17 -Wall -g -pthread -o main main.cpp
// Forma #2 de Compilar (requiere el archivo Makefile)
// make

int main(){
    cout << "Hello CS-UNI" << endl;
    int a, b=5, c=8;
    a = test(b, c);
    cout << "a=" << a << endl;
    return 0;
}

// Forma #2: sirve para recibir parametros por linea de comando.
// int main(int nArgs, char *pArgs[]){
//     cout << "Hello Alg y EDA-UNI (forma #2)" << endl;
//     int i;
//     for(i = 0 ; i < nArgs ; ++i){
//         cout << pArgs[i] << endl;
//     }
// }

// Forma #3: sirve para recibir parametros por linea de comando y
//           para recibir las varoables de entorno
// int main(int nArgs, char *pArgs[], char *pEnv[]){
//     cout << "Hello Alg y EDA-UNI (forma #2)" << endl;
//     int i;
//     cout << "Parametros:" << endl;
//     for(i = 0 ; i < nArgs ; ++i)
//         cout << "\t" << pArgs[i] << endl;
    
//     cout << "Variables de entorno:" << endl;
//     for(i = 0 ; pEnv[i] != nullptr ; ++i)
//         cout << "\t" << pEnv[i] << endl;
// }

