#ifndef __MATRIXES_H__
#define __MATRIXES_H__
#include <iostream>
#include "array.h"
// #include "general/types.h"
using namespace std;

template <typename T>
void CreateMatrix(T **&pMatrix, size_t rows, size_t cols){
    pMatrix = new T*[rows]; 
        for(size_t i = 0 ; i < rows ; ++i)
            pMatrix[i] = new T[cols];
}

template <typename T>
void ReadMatrix(T **pMatrix, size_t rows, size_t cols){
    cout << "Leyendo " << rows << "*" << cols << " elementos ..." << endl;
    for(size_t i = 0 ; i < rows ; ++i)
        for(size_t j = 0 ; j < cols ; ++j){
            cout << "Ingresar mat[" << i << "][" << j << "]=";
            cin  >> pMatrix[i][j];
        }
}

template <typename T>
void PrintMatrix(T **pMatrix, size_t rows, size_t cols, ostream &os){
     for(size_t i = 0 ; i < rows ; ++i){
        for(size_t j = 0 ; j < cols ; ++j)
            os << "mat[" << i << "][" << j << "]=" << pMatrix[i][j] << " ";
        os << endl;
    }
}

template <typename T>
void DestroyMatrix(T **&pMatrix, size_t rows){
    cout << "Liberando la memoria asignada" << endl;
    for(size_t i = 0 ; i < rows ; ++i)
        delete [] pMatrix[i];
    delete [] pMatrix;    
    pMatrix = nullptr;
}

void DemoMatrixes();

#endif // __MATRIXES_H__