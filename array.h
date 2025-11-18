#ifndef __ARRAYS_H__
#define __ARRAYS_H__
#include <iostream>
#include "general/types.h"
using namespace std;

template <typename T>
void PrintArray(T *pArray, size_t n, ostream &os){
    for(size_t i = 0 ; i < n ; ++i)
        os << pArray[i] << " ";
    os << endl;
}

template <typename T>
void CreateArray(T*&pArray, size_t n){
    pArray = new T[n];
}

template <typename T>
void ReadArray(T *pArray, size_t n){
    cout << "Leyendo " << n << " elementos ..." << endl;
    for(size_t i = 0 ; i < n ; ++i){
        cout << "Ingresar v[" << i << "]: ";
        cin  >> pArray[i]; //considerar getline(cin,..) si elementos del array son frases
    }
}

template <typename T>
void DestroyArray(T *&pArray){
    cout << "Liberando la memoria asignada" << endl;
    delete[] pArray;
    pArray = nullptr;
}

void DemoArrays();

#endif // __ARRAYS_H__