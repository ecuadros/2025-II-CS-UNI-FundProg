#ifndef __FOREACH_H__
#define __FOREACH_H__
#include <iostream>

// template <typename Iterator, typename Function >
// void foreach(Iterator begin, Iterator end, Function func){
//     auto iter = begin;
//     for(; iter != end ; ++iter )
//         func( *iter );
// }

// V1.0
// template <typename Container, typename Func>
// void foreach(Container &container, Func fn){
//     // typename Container::iterator iter = container.begin();
//     auto iter = container.begin();
//     for(; iter != container.end() ; iter++ )
//         fn( *iter );
// }

// Variadic templates
template<typename Iterator, typename Function, typename... Args>
void foreach (Iterator begin, Iterator end,
              Function func, Args &&... args){ 
    for (auto iter = begin; iter != end; ++iter)  
        func(*iter, std::forward<Args>(args)...);
        //  std::invoke(func, *iter, args...);
}

// V1.1
template <typename Container,
          typename Function, typename... Args>
void foreach(Container &container, Function func, Args &&... args){
    foreach(container.begin(), container.end(), func, std::forward<Args>(args)...);
}

// template<typename Callable, typename... Args>
// decltype(auto) call(Callable op, Args&&... args)
// {
//     if constexpr(is_void_v<invoke_result_t<Callable, Args...>>)
//     { std::cout << "Function is returning: void!" << std::endl;
//       invoke(forward<Callable>(op), forward<Args>(args)...);
//       //...  // do something before we return
//       return;
//     }
//     else // return type is not void:
//     { auto ret = invoke(forward<Callable>(op), forward<Args>(args)...);
//       std::cout << "Function is returning: " << type_name<decltype(ret)>() << std::endl;
//       //...  // do something (with ret) before we return
//       return ret;
//     }
// }

template<typename T>
void PrintElem(T &elem){
    std::cout << elem << " ";
}

template<typename T>
void AddOne(T &elem){
    ++elem;
}

template<typename T>
void AddX(T &elem, const T &delta){
    elem = elem + delta;
}


void ForeachDemo();

#endif // __FOREACH_H__