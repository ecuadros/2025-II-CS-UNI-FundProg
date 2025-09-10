#include <iostream>
#include "recursion.h"
#include "types.h"

// fib(0) = 0
// fib(1) = 1
// fib(n) = fib(n-1) + fib(n-2)
// Computational complexity 2^n
BigNumber fib_recursivo(PositiveNumber n){
    if( n <= 1 )
       return n;
    return fib_recursivo(n-1) + fib_recursivo(n-2);
}

// a = 0 1 1 2 3  5  8
// b = 1 1 2 3 5  8 13
// c = 1 2 3 5 8 13
// Computational complexity: n-2
BigNumber fib_iterativo(PositiveNumber n){
    if( n <= 1 )
       return n;
    BigNumber a = 0, b = 1, c;
    for( PositiveNumber i = 2 ; i <= n ; ++i ){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

// Computational complexity: n
// 4: 4 * factorial_recursivo(3)
//        3 * factorial_recursivo(2)
//            2 * factorial_recursivo(1)
//                1
BigNumber factorial_recursivo(PositiveNumber n){
    if(n <= 1)
        return 1L;
    return n * factorial_recursivo(n-1);
}

BigNumber factorial_iterativo(PositiveNumber n){
    BigNumber rpta = 1L;
    for( PositiveNumber i = 2 ; i <= n ; ++i )
        rpta *= i;
    return rpta;
}

void DemoRecursion(){
    // for(auto i = 0; i < 70 ; i++){
    //     std::cout << "fib_iterativo(" << i << ")=" << fib_iterativo(i) << std::endl;
    //     std::cout << "fib_recursivo(" << i << ")=" << fib_recursivo(i) << std::endl;
    //     std::cout << std::endl;
    // }

    for(auto i = 0; i < 70 ; i++){
        std::cout << "factorial_iterativo(" << i << ")=" << factorial_iterativo(i) << std::endl;
        std::cout << "factorial_recursivo(" << i << ")=" << factorial_recursivo(i) << std::endl;
        std::cout << std::endl;
    }
}

void VariablesCapacity(){
    unsigned char uc = 163;
    char sc = 100; sc += 63;
    std::cout << "uc: " << uc << std::endl;
    std::cout << "sc: " << sc << std::endl;
    char c;
    int i;
    for( i = 0, c = 'A' ; i < 80 ; i++, c++ )
        std::cout << c;
    for( i = 0, uc = 200 ; i < 80 ; i++, uc++ )
        std::cout << (int)uc << " ";
    uc = 0;
    uc += 5000;
    std::cout << (int)uc << " ";
}