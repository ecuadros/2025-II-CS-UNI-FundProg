#include <iostream>
#include <ctime>
#include "juego.h"

using namespace std;

int main() {
    srand(time(0));

    Juego jugador;
    Juego rival; 
    char respuesta;

    cout << "---INICIAMOS---" << endl;

    jugador.tomarCarta();
    jugador.tomarCarta();
    rival.tomarCarta();
    rival.tomarCarta();

    jugador.mostrarCartas("Tu mano");
    cout << "El Rival recibio sus 2 cartas" << endl;

    while (true) {
        if (jugador.sePasoDe21()) {
            cout << "Te pasaste de 21 --El Rival gana--" << endl;
            return 0;
        }

        cout << "Quieres tomar otra carta(t) o plantarte (p): ";
        cin >> respuesta;

        if (respuesta == 't' || respuesta == 'T') {
            jugador.tomarCarta();
            jugador.mostrarCartas("Tu mano");
        } else {
            break;
        }
    }

    cout << "--- Turno del Rival ---" << endl;
    rival.mostrarCartas("Rival");


    while (rival.obtenerPuntos() < 17) {
        cout << "El Rival toma otra carta" << endl;
        rival.tomarCarta();
        rival.mostrarCartas("Rival");
    }


    int ptsJ = jugador.obtenerPuntos();
    int ptsR = rival.obtenerPuntos();

    cout << "--- RESULTADO FINAL ---" << endl;
    if (rival.sePasoDe21() || ptsJ > ptsR) {
        cout << "Felicidades Ganaste" << endl;
    } else if (ptsJ < ptsR) {
        cout << "Perdiste" << endl;
    } else {
        cout << "Es un empate" << endl;
    }

    return 0;
}