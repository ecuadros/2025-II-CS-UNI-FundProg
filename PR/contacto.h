#ifndef __CONTACTO_H__
#define __CONTACTO_H__

#include <iostream>
#include <string>
using namespace std;

class Contacto {
    private:
        int m_id;
        string m_nombre;
        string m_telefono;
        string m_email;
    
    
    public:
        Contacto();
        Contacto(int id, const string& nombre, const string& telefono, const string& email);

        //Constructor por copia
        Contacto(const Contacto& otro);

        virtual ~Contacto();

        //Getters
        int GetId() const {return m_id; }
        string GetNombre() const { return m_nombre; }
        string GetTelefono() const { return m_telefono; }
        string GetEmail() const { return m_email;}

        //Setters
        void SetId(int id) { m_id = id; }
        void SetNombre(const string& nombre) { m_nombre =  nombre; }
        void SetTelefono(const string& telefono) { m_telefono = telefono; }
        void SetEmail(const string& email) { m_email = email; }

        void Print() const;

        bool ContieneTexto(const string& texto) const;

        Contacto& operator=(const Contacto& otro);
        bool operator==(const Contacto& otro) const;
};

ostream& operator<<(ostream& os, const Contacto& contacto);

#endif // __CONTACTO_H__