#include <iostream>
#include "agenda.h"
using namespace std;

void MostrarMenu() {
    cout << "\n=== AGENDA DE CONTACTOS ===" << endl;
    cout << "1. Agregar contacto" << endl;
    cout << "2. Listar contactos" << endl;
    cout << "3. Buscar por nombre" << endl;
    cout << "4. Eliminar contacto" << endl;
    cout << "5. Guardar en archivo binario" << endl;
    cout << "6. Cargar desde archivo binario" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione: ";
}

int main(){
    Agenda agenda;
    int opcion;

    do {
        MostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: {
                string nombre, telefono, email;
                cout << "Nombre: ";
                getline(cin, nombre); 
                cout << "Telefono: ";
                getline(cin, telefono);
                cout << "Email: ";
                getline(cin, email);
                agenda.Agregar(nombre, telefono, email);
                break;
            }
            case 2: {
                agenda.Listar();
                break;
            }
            case 3: {
                string texto;
                cout << "Texto a buscar: ";
                getline(cin, texto);
                agenda.Buscar(texto); 
                break;
            }
            case 4: {
                int id;
                std::cout << "ID a eliminar: ";
                std::cin >> id;
                agenda.Eliminar(id);
                break;
            }
            case 5:
                agenda.GuardarEnArchivo("agenda.dat");
                break;
            case 6:
                agenda.CargarDesdeArchivo("agenda.dat");
                break;
            case 7:
                std::cout << "¡Hasta pronto!" << std::endl;
                break;
            default:
                std::cout << "Opción inválida" << std::endl;
        }
    } while(opcion != 7);

    return 0;
}
