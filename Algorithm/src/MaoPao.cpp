#ifndef _MAOPAO_CPP_
#define _MAOPAO_CPP_
#include "MaoPao/MaoPao.hpp"
#include "spdlog/spdlog.h"
//maopao sort
void MaoPaoSort(int *arr, int n)
{

#ifdef ALGO_DEBUG
    spdlog::info("Mao Pao file spdlog use...");
#endif 

    int tmp = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n-i -1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }

        }

    }






}
#endif