#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void CreateMatrix(ContainerElemType **&pMatrix, size_t rows, size_t cols){
    pMatrix = new ContainerElemType*[rows]; // Pido memoria para rows punteros
    for(size_t i = 0 ; i < rows ; ++i)
        pMatrix[i] = new ContainerElemType[cols];
        // *(pMatrix+i) = new ContainerElemType[cols];
        // *(i+pMatrix) = new ContainerElemType[cols];
        // i[pMatrix] = new ContainerElemType[cols];
}

void ReadMatrix(ContainerElemType **pMatrix, size_t rows, size_t cols){
    cout << "Leyendo " << rows << "*" << cols << " elementos ..." << endl;
    for(size_t i = 0 ; i < rows ; ++i)
        for(size_t j = 0 ; j < cols ; ++j){
            cout << "Ingresar mat[" << i << "][" << j << "]=";
            cin  >> pMatrix[i][j];
            // cin  >> *(pMatrix[i]+j);
            // cin  >> *( *(pMatrix+i) + j);
            // cin  >> j[pMatrix[i]];
            // cin  >> j[i[pMatrix]];
        }
}

void PrintMatrix(ContainerElemType **pMatrix, 
                size_t rows, size_t cols, 
                ostream &os){
    for(size_t i = 0 ; i < rows ; ++i){
        for(size_t j = 0 ; j < cols ; ++j)
            os << "mat[" << i << "][" << j << "]=" << pMatrix[i][j] << " ";
        os << endl;
    }
}

void DestroyMatrix(ContainerElemType **&pMatrix, size_t rows){
    cout << "Liberando la memoria asignada" << endl;
    for(size_t i = 0 ; i < rows ; ++i)
        delete [] pMatrix[i];
    delete [] pMatrix;    // Liberar la memoria
    pMatrix = nullptr;
}

// Version programacion estructurada ... todavia reprobada
void DemoMatrixes(){
    ContainerElemType **pM1 = nullptr;
    size_t rows, cols;

    cout << "Ingrese tamano del Matrix:";
    cin >> rows >> cols;

    // Crear el vector
    CreateMatrix(pM1, rows, cols);
    // Ingresar los valores
    ReadMatrix(pM1, rows, cols);

    PrintMatrix(pM1, rows, cols, cout);
    pM1[2][1] = 7;
    // Imprimir los valores ingresados
    ofstream of1("test.txt");
    cout << "Los valores ingresados son:" << endl;
    PrintMatrix(pM1, rows, cols, of1);

    of1.close();
    // Eliminar la memoria
    DestroyMatrix(pM1, rows);
}