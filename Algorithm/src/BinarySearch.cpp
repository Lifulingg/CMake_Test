#include "BinarySearch/BinarySearch.h"
#include "spdlog/spdlog.h"

void BinarySearch(int *arr, int n, int Target_value)
{
    int low =0, high = n-1;
    

    while(1)
    {
        int mid = (low+high +1)/2;

        if(arr[mid]<Target_value)
        {
            low = mid;
        }
        else if(arr[mid]>Target_value)
        {
            high = mid;
        }
        else if(arr[mid]==Target_value)
        {
            spdlog::info("Find it!");
            return ;
        }
        else
        {
            spdlog::error("There have none!");
            return;
        }


    }



}