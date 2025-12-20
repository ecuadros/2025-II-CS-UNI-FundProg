#include "Inventario.h"
#include "Producto.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;

Inventario::Inventario(){
    cantidad=0;
}
Inventario::~Inventario(){}

int Inventario::buscarProducto(int codigo) const{
    for(int i=0;i<cantidad;i++){
        if(lista[i].getCodigo()==codigo){
            return i;
        }
    }
    return -1;
}

bool Inventario::agregarProducto(const Producto& p){
    if(cantidad<MAX){
        if(buscarProducto(p.getCodigo())==-1){
            lista[cantidad]=p;
            cantidad++;
            registrarLog("Producto codigo "+to_string(p.getCodigo())+" agregado.");
            return true;
        }else{
            cout<<"No se puede agregar, codigo existente."<<endl<<endl;
            return false;
        }
    }else{
        cout<<"No se puede agregar, excede el limite."<<endl<<endl;
        return false;
    }
}

bool Inventario::eliminarProducto(int codigo){
    int indice=buscarProducto(codigo);
    if(indice==-1){
        cout<<"El codigo no existe."<<endl<<endl;
        return false;
    }else{
        for(int i=indice;i<cantidad-1;i++){
            lista[i]=lista[i+1];
        }
        cantidad--;
        registrarLog("Producto codigo "+to_string(codigo)+" eliminado.");
        cout<<"El producto con codigo "<<codigo<<" fue eliminado."<<endl<<endl;
        return true;
    }
}

bool Inventario::agregarStock(int codigo,int cant){
    int indice=buscarProducto(codigo);
    if(indice==-1){
        cout<<"El codigo no existe."<<endl<<endl;
        return false;
    }
    int actual=lista[indice].getStock();
    int nuevo=actual+cant;
    lista[indice].setStock(nuevo);
    registrarLog(to_string(cant)+" agregado a codigo "+to_string(codigo));
    cout<<"Se han agregado "<<cant<<" unidades al codigo "<<codigo<<endl<<endl;
    return true;
}

bool Inventario::disminuirStock(int codigo,int cant){
    int indice=buscarProducto(codigo);
    if(indice==-1){
        cout<<"El codigo no existe."<<endl<<endl;
        return false;
    }
    if(cant<=0){
        cout<<"La cantidad debe ser positiva."<<endl<<endl;
        return false;
    }
    if(lista[indice].getStock()<cant){
        cout<<"Hay menos de "<<cant<<" en stock."<<endl<<endl;
        return false;
    }else{
        int actual=lista[indice].getStock();
        int nuevo=actual-cant;
        lista[indice].setStock(nuevo);
        registrarLog(to_string(cant)+" disminuido a codigo "+to_string(codigo));
        cout<<"Se han disminuido "<<cant<<" unidades al codigo "<<codigo<<endl<<endl;
        return true;
    }
}

bool Inventario::actualizarStock(int codigo,int nuevoStock){
    int indice=buscarProducto(codigo);
    if(indice==-1){
        cout<<"El codigo no existe."<<endl<<endl;
        return false;
    }else{
        lista[indice].setStock(nuevoStock);
        registrarLog("Stock actualizado para codigo "+to_string(codigo));
        cout<<"Se actualizo el stock del codigo "<<codigo<<endl<<endl;
        return true;
    }
}

void Inventario::ordenarPorNombre(){
    for(int i=0;i<cantidad-1;i++){
        int menor=i;
        for(int j=i+1;j<cantidad;j++){
            if(lista[j].getNombre()<lista[menor].getNombre()){
                menor=j;
            }
        }
        if(menor!=i){
            Producto temp=lista[i];
            lista[i]=lista[menor];
            lista[menor]=temp;
        }
    }
    cout<<"El inventario ha sido ordenado por nombre."<<endl<<endl;
}

void Inventario::ordenarPorStock(){
    for(int i=0;i<cantidad-1;i++){
        int menor=i;
        for(int j=i+1;j<cantidad;j++){
            if(lista[j].getStock()<lista[menor].getStock()){
                menor=j;
            }
        }
        if(menor!=i){
            Producto temp=lista[i];
            lista[i]=lista[menor];
            lista[menor]=temp;
        }
    }
    cout<<"El inventario ha sido ordenado por stock."<<endl<<endl;
}

void Inventario::ordenarPorCategoria(){
    for(int i=0;i<cantidad-1;i++){
        int menor=i;
        for(int j=i+1;j<cantidad;j++){
            if(lista[j].getCategoria()<lista[menor].getCategoria()){
                menor=j;
            }
        }
        if(menor!=i){
            Producto temp=lista[i];
            lista[i]=lista[menor];
            lista[menor]=temp;
        }
    }
    cout<<"El inventario ha sido ordenado por categorias."<<endl<<endl;
}

void Inventario::ordenarPorCodigo(){
    for(int i=0;i<cantidad-1;i++){
        int menor=i;
        for(int j=i+1;j<cantidad;j++){
            if(lista[j].getCodigo()<lista[menor].getCodigo()){
                menor=j;
            }
        }
        if(menor!=i){
            Producto temp=lista[i];
            lista[i]=lista[menor];
            lista[menor]=temp;
        }
    }
    cout<<"El inventario ha sido ordenado por codigos."<<endl<<endl;
}

void Inventario::mostrarInventario() const{
    if(cantidad==0){
        cout<<"No hay productos en el inventario."<<endl<<endl;
    }else{
        cout<<"--------- INVENTARIO ---------"<<endl;
        for(int i=0;i<cantidad;i++){
            cout<<"Producto #"<<i+1<<":"<<endl;
            cout<<"Codigo: "<<lista[i].getCodigo()<<endl;
            cout<<"Nombre: "<<lista[i].getNombre()<<endl;
            cout<<"Categoria: "<<lista[i].getCategoria()<<endl;
            cout<<"Precio unitario: "<<lista[i].getPrecio()<<" soles"<<endl;
            cout<<"Stock: "<<lista[i].getStock()<<endl;
            cout<<"------------------------"<<endl;
        }
        cout<<endl;
    }
}

void Inventario::reportarAgotados() const{
    int cont=0;
    cout<<"--------- PRODUCTOS AGOTADOS ---------"<<endl;
    for(int i=0;i<cantidad;i++){
        int stock=lista[i].getStock();
        if(stock==0){
            cout<<"Producto #"<<i+1<<":"<<endl;
            cout<<"Codigo: "<<lista[i].getCodigo()<<endl;
            cout<<"Nombre: "<<lista[i].getNombre()<<endl;
            cout<<"Categoria: "<<lista[i].getCategoria()<<endl;
            cout<<"Precio unitario: "<<lista[i].getPrecio()<<" soles"<<endl;
            cout<<"Stock: "<<lista[i].getStock()<<endl;
            cout<<"------------------------"<<endl;
            cont++;
        }
    }
    if(cont==0){
        cout<<"No hay ningun producto agotado."<<endl<<endl;
    }
    cout<<endl;
}

void Inventario::reportarPorAgotarse(int limite) const{
    cout<<"----- PRODUCTOS POR AGOTARSE -----"<<endl;
    for(int i=0;i<cantidad;i++){
        int stock=lista[i].getStock();
        if(stock<limite){
            cout<<"Producto #"<<i+1<<":"<<endl;
            cout<<"Codigo: "<<lista[i].getCodigo()<<endl;
            cout<<"Nombre: "<<lista[i].getNombre()<<endl;
            cout<<"Categoria: "<<lista[i].getCategoria()<<endl;
            cout<<"Precio unitario: "<<lista[i].getPrecio()<<" soles"<<endl;
            cout<<"Stock: "<<lista[i].getStock()<<endl;
            cout<<"------------------------"<<endl;
        }
    }
    cout<<endl;
}

double Inventario::valorTotalInventario() const{
    double suma=0.0;
    for(int i=0;i<cantidad;i++){
        double valor=lista[i].getPrecio()*lista[i].getStock();
        suma+=valor;
    }
    return suma;
}

void Inventario::cargarDesdeArchivo(const string& nombreArchivo){
    string nombre=nombreArchivo+".csv";
    ifstream archivo(nombre);
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl<<endl;
        return;
    }
    cantidad=0;
    string linea;
    while(getline(archivo,linea) && cantidad<MAX){
        string campos[5];
        int ind=0;
        string campo="";
        for(char c:linea){
            if(c==','){
                campos[ind]=campo;
                campo="";
                ind++;
            }else{
                campo+=c;
            }
        }
        campos[ind]=campo;

        int codigo=stoi(campos[0]);
        string nombre=campos[1];
        string categoria=campos[2];
        double precio=stod(campos[3]);
        int stock=stoi(campos[4]);

        Producto p(codigo,nombre,categoria,precio,stock);
        lista[cantidad]=p;
        cantidad++;
    }
    archivo.close();
    cout<<"Datos cargados correctamente desde el archivo."<<endl<<endl;
}

void Inventario::guardarEnArchivo(const string& nombreArchivo) const{
    string nombre=nombreArchivo+".csv";
    ofstream archivo(nombre);
    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl<<endl;
        return;
    }
    for(int i=0;i<cantidad;i++){
        archivo<<lista[i].getCodigo()<<",";
        archivo<<lista[i].getNombre()<<",";
        archivo<<lista[i].getCategoria()<<",";
        archivo<<lista[i].getPrecio()<<",";
        archivo<<lista[i].getStock()<<endl;
    }
    archivo.close();
    registrarLog("Inventario guardado en archivo "+nombreArchivo+".");
    cout<<"Datos guardados correctamente en el archivo."<<endl<<endl;
}

void Inventario::registrarLog(const string& mensaje) const{
    ofstream log("log.txt",ios::app);
    if(!log.is_open()){
        cout<<"No se pudo abrir el archivo de log."<<endl<<endl;
        return;
    }

    time_t ahora = time(nullptr);
    tm tiempo;
    localtime_s(&tiempo, &ahora);

    log<<"[";
    log<<(tiempo.tm_year+1900)<<"-";
    log<<(tiempo.tm_mon+1)<<"-";
    log<<tiempo.tm_mday<<" ";
    log<<tiempo.tm_hour<<":";
    log<<tiempo.tm_min<<":";
    log<<tiempo.tm_sec;
    log<<"] ";
    log<<mensaje<<endl;

    log.close();
}

