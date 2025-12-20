#include "cproyectil.h"
#include <sstream>

CProyectil::CProyectil(VelocidadType v, AnguloType a){
    v0 = v;
    theta = a;
}

RealType CProyectil::convertirARadianes(AnguloType grados){
    return grados * (PI / 180.0);
}

DistanciaType CProyectil::CalcularAlturaMax(){
    RealType rad = convertirARadianes(theta);
    RealType vy = v0 * sin(rad); //componente vertical de la velocidad
    return pow(vy,2) / (2*acGravedad);
}

DistanciaType CProyectil::CalcularAlcance(){
    RealType rad = convertirARadianes(theta);
    return (pow(v0,2) * sin(2*rad)) / acGravedad;
}

TiempoType CProyectil::CalcularTiempoVuelo(){
    RealType rad = convertirARadianes(theta);
    return (2 * v0 * sin(rad)) / acGravedad;
}

TextoType CProyectil::ATexto(){
    stringstream ss;
    ss << "Lanzamiento [v0 = " << v0 << "m/s, angulo = " << theta << "grSexagesimales]: " << endl << "Altura Maxima: " 
       << CalcularAlturaMax() << "m " << endl << "Alcance horizontal: " << CalcularAlcance() << "m " 
       << endl << "Tiempo: " << CalcularTiempoVuelo() << "s";

    return ss.str();
}