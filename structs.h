#ifndef __STRUCTS_H__
#define __STRUCTS_H__

struct Alu{
    long dni;
    char type;
    struct fec{
        int dd, mm, yy;
    }fecnac;

};

void DemoStructs();

#endif // __STRUCTS_H__