#include <iostream>
#include <vector>
#include "foreach.h"
using namespace std;

using T1 = long;
using T2 = string;
void ForeachDemo(){
    vector<T1> v = {5, 7, 2, 4};

    cout << "Forma #1: muchos errores" << endl;
    for(int x = 0; x < v.size(); x++)
        cout << v[x] << " ";
    cout << endl;

    cout << "Forma #2: poquito mejor (3 mejoras)" << endl;
    auto size = v.size();
    for(size_t x = 0; x < size; ++x)
        cout << v[x] << " ";
    cout << endl;

    cout << "Forma #3: mucho mejor" << endl;
    for(auto elem : v)
        cout << elem << " ";
    cout << endl;

    cout << "Forma #4: aplicando una funcion" << endl;
    for(auto &elem : v)
        AddOne(elem);
    for(auto &elem : v)
        PrintElem(elem);
    cout << endl;

    cout << "Forma #5: aplicando una funcion" << endl;
    foreach(v, AddOne<T1>);
    foreach(v, PrintElem<T1>);
    cout << endl;

    cout << "Forma #6: aplicando una funcion" << endl;
    foreach(v, AddX<T1>, 5L);
    foreach(v, PrintElem<T1>);
    cout << endl;

    cout << "Forma #6: funcion lambda" << endl;
    foreach(v, [](auto &elem){ elem *= elem;    });
    foreach(v, PrintElem<T1>);
    cout << endl;

    vector<T2> vStr = {"CS", "UNI", "2025-II"};
    foreach(vStr, AddX<T2>, string("X"));
    foreach(vStr, PrintElem<T2>);


}