#ifndef __INVENTARIO_H__
#define __INVENTARIO_H__

#include <string>
#include "Producto.h"

class Inventario{
    private:
    static const int MAX=1000;
    Producto lista[MAX];
    int cantidad;
    
    public:
    Inventario();
    ~Inventario();

    int buscarProducto(int codigo) const;
    bool agregarProducto(const Producto& p);
    bool eliminarProducto(int codigo);
    bool agregarStock(int codigo,int cant);
    bool disminuirStock(int codigo,int cant);
    bool actualizarStock(int codigo,int nuevoStock);

    void ordenarPorNombre();
    void ordenarPorStock();
    void ordenarPorCategoria();
    void ordenarPorCodigo();

    void mostrarInventario()const;
    void reportarAgotados() const;
    void reportarPorAgotarse(int limite) const;
    double valorTotalInventario() const;

    void cargarDesdeArchivo(const string& nombreArchivo);
    void guardarEnArchivo(const string& nombreArchivo) const;
    void registrarLog(const string& mensaje) const;

    void menu();
};

#endif