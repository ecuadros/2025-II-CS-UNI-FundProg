#ifndef __AGENDA_H__
#define __AGENDA_H__

#include "contacto.h"

class Agenda {
    private:
        Contacto* m_pContactos;
        size_t m_size;
        size_t m_capacity;
        int m_siguienteId;

        void Redimensionar(size_t nuevaCapacidad);
    
    public:
        Agenda(size_t capacidadInicial = 5);
        Agenda(const Agenda& otro);
        ~Agenda();

        
        void Agregar(const string& nombre, const string& telefono, const string& email);
        void Listar() const;
        void Buscar(const string& texto) const;
        void Eliminar(int id);


        void GuardarEnArchivo(const string& nombreArchivo) const;
        void CargarDesdeArchivo(const string& nombreArchivo);

        //Getters
        size_t GetSize() const { return m_size; }
        size_t GetCapacity() const { return m_capacity; }

        Contacto& operator[](size_t index);
        const Contacto& operator[](size_t index) const;
        Agenda& operator=(const Agenda& otro);
};

#endif // __AGENDA_H__