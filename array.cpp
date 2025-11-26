#include <iostream>
#include <fstream>
#include <string>
#include "array.h"

using namespace std;

// Version programacion estructurada ... todavia reprobada
void DemoArrays(){
    size_t nElem1 = 0;
    size_t nElem2 = 0;

    cout << "Ingrese tamano del array:";
    cin >> nElem1;

    // Crear el vector
    CVector<int> v1(nElem1);

    // Ingresar los valores
    v1.ReadArray(cin, cout);
    // Imprimir los valores ingresados
    ofstream of1("test-int.txt");
    cout << "Los valores ingresados son:" << endl;
    v1[2] = 25;
    v1.PrintArray(of1);
    of1.close();

    v1.PrintArray(cout);
    cout << "Array v1: " << v1 << endl;

    cout << "Ingrese tamano del array:";
    cin >> nElem2;
    // Crear el vector
    CVector<string> v2(nElem2);
    // Ingresar los valores
    v2.ReadArray(cin, cout);
    // Imprimir los valores ingresados
    ofstream of2("test-string.txt");
    v2.PrintArray(of2);
    v2[4] = "Ernesto";
    v2.PrintArray(cout);
    cout << "Array v2: " << v2 << endl;
    of2.close();
}