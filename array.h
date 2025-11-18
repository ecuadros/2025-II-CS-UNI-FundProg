#ifndef __ARRAYS_H__
#define __ARRAYS_H__
#include <iostream>
#include "general/types.h"
using namespace std;

template <typename T>
class CVector{
private:
    T *m_pArray;
    size_t m_size;
public:
    CVector(size_t n) : m_size(n){
        CreateArray();
    }
    ~CVector(){
        DestroyArray();
    }
    void CreateArray(){
        m_pArray = new T [m_size]; // Pido memoria para n elementos de tipo T
    }

    void ReadArray(istream &is, ostream &os){
        os << "Leyendo " << m_size << " elementos ..." << endl;
        for(size_t i = 0 ; i < m_size ; ++i){
            os << "Ingresar v[" << i << "]: ";
            is  >> m_pArray[i];
        }
    }

    void PrintArray(ostream &os){
        for(size_t i = 0 ; i < m_size ; ++i)
            os << m_pArray[i] << " ";
        os << endl;
    }

    void DestroyArray(){
        // cout << "Liberando la memoria asignada" << endl;
        delete [] m_pArray;    // Liberar la memoria
        m_pArray = nullptr;
    }
};

void DemoArrays();

#endif // __ARRAYS_H__