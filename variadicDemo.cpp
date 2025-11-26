#include <iostream>
#include "variadic.h"

using namespace std;

template <typename T>
void PrintResult(T val){
    cout <<"Res: " << val << endl;
}

void VariadicDemo(){
    auto x = VarFn(5, 4, 2, 8, 6);
    PrintResult(x);

    auto f = VarFn(7, 4.5, 10, 3.6, 7.1, 15);
    PrintResult(f);

    auto str = VarFn(string("hola"), string("que"), string("tal"));
    PrintResult(str);
}