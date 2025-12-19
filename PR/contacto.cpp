#include "contacto.h"
#include <cctype>
#include <algorithm>
using namespace std;

Contacto::Contacto() : m_id(0), m_nombre(""), m_telefono(""), m_email("") {}
Contacto::Contacto(int id, const string& nombre, const string& telefono, const string& email)
    : m_id(id), m_nombre(nombre), m_telefono(telefono), m_email(email) {}

Contacto::Contacto(const Contacto& otro)
    : m_id(otro.m_id), m_nombre(otro.m_nombre), m_telefono(otro.m_telefono), m_email(otro.m_email) {}

Contacto::~Contacto() {

}

void Contacto::Print() const {
    cout << "ID: " << m_id << " | " << m_nombre
         << " | Tel: " << m_telefono << " | Email: " << m_email << endl;
}

//Para convertir a minúsculas
static string ToLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
    return result;
}

bool Contacto::ContieneTexto(const string& texto) const {
    string nombreLower = ToLower(m_nombre);
    string textoLower = ToLower(texto);
    return nombreLower.find(textoLower) != string::npos;
}

Contacto& Contacto::operator=(const Contacto& otro) {
    if(this != &otro) {
        m_id = otro.m_id;
        m_nombre = otro.m_nombre;
        m_telefono = otro.m_telefono;
        m_email = otro.m_email;
    }
    return *this;
}

bool Contacto::operator==(const Contacto& otro) const {
    return m_id == otro.m_id;
}

ostream& operator<<(ostream& os, const Contacto& contacto) {
    os << "ID: " << contacto.GetId() << " | " << contacto.GetNombre()
       << " | Tel: " << contacto.GetTelefono() << " | Email: " << contacto.GetEmail();
    return os;
}