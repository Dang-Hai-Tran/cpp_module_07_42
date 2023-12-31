#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T *arr, int len, F func) {
    for (int i = 0; i < len; i++) {
        func(arr[i]);
    }
}

#endif
