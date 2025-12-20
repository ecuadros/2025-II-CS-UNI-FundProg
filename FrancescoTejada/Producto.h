#ifndef __PRODUCTO_H__
#define __PRODUCTO_H__

#include <string>
using namespace std;

class Producto{
    private:
    int codigo;
    string nombre;
    string categoria;
    double precio;
    int stock;

    public:
    Producto();
    Producto(int codigo,string nombre,string categoria,double precio,int stock);

    int getCodigo() const;
    string getNombre() const;
    string getCategoria() const;
    double getPrecio() const;
    int getStock() const;

    void setNombre(const string& n);
    void setCategoria(const string& c);
    void setPrecio(double p);
    void setStock(int s);

    void mostrar() const;
};

#endif