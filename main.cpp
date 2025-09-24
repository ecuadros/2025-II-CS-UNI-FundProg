#include <iostream>
#include "funcion.h"
#include "parametros.h"
#include "sorting.h"
#include "array.h"
#include "recursion.h"
#include "const.h"
#include "matrix.h"
#include "structs.h"
#include "BinaryFiles.h"

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
   10. Francesco Renan Piccone Tejada
   11. Marco Antonio Choque Vilca
   12. Fred Camacho Olarte
*/
// Forma 1 de Compilar: 
// g++ -std=c++17 -Wall -g -pthread -o main main.cpp sorting.cpp
// Forma #2 de Compilar (requiere el archivo Makefile)
// make

int main(){
    cout << "Hello CS-UNI" << endl;
    // DemoParametros();
    // DemoSorting();
    // DemoArrays();
    // DemoRecursion();
    // VariablesOverflow();
    // DemoConst();
    // DemoMatrixes();
    // DemoStructs();
    DemoBinaryFiles();
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

