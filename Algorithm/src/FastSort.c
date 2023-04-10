#include "FastSort/FastSort.h"

//wa keng fa
void vFastSort(int *arr, int low, int high)
{

    int i = low, j = high, base = arr[i];
    if(low > high)
    {
        return;
    } 

    while(i<j)
    {
        //right-->find large num
        while(i<j && arr[j] > base)
        {
            j--;
        }
        if(i < j)
        {
            arr[i] = arr[j];
            
        }
        if(i < j && arr[j] == base)
        {
            i++;j--;
        }
        
        while(i<j && arr[i] < base)
        {
            i++;
        }
        if(i<j)
        {
            arr[j] = arr[i];
        }
        if(i<j && arr[i] == base)
        {
            i++;j--;
        }

    }
    arr[i] = base;

    vFastSort(arr, low, i-1);
    vFastSort(arr, i+1, high);
}
