#ifndef __BINARY_FILES_H__
#define __BINARY_FILES_H__
#include <iostream>

// Estructura de ejemplo para demostrar E/S binaria
struct Persona {
    int id;
    double altura;
    float edad;
    char nombre[20];
};

void escribirArchivoBinario(const std::string& nombreArchivo);
void leerArchivoBinario(const std::string& nombreArchivo);
void leerArchivoRandom(const std::string& nombreArchivo);
void DemoBinaryFiles();

#endif