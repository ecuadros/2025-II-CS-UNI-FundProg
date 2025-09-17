#ifndef __MATRIXES_H__
#define __MATRIXES_H__
#include <iostream>
#include "array.h"
// #include "types.h"
using namespace std;

void CreateMatrix(ContainerElemType **&pMatrix, size_t rows, size_t cols);
void ReadMatrix(ContainerElemType *pMatrix, size_t rows, size_t cols);
void PrintMatrix(ContainerElemType *pMatrix, size_t rows, size_t cols, ostream &os);
void DestroyMatrix(ContainerElemType *&pMatrix, size_t rows);
void DemoMatrixes();

#endif // __MATRIXES_H__