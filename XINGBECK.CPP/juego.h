#ifndef JUEGO_H
#define JUEGO_H

#include <string>

using namespace std;

class Juego {
private:
    int misCartas[10]; 
    int cantidadCartas; 
    int sumaPuntos;
    int ases;

public:
    Juego();
    void tomarCarta(); 
    void mostrarCartas(string nombre) const; 
    int obtenerPuntos() const; 
    bool sePasoDe21() const; 
};

#endif