#ifndef __IMPRIMIR_H__
#define __IMPRIMIR_H__

#include <iostream>
#include "types.h"

namespace Impresion{

    template <typename T>
    void Mostrar(T mensaje){
        cout << mensaje << endl;
    }

    template <typename T>
    void MostrarSinSalto(T mensaje){
        cout << mensaje;
    }

    template <typename T>
    void Leer(T &variable){
        cin >> variable;
    }
}

#endif