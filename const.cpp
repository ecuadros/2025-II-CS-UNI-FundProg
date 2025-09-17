#include <iostream>
#include "const.h"
using namespace std;

int x = 10;
const int y = 100;

void fx1(string msg, int n){
    msg = "fx1:"+msg;
    n++;
    cout << msg << n << endl;
}

void fx2(string msg, int &n){
    msg = "fx2:"+msg;
    n++;
    cout << msg << n << endl;
}

void fx3(string msg, const int n){
    // n++; Error ! n no puede variar.
    msg = "fx3:"+msg;
    cout << msg << n << endl;
}

constexpr void fx4(string& msg, int n) {
    // msg ya es const, n se pasa por valor pero no se modifica
    // constexpr string modified_msg = "fx4:" + msg;
    // int modified_n = n + 1;
    // cout no puede usarse en constexpr, así que esto no compilaría
    // cout << modified_msg << modified_n << endl;
}

void DemoConst(){
    x++;
    fx1("y:", y);

    fx2("Msg1: ", x);
    // fx2("Msg1: ", y);
    // fx2("Msg1: ", 8);

    fx3("Msg3.1: ", 5);
    fx3("Msg3.2: ", x);
    fx3("Msg3.3: ", y);

    string msg = "Msg4.1";
    fx4(msg, 7);
    // fx4("Msg4.1", x);
    // fx4("Msg4.1", y);
}