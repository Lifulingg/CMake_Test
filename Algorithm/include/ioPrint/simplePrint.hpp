#ifndef _SIMPLEPRINT_HPP_
#define _SIMPLEPRINT_HPP_
#include <iostream>

template<typename T> //
void arrPrint(T *arr, int n);

template<typename T>
void arrPrint(T *arr, int n)
{
    for(int i =0 ; i < n; i++)
    {
        std::cout<<arr[i]<<"   ";
    }
    std::cout<<std::endl;
}




#endif