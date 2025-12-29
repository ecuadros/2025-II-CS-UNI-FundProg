#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std;

void menu();
void ingreso();
void actualizar();
void eliminarSocio();
void consultar();
void deposito();
void retiro();
void libreta();
void estadoCuenta();

struct socio{
    char nombre[35];
    char dni[15];
    char ciudad[20];
    char telefono[20];
};

struct transacciones{
    char dni[15];
    char nombre[35];
    char fecha[15];
    float valorinicial;
    float transacc;
};

struct RegistroHistorial{ 
    char dnif[15];
    char nombref[35];
    char fechaf[15];
    char tipof[10];
    float transaccf;
    float saldof;
};

int main(){
    menu();
    return 0;
}

void menu(){
    char op;
    do{
        cout << "--- MENU PRINCIPAL ---" << endl;
        cout << "1. Socios" << endl;
        cout << "2. Cuenta" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> op;

        if(op=='1'){
            char op2;
            do{
                cout << "--- SOCIOS ---" << endl;
                cout << "1. Registrar" << endl;
                cout << "2. Actualizar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Consultar" << endl;
                cout << "5. Volver" << endl;
                cout << "Opcion: ";
                cin >> op2;

                if(op2=='1') ingreso();
                else if(op2=='2') actualizar();
                else if(op2=='3') eliminarSocio();
                else if(op2=='4') consultar();

            } while(op2!='5');
        }
        else if(op=='2'){
            char op2;
            do{
                cout << "--- CUENTA ---" << endl;
                cout << "1. Deposito" << endl;
                cout << "2. Retiro" << endl;
                cout << "3. Ver movimientos" << endl;
                cout << "4. Generar estado de cuenta (TXT)" << endl;
                cout << "5. Volver" << endl;
                cout << "Opcion: ";
                cin >> op2;

                if(op2=='1') deposito();
                else if(op2=='2') retiro();
                else if(op2=='3') libreta();
                else if(op2=='4') estadoCuenta();

            } while(op2!='5');
        }
    } while(op!='3');
}


void ingreso(){
    fstream pa("ArchivoBinario.dat", ios::in | ios::out | ios::binary | ios::app);
    ofstream pa2("Socios.txt", ios::app);

    socio nuevo;
    socio* lista = new socio[200];
    
    char r;
    int i=0;

    if(!pa.is_open() || !pa2.is_open()){
        cout << "No se puede abrir archivo" << endl;
        delete[] lista;
        return;
    }

    pa.seekg(0, ios::beg);
    while(pa.read((char*)&nuevo,sizeof(socio))) lista[i++]=nuevo;

    pa.clear();
    pa.seekp(0, ios::end);

    cin.ignore();
    cout << "Nombre: ";
    cin.getline(nuevo.nombre,35);

    int existe;
    do{
        existe=0;
        cout << "DNI: ";
        cin.getline(nuevo.dni,15);
        for(int j=0;j<i;j++)
            if(strcmp(lista[j].dni,nuevo.dni)==0) existe=1;
        if(existe) cout << "DNI ya existe." << endl;
    } while(existe);

    cout << "Ciudad: ";
    cin.getline(nuevo.ciudad,20);
    cout << "Telefono: ";
    cin.getline(nuevo.telefono,20);

    cout << "Guardar? (s/n): ";
    cin >> r;

    if(r=='s'||r=='S'){
        pa.write((char*)&nuevo,sizeof(socio));
        pa2 << nuevo.nombre << " " << nuevo.dni << " "
            << nuevo.ciudad << " " << nuevo.telefono << endl;
        cout << "Socio registrado." << endl;
    }

    pa.close();
    pa2.close();
    
    delete[] lista;
}

void actualizar(){
    ifstream pa_in("ArchivoBinario.dat", ios::binary);
    socio aux;
    
    socio* lista = new socio[200];
    
    char dni[15];
    int n=0;

    if(!pa_in.is_open()) { delete[] lista; return; }

    while(pa_in.read((char*)&aux,sizeof(socio))) lista[n++]=aux;
    pa_in.close();

    cin.ignore();
    cout << "DNI a actualizar: ";
    cin.getline(dni,15);

    int pos=-1;
    for(int i=0;i<n;i++)
        if(strcmp(lista[i].dni,dni)==0) pos=i;

    if(pos==-1){ 
        cout<<"No existe" << endl; 
        delete[] lista;
        return; 
    }

    cout << "Nuevo nombre: ";
    cin.getline(lista[pos].nombre,35);

    ofstream pa_out("ArchivoBinario.dat", ios::binary | ios::trunc);
    ofstream pa2("Socios.txt", ios::trunc);

    for(int i=0;i<n;i++){
        pa_out.write((char*)&lista[i],sizeof(socio));
        pa2 << lista[i].nombre << " " << lista[i].dni << " "
            << lista[i].ciudad << " " << lista[i].telefono << endl;
    }
    pa_out.close();
    pa2.close();
    
    delete[] lista;
}

void eliminarSocio(){
    ifstream pa_in("ArchivoBinario.dat", ios::binary);
    socio aux;
    
    socio* lista = new socio[200];
    
    char dni[15];
    int n=0;

    if(!pa_in.is_open()) { delete[] lista; return; }

    while(pa_in.read((char*)&aux,sizeof(socio))) lista[n++]=aux;
    pa_in.close();

    cin.ignore();
    cout << "DNI a eliminar: ";
    cin.getline(dni,15);

    int pos=-1;
    for(int i=0;i<n;i++)
        if(strcmp(lista[i].dni,dni)==0) pos=i;

    if(pos==-1) { 
        cout<<"Socio no encontrado" << endl; 
        delete[] lista;
        return; 
    }

    for(int i=pos;i<n-1;i++) lista[i]=lista[i+1];
    n--;

    ofstream pa_out("ArchivoBinario.dat", ios::binary | ios::trunc);
    ofstream pa2("Socios.txt", ios::trunc);

    for(int i=0;i<n;i++){
        pa_out.write((char*)&lista[i],sizeof(socio));
        pa2 << lista[i].nombre << " " << lista[i].dni << " "
            << lista[i].ciudad << " " << lista[i].telefono << endl;
    }
    pa_out.close();
    pa2.close();
    
    delete[] lista;
}

void consultar(){
    ifstream pa("ArchivoBinario.dat", ios::binary);
    socio aux;
    char dni[15];

    if(!pa.is_open()) return;

    cin.ignore();
    cout << "DNI: ";
    cin.getline(dni,15);

    bool encontrado = false;
    while(pa.read((char*)&aux,sizeof(socio))){
        if(strcmp(aux.dni,dni)==0){
            cout << "Nombre: " << aux.nombre << endl;
            cout << "Ciudad: " << aux.ciudad << endl;
            cout << "Telefono: " << aux.telefono << endl;
            encontrado = true;
            break;
        }
    }
    if(!encontrado) cout << "Socio no encontrado." << endl;

    pa.close();
}

void deposito(){
    socio* socios = new socio[200];
    transacciones* movs = new transacciones[200];
    
    socio s;
    transacciones t;
    RegistroHistorial reg; 
    
    char dni[15];
    int ns=0, nm=0, ps=-1, pm=-1;

    ifstream pa("ArchivoBinario.dat", ios::binary);
    if(!pa.is_open()){ 
        cout<<"No hay socios" << endl; 
        delete[] socios; delete[] movs; return;
    }
    while(pa.read((char*)&s,sizeof(socio))) socios[ns++]=s;
    pa.close();

    cin.ignore();
    cout << "DNI: ";
    cin.getline(dni,15);

    for(int i=0;i<ns;i++)
        if(strcmp(socios[i].dni,dni)==0) ps=i;
    if(ps==-1){ 
        cout<<"Socio no existe" << endl; 
        delete[] socios; delete[] movs; return; 
    }

    ifstream da_in("Movimientos.dat", ios::binary);
    if(da_in.is_open()){
        while(da_in.read((char*)&t,sizeof(transacciones))) movs[nm++]=t;
        da_in.close();
    }

    for(int i=0;i<nm;i++)
        if(strcmp(movs[i].dni,dni)==0) pm=i;

    float monto;
    cout << "Monto a depositar: ";
    cin >> monto;
    cin.ignore();
    
    if(pm==-1){
        strcpy(movs[nm].dni,dni);
        strcpy(movs[nm].nombre,socios[ps].nombre);
        movs[nm].valorinicial = monto;
        movs[nm].transacc = monto;
        cout << "Fecha: ";
        cin.getline(movs[nm].fecha,15);
        pm = nm++;
    } else {
        movs[pm].transacc = monto;
        movs[pm].valorinicial += monto;
        cout << "Fecha: ";
        cin.getline(movs[pm].fecha,15);
    }

    ofstream da_out("Movimientos.dat", ios::binary | ios::trunc);
    for(int i=0;i<nm;i++)
        da_out.write((char*)&movs[i],sizeof(transacciones));
    da_out.close();

    ofstream li("Libreta.dat", ios::binary | ios::app);
    strcpy(reg.dnif,dni);
    strcpy(reg.nombref,socios[ps].nombre);
    strcpy(reg.fechaf,movs[pm].fecha);
    strcpy(reg.tipof,"Deposito");
    reg.transaccf = monto;
    reg.saldof = movs[pm].valorinicial;
    li.write((char*)&reg,sizeof(RegistroHistorial)); 
    li.close();

    cout << "Deposito realizado." << endl;
    
    delete[] socios;
    delete[] movs;
}

void retiro(){
    socio* socios = new socio[200];
    transacciones* movs = new transacciones[200];
    
    socio s;
    transacciones t;
    RegistroHistorial reg; 
    
    char dni[15];
    int ns=0, nm=0, ps=-1, pm=-1;

    ifstream pa("ArchivoBinario.dat", ios::binary);
    if(!pa.is_open()){ 
        cout<<"No hay socios" << endl; 
        delete[] socios; delete[] movs; return;
    }
    while(pa.read((char*)&s,sizeof(socio))) socios[ns++]=s;
    pa.close();

    cin.ignore();
    cout << "DNI: ";
    cin.getline(dni,15);

    for(int i=0;i<ns;i++)
        if(strcmp(socios[i].dni,dni)==0) ps=i;
    if(ps==-1){ 
        cout<<"Socio no existe" << endl; 
        delete[] socios; delete[] movs; return; 
    }

    ifstream da_in("Movimientos.dat", ios::binary);
    if(!da_in.is_open()){ 
        cout<<"No hay saldo" << endl; 
        delete[] socios; delete[] movs; return;
    }
    while(da_in.read((char*)&t,sizeof(transacciones))) movs[nm++]=t;
    da_in.close();

    for(int i=0;i<nm;i++)
        if(strcmp(movs[i].dni,dni)==0) pm=i;
    if(pm==-1){ 
        cout<<"No hay saldo" << endl; 
        delete[] socios; delete[] movs; return;
    }

    float monto;
    do{
        cout << "Saldo actual: " << movs[pm].valorinicial << endl;
        cout << "Monto a retirar: ";
        cin >> monto;
    } while(monto<=0 || monto>movs[pm].valorinicial);

    cin.ignore();
    movs[pm].transacc = monto;
    movs[pm].valorinicial -= monto;
    cout << "Fecha: ";
    cin.getline(movs[pm].fecha,15);

    ofstream da_out("Movimientos.dat", ios::binary | ios::trunc);
    for(int i=0;i<nm;i++)
        da_out.write((char*)&movs[i],sizeof(transacciones));
    da_out.close();

    ofstream li("Libreta.dat", ios::binary | ios::app);
    strcpy(reg.dnif,dni);
    strcpy(reg.nombref,socios[ps].nombre);
    strcpy(reg.fechaf,movs[pm].fecha);
    strcpy(reg.tipof,"Retiro");
    reg.transaccf = monto;
    reg.saldof = movs[pm].valorinicial;
    li.write((char*)&reg,sizeof(RegistroHistorial)); 
    li.close();

    cout << "Retiro realizado." << endl;
    
    delete[] socios;
    delete[] movs;
}

void libreta(){
    ifstream fe("Libreta.dat", ios::binary);
    RegistroHistorial m; 
    char dni[15];
    bool ok=false;

    if(!fe.is_open()) { cout << "No hay libreta de movimientos." << endl; return; }

    cin.ignore();
    cout << "DNI: ";
    cin.getline(dni,15);

    while(fe.read((char*)&m,sizeof(RegistroHistorial))){ 
        if(strcmp(m.dnif,dni)==0){
            ok=true;
            cout << m.fechaf << " | " << m.tipof
                 << " | " << m.transaccf
                 << " | Saldo: " << m.saldof << endl;
        }
    }
    if(!ok) cout<<"Sin movimientos" << endl;
    fe.close();
}

void estadoCuenta(){
    ifstream fe("Libreta.dat", ios::binary);
    RegistroHistorial m; 
    char dni[15];
    bool existe=false;

    if(!fe.is_open()){ cout<<"No hay movimientos" << endl; return; }

    cin.ignore();
    cout << "DNI: ";
    cin.getline(dni,15);

    ofstream txt("EstadoCuenta.txt", ios::trunc);

    
    txt << "===== ESTADO DE CUENTA =====" << endl;
    txt << "DNI: " << dni << endl << endl;
    txt << "Fecha          Tipo           Monto        Saldo" << endl; 
    txt << "----------------------------------------" << endl;

    txt << fixed;
    txt.precision(2);

    while(fe.read((char*)&m,sizeof(RegistroHistorial))){ 
        if(strcmp(m.dnif,dni)==0){
            existe=true;
            txt << m.fechaf << "   "; 
            
            txt << m.tipof;
            if (strcmp(m.tipof, "Deposito") == 0) txt << "    "; 
            else if (strcmp(m.tipof, "Retiro") == 0) txt << "      "; 
            else txt << "          "; 

            txt << m.transaccf << "  " << m.saldof << endl;
        }
    }

    if(!existe)
        txt << "No existen movimientos" << endl;

    fe.close();
    txt.close();

    cout << "EstadoCuenta.txt generado correctamente." << endl;
}