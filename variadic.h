#ifndef __VARIADIC_TEMPLATE_H__
#define __VARIADIC_TEMPLATE_H__

template<typename T>
auto VarFn (T val){
    return val;
}

template<typename T, typename ... Args>
auto VarFn (T val, Args const& ... args){
    return val + VarFn( args ... );
}

void VariadicDemo();

#endif // __VARIADIC_TEMPLATE_H__