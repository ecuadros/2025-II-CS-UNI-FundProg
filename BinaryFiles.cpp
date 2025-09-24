#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "BinaryFiles.h"

// Función para escribir datos binarios
void escribirArchivoBinario(const std::string& nombreArchivo) {
    // Crear ofstream en modo binario
    std::ofstream archivo(nombreArchivo, std::ios::binary);
    
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para escritura: " << nombreArchivo << std::endl;
        return;
    }
    
    // Crear algunos datos de ejemplo
    Persona p1 = {31234, 1.75, 30, "Eduardo Rashta"};
    Persona personas[] = {
        {32541, 1.75, 30, "Juan Pérez"},
        {25894, 1.65, 25, "María García"},
        {23456, 1.80, 35, "Carlos López"},
        {18567, 1.70, 28, "Ana Martínez"}
    };
    
    std::cout << "sizeof(int)   : " << sizeof(int)    << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(float) : " << sizeof(float)  << std::endl;
    // Escribir el número de personas primero
    size_t cantidad = sizeof(personas)/sizeof(personas[0]);
    archivo.write((const char*)&cantidad, sizeof(cantidad));
    
    // Escribir cada persona
    archivo.write((const char*)&personas, sizeof(personas));
    
    
    // Ejemplo adicional: escribir datos primitivos
    int numeros[] = {13, 23, 33, 43, 53};
    archivo.write((const char *)numeros, sizeof(numeros));
    
    std::cout << "Datos escritos correctamente en: " << nombreArchivo << std::endl;
    archivo.close();
}

// Función para leer datos binarios
void leerArchivoBinario(const std::string& nombreArchivo) {
    // Crear ifstream en modo binario
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para lectura: " << nombreArchivo << std::endl;
        return;
    }
    
    std::cout << "\nLeyendo datos del archivo: " << nombreArchivo << std::endl;
    
    // Leer la cantidad de personas
    size_t cantidad;
    archivo.read((char *)&cantidad, sizeof(cantidad));
    
    std::cout << "Número de personas en el archivo: " << cantidad << std::endl;

    // Leer las personas
    Persona *personas = new Persona[cantidad];
    // Forma 1: leer 1x1 cada opersona
    // for (size_t i = 0; i < cantidad; ++i)
    //     archivo.read((char *)&personas[i], sizeof(Persona));
    // Forma 2: leer todo el bloque de personas
    archivo.read((char *)personas, cantidad*sizeof(Persona));

    // Imprimir el contenido leido
    for (size_t i = 0; i < cantidad; ++i) {
        std::cout << "Persona "   << i + 1 << ":" << std::endl;
        std::cout << "  ID: "     << personas[i].id << std::endl;
        // std::cout << "  ID: "     << (*(personas+i)).id << std::endl;
        // std::cout << "  ID: "     << (personas+i)->id << std::endl;
        // std::cout << "  ID: "     << (i+personas)->id << std::endl;
        // std::cout << "  ID: "     << i[personas].id << std::endl;
        std::cout << "  Nombre: " << personas[i].nombre << std::endl;
        std::cout << "  Altura: " << personas[i].altura << std::endl;
        std::cout << "  Edad: "   << personas[i].edad << std::endl;
        std::cout << std::endl;
    }
    delete [] personas;

    // Leer los números adicionales
    int numeros[5];
    archivo.read((char *)numeros, sizeof(numeros));
    
    std::cout << "Números adicionales: ";
    for (int num : numeros)
        std::cout << num << " ";
    std::cout << std::endl;
    archivo.close();
}

// Función para leer datos binarios
void leerArchivoRandom(const std::string& nombreArchivo) {
    // Crear ifstream en modo binario
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para lectura: " << nombreArchivo << std::endl;
        return;
    }
    
    std::cout << "\nLeyendo datos del archivo Random: " << nombreArchivo << std::endl;
    
    size_t offset = 0;
    // Leer la cantidad de personas
    size_t cantidad;
    archivo.read((char *)&cantidad, sizeof(cantidad));
    offset += sizeof(cantidad) + cantidad*sizeof(Persona);

    archivo.seekg(offset, std::ios_base::beg);

    // Leer los números adicionales
    int numeros[5];
    archivo.read((char *)numeros, sizeof(numeros));
    
    std::cout << "Números adicionales con acceso random: ";
    for (int num : numeros)
        std::cout << num << " ";
    std::cout << std::endl;
    archivo.close();
}

// Ejemplo con std::string y vector (más avanzado)
void ejemploConContenedoresSTL() {
    std::string nombreArchivo = "datos_complejos.bin";
    
    // Escritura
    {
        std::ofstream archivo(nombreArchivo, std::ios::binary);
        
        std::vector<std::string> textos = {"Hola", "Mundo", "C++17", "Binario"};
        
        // Escribir cantidad de textos
        size_t count = textos.size();
        archivo.write(reinterpret_cast<const char*>(&count), sizeof(count));
        
        // Escribir cada texto (primero la longitud, luego los caracteres)
        for (const auto& texto : textos) {
            size_t longitud = texto.size();
            archivo.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
            archivo.write(texto.c_str(), longitud);
        }
        
        std::cout << "Contenedores STL escritos correctamente." << std::endl;
    }
    
    // Lectura
    {
        std::ifstream archivo(nombreArchivo, std::ios::binary);
        
        size_t count;
        archivo.read(reinterpret_cast<char*>(&count), sizeof(count));
        
        std::vector<std::string> textos;
        textos.reserve(count);
        
        for (size_t i = 0; i < count; ++i) {
            size_t longitud;
            archivo.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
            
            std::string texto(longitud, '\0');
            archivo.read(&texto[0], longitud);
            textos.push_back(std::move(texto));
        }
        
        std::cout << "Textos leídos: ";
        for (const auto& texto : textos) {
            std::cout << texto << " ";
        }
        std::cout << std::endl;
    }
}

// Función principal
void DemoBinaryFiles() {
    const std::string nombreArchivo = "datos.bin";
    
    // Ejemplo básico con estructura
    escribirArchivoBinario(nombreArchivo);
    leerArchivoBinario(nombreArchivo);

    leerArchivoRandom(nombreArchivo);
    
    // Ejemplo con contenedores STL
    // ejemploConContenedoresSTL();
}