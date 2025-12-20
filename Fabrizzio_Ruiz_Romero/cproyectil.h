#ifndef __CPROYECTIL_H__
#define __CPROYECTIL_H__

#include <cmath>
#include <string>
#include "types.h"
#include "cuerpo.h"

class CProyectil : public Cuerpo{
    private:
        VelocidadType v0; //rapidez inicial
        AnguloType theta; //angulo de lanzamiento
        //declaro una función para convertir los grados sexagesimales a radianes)
        RealType convertirARadianes(AnguloType grados);
    public:
        CProyectil(VelocidadType v, AnguloType a);
        DistanciaType CalcularAlturaMax();
        DistanciaType CalcularAlcance();
        TiempoType CalcularTiempoVuelo();
        TextoType ATexto() override; //metodo para devolver todo en texto
};

#endif