#include <iostream>
#include "structs.h"
using namespace std;

void Print(Alu *pX){
    cout << "dni   : " << pX->dni << endl
         << "type  : " << pX->type << endl
         << "fecnac: " << pX->fecnac.dd << "/" 
                        << pX->fecnac.mm << "/" 
                        << pX->fecnac.yy << endl;
}

void Print(Alu &a){
    Print(&a);
}

void DemoStructs(){
    Alu a1 = {29701234, 'X', {15, 8, 2025}};
    Print(&a1);
    a1.dni = 87654321;
    a1.type= 'A';
    a1.fecnac.dd = 23;
    Print(&a1);
    Print(a1);

    Alu *pAlu = nullptr;
    pAlu = &a1;
    pAlu->dni = 2000;
    pAlu->type = 'M';
    pAlu->fecnac.mm = 9;
    Print(pAlu);
    Print(*pAlu);

    pAlu = new Alu[5];

    pAlu[0].dni = 24680;
    pAlu[0].fecnac.dd = 25;
    Print(&pAlu[0]);
    Print(pAlu);

    Print(&pAlu[2]);

    
    delete [] pAlu;
}