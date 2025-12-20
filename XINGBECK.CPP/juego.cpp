#include "juego.h"
#include <iostream>
#include <cstdlib>
#include <string>

Juego::Juego() {
    sumaPuntos = 0;
    ases = 0;
    cantidadCartas = 0;
}

void Juego::tomarCarta() {
    if (cantidadCartas < 10) {
        int num = (rand() % 13) + 1;
        int valor;

        if (num == 1) {
            valor = 11;
            ases++;
        } else if (num >= 10) {
            valor = 10;
        } else {
            valor = num;
        }

        misCartas[cantidadCartas] = valor;
        cantidadCartas++; 
        sumaPuntos += valor;

        if (sumaPuntos > 21 && ases > 0) {
            sumaPuntos -= 10;
            ases--;
        }
    }
}

void Juego::mostrarCartas(string nombre) const {
    cout << nombre << " tiene: ";
    for (int i = 0; i < cantidadCartas; i++) {
        if (misCartas[i] == 11) cout << "[As] ";
        else cout << "[" << misCartas[i] << "] ";
    }
    cout << "Total: " << sumaPuntos << endl;
}

int Juego::obtenerPuntos() const { 
    return sumaPuntos;
 }
bool Juego::sePasoDe21() const { 
    return sumaPuntos > 21; 
}