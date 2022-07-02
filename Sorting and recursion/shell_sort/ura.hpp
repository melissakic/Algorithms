#pragma once
#include <iostream>
#include <algorithm>

template <typename It>
void shellsort(It begin, It end) {
    auto distance=std::distance(begin,end)/2;
    for (; distance > 0; distance/=2)
    {
        for (auto i = begin+distance-1; i < end; i++)
        {
            for (auto j =i-distance; j < ount; j++)            {
                /* code */
            }
            
        }
        
    }
    



    //  int i=std::distance(begin,end)/2;
    // for (; i>0; i=i/2)
    //     for (auto j =begin+i-1; j<end ; j++)
    //        for (auto k = j-i; k>=begin; k=k-i)
    //            if(*(k+i)>=*k)break;
    //            else std::swap(*(k+i),*k);
}