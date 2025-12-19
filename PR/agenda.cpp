#include "agenda.h"
#include <fstream>
#include <iostream>
using namespace std;

Agenda::Agenda(size_t capacidadInicial) : m_capacity(capacidadInicial), m_size(0), m_siguienteId(1) {
    m_pContactos = new Contacto[m_capacity];
}


Agenda::Agenda(const Agenda& otro) : m_capacity(otro.m_capacity), m_size(otro.m_size), m_siguienteId(otro.m_siguienteId) {
    m_pContactos = new Contacto[m_capacity];
    for ( size_t i = 0; i < m_size; i++) {
        m_pContactos[i] = otro.m_pContactos[i];
    }
}

Agenda:: ~Agenda() {
    delete[] m_pContactos;
}


void Agenda:: Redimensionar(size_t nuevaCapacidad) {
    Contacto* nuevoArray = new Contacto[nuevaCapacidad];
    for (size_t i = 0; i < m_size; i++){
        nuevoArray[i] = m_pContactos[i];
    }
    delete[] m_pContactos;
    m_pContactos = nuevoArray;
    m_capacity = nuevaCapacidad;
    cout << "Array redimensionado a capacidad: " << m_capacity << endl;
}

void Agenda::Agregar(const string& nombre, const string& telefono, const string& email) {
    if(m_size >= m_capacity){
        Redimensionar(m_capacity * 2);
    }

    m_pContactos[m_size] = Contacto(m_siguienteId++, nombre, telefono, email);
    m_size++;

    cout << "Contacto agregado! (Total: " << m_size << ")" << endl;
}

void Agenda::Listar() const {
    if (m_size == 0) {
        cout << "La agenda está vacía. " << endl;
        return;
    }

    cout << "\n=== LISTA DE CONTACTOS (" << m_size << ") ===" << endl;
    for (size_t i = 0; i < m_size; i++) {
        cout << m_pContactos[i] << endl;
    }
    cout << "Capacidad actual: " << m_capacity << endl;
}

void Agenda::Buscar(const string& texto) const {
    if (m_size == 0) {
        cout << "La agenda está vacía. " << endl;
        return;
    }
    
    bool encontrado = false;
    cout << " Resultados para \"" << texto << "\":" << endl;

    for (size_t i = 0; i < m_size; i++) {
        if (m_pContactos[i].ContieneTexto(texto)) {
            cout << m_pContactos[i]<< endl;
            encontrado = true;
        }
    }

    if (!encontrado){
        cout << "No se encontraron contactos." << endl;
    }
}

void Agenda::Eliminar(int id) {
    if (m_size == 0) {
        cout << "La agenda está vacía." << endl;
        return;
    }

    for (size_t i = 0; i < m_size; i++) {
        if (m_pContactos[i].GetId() == id) {
            for (size_t j = i; j < m_size - 1; j++) {
                m_pContactos[j] = m_pContactos[j + 1];
            }
            m_size--;
            cout << "Contacto eliminado. " << endl;
            return;
        }
    }
    cout << "Contacto no encontrado." << endl;
}

void Agenda::GuardarEnArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::binary);
    if(!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escritura: " << nombreArchivo << endl;
        return;
    }

    archivo.write(reinterpret_cast<const char*>(&m_size), sizeof(m_size));

    for(size_t i = 0; i < m_size; ++i) {
        int id = m_pContactos[i].GetId();
        archivo.write(reinterpret_cast<const char*>(&id), sizeof(id));

        string nombre = m_pContactos[i].GetNombre();
        size_t len = nombre.size();
        archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
        archivo.write(nombre.c_str(), len);

        string telefono = m_pContactos[i].GetTelefono();
        len = telefono.size();
        archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
        archivo.write(telefono.c_str(), len);

        string email = m_pContactos[i].GetEmail();
        len = email.size();
        archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
        archivo.write(email.c_str(), len);
    }

    archivo.close();
    cout << "Datos guardados en: " << nombreArchivo << endl;
}

void Agenda::CargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo.is_open()) {
        cerr << "Error al abrir el archivo para lectura: " << nombreArchivo << endl;
        return;
    }

    delete[] m_pContactos;
    m_size = 0;
    m_siguienteId = 1;

    size_t cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    if(cantidad > m_capacity) {
        m_capacity = cantidad * 2;
        m_pContactos = new Contacto[m_capacity];
    }

    for (size_t i = 0; i < cantidad; ++i) {
        int id;
        archivo.read(reinterpret_cast<char*>(&id), sizeof(id));

        size_t len;
        archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
        string nombre(len, '\0');
        archivo.read(&nombre[0], len);

        archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
        string telefono(len, '\0');
        archivo.read(&telefono[0], len);

        archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
        string email(len, '\0');
        archivo.read(&email[0], len);

        m_pContactos[m_size] = Contacto(id, nombre, telefono, email);
        m_size++;

        if (id >= m_siguienteId) {
            m_siguienteId = id + 1;
        }
    }

    archivo.close();
    cout << "Datos cargados desde: " << nombreArchivo << endl;
}

Contacto& Agenda::operator[](size_t index) {
    return m_pContactos[index];
}

const Contacto& Agenda::operator[](size_t index) const {
    return m_pContactos[index];
}

Agenda& Agenda::operator=(const Agenda& otro) {
    if (this != &otro) {
        delete[] m_pContactos;

        m_capacity = otro.m_capacity;
        m_size = otro.m_size;
        m_siguienteId = otro.m_siguienteId;

        m_pContactos = new Contacto[m_capacity];
        for (size_t i = 0; i < m_size; i++) {
            m_pContactos[i] = otro.m_pContactos[i];
        }
    }
    return *this;
}