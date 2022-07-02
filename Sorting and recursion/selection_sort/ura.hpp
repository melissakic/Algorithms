#pragma once
#include <iostream>

#include <algorithm>


//2,5,8,2,1,9,0,3
template <typename It>
void selectionsort(It begin, It end) {
    for (auto i = begin; i!=end;++i)
    {
        auto temp=i;
        for (auto j = i+1; j !=end; j++) if(*j<*temp) temp=j;
        std::swap(*i,*temp);
    }
}