void Inventario::menu(){
    int opcion;
    do{
        cout<<"=========== MENU DE INVENTARIO ==========="<<endl;
        cout<<"1. Administrar stock"<<endl;
        cout<<"2. Mostrar stock"<<endl;
        cout<<"3. Ordenar stock"<<endl;
        cout<<"4. Gestion de archivos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
            case 1:{
                int op1;
                cout<<"----- ADMINISTRAR STOCK -----"<<endl;
                cout<<"1. Agregar producto"<<endl;
                cout<<"2. Eliminar producto"<<endl;
                cout<<"3. Agregar stock"<<endl;
                cout<<"4. Disminuir stock"<<endl;
                cout<<"5. Actualizar stock"<<endl;
                cout<<"0. Volver"<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                cout<<endl;
                switch(op1){
                    case 1:{
                        int codigo,stock;
                        double precio;
                        string nombre,categoria;
                        cout<<"Codigo: ";
                        cin>>codigo;
                        cout<<"Nombre: ";
                        cin.ignore();
                        getline(cin, nombre);
                        cout<<"Categoria: ";
                        getline(cin, categoria);
                        cout<<"Precio unitario en soles: ";
                        cin>>precio;
                        cout<<"Stock inicial: ";
                        cin>>stock;
                        Producto p(codigo, nombre, categoria, precio, stock);
                        agregarProducto(p);
                        cout<<"El producto ha sido agregado al inventario."<<endl<<endl;
                        break;
                    }
                    case 2:{
                        int codigo;
                        cout<<"Codigo a eliminar: ";
                        cin>>codigo;
                        eliminarProducto(codigo);
                        break;
                    }
                    case 3:{
                        int codigo, cant;
                        cout<<"Codigo: ";
                        cin>>codigo;
                        cout<<"Cantidad a agregar: ";
                        cin>>cant;
                        agregarStock(codigo, cant);
                        break;
                    }
                    case 4:{
                        int codigo, cant;
                        cout<<"Codigo: ";
                        cin>>codigo;
                        cout<<"Cantidad a disminuir: ";
                        cin>>cant;
                        disminuirStock(codigo, cant);
                        break;
                    }
                    case 5:{
                        int codigo, stock;
                        cout<<"Codigo: ";
                        cin>>codigo;
                        cout<<"Nuevo stock: ";
                        cin>>stock;
                        actualizarStock(codigo, stock);
                        break;
                    }
                }
                break;
            }
            case 2:{
                int op2;
                cout<<"----- MOSTRAR STOCK -----"<<endl;
                cout<<"1. Mostrar inventario"<<endl;
                cout<<"2. Productos agotados"<<endl;
                cout<<"3. Productos por agotarse"<<endl;
                cout<<"0. Volver"<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op2;
                cout<<endl;
                switch(op2){
                    case 1:{
                        mostrarInventario();
                        break;
                    }
                    case 2:{
                        reportarAgotados();
                        break;
                    }
                    case 3:{
                        int limite;
                        cout<<"Stock limite: ";
                        cin>>limite;
                        reportarPorAgotarse(limite);
                        break;
                    }
                }
                break;
            }
            case 3:{
                int op3;
                cout<<"----- ORDENAR STOCK -----"<<endl;
                cout<<"1. Ordenar por nombre"<<endl;
                cout<<"2. Ordenar por categoria"<<endl;
                cout<<"3. Ordenar por stock"<<endl;
                cout<<"4. Ordenar por codigo"<<endl;
                cout<<"0. Volver"<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op3;
                cout<<endl;
                switch(op3){
                    case 1:{
                        ordenarPorNombre();
                        break;
                    }
                    case 2:{
                        ordenarPorCategoria();
                        break;
                    }
                    case 3:{
                        ordenarPorStock();
                        break;
                    }
                    case 4:{
                        ordenarPorCodigo();
                        break;
                    }
                }
                break;
            }
            case 4:{
                int op4;
                cout<<"----- GESTION DE ARCHIVOS -----"<<endl;
                cout<<"1. Cargar inventario desde archivo"<<endl;
                cout<<"2. Guardar inventario en archivo"<<endl;
                cout<<"0. Volver"<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op4;
                cout<<endl;
                switch(op4){
                    case 1:{
                        string archivo;
                        cout<<"Nombre del archivo: ";
                        cin>>archivo;
                        cargarDesdeArchivo(archivo);
                        break;
                    }
                    case 2:{
                        string archivo;
                        cout<<"Nombre del archivo: ";
                        cin>>archivo;
                        guardarEnArchivo(archivo);
                        break;
                    }
                }
                break;
            }
            case 0:{
                cout<<"Saliendo..."<<endl;
                registrarLog("Sistema cerrado.");
                break;
            }
            default:{
                cout<<"Opcion invalida."<<endl<<endl;
            }
        }
    }while(opcion!=0);
}