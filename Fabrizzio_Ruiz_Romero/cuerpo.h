#ifndef __CUERPO_H__
#define __CUERPO_H__

#include "Types.h"


//en física le llamamos "cuerpo" a todo objeto de estudio, 
//por eso el nombre de la clase
class Cuerpo{
    public:
        virtual ~Cuerpo() {}
        virtual TextoType ATexto() = 0;
};

#endif