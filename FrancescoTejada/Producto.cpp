#include <iostream>
#include "Producto.h"
using namespace std;

Producto::Producto(){}
Producto::Producto(int codigo,string nombre,string categoria,double precio,int stock){
    this->codigo=codigo;
    this->nombre=nombre;
    this->categoria=categoria;
    this->precio=precio;
    this->stock=stock;
}

int Producto::getCodigo() const{
    return codigo;
}
string Producto::getNombre() const{
    return nombre;
}
string Producto::getCategoria() const{
    return categoria;
}
double Producto::getPrecio() const{
    return precio;
}
int Producto::getStock() const{
    return stock;
}

void Producto::setNombre(const string& n){
    nombre=n;
}
void Producto::setCategoria(const string& c){
    categoria=c;
}
void Producto::setPrecio(double p){
    precio=p;
}
void Producto::setStock(int s){
    stock=s;
}

void Producto::mostrar() const{
    cout<<codigo<<" | "<<nombre<<" | "<<categoria<<" | "<<precio<<" | "<<stock<<endl;
}