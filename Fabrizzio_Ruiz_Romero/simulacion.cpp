#include <iostream>
#include <fstream>
#include "simulacion.h"
#include "imprimir.h"
#include "cproyectil.h"
#include "cuerpo.h"

void MostrarResultados(Cuerpo *objeto){
    Impresion::Mostrar(objeto->ATexto());
}

void IniciarSimulacion(){
    VelocidadType v;
    AnguloType a;

    Impresion::Mostrar("---SIMULACION DEL MOVIMIENTO PARABOLICO---");

    //pedimos los datos
    Impresion::MostrarSinSalto("Ingrese la rapidez incial (m/s): ");  
    Impresion::Leer(v);

    Impresion::MostrarSinSalto("Ingrese el angulo de disparo (grados): ");
    Impresion::Leer(a);

    //creamos el objeto
    Cuerpo* proyectil = new CProyectil(v, a);

    Impresion::Mostrar("------------------------------------------");
    Impresion::Mostrar("Resultados calculados:");

    MostrarResultados(proyectil);

    ofstream archivo("historial_simulaciones.txt", ios::app);
    if(archivo.is_open()){
        archivo << "REGISTRO: " << endl
                << proyectil->ATexto() << endl
                << "-----------------------------------" << endl;    
           archivo.close();
           Impresion::Mostrar("\nDatos guardados en 'historial_simulaciones.txt'");
    }else{
        Impresion::Mostrar("[ERROR]: No se pudo acceder al archivo de texto.");
    }

    delete proyectil;
    proyectil = nullptr;
    
    Impresion::Mostrar("-----------------------------------------------");
}