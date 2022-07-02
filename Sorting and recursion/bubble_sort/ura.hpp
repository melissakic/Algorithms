#pragma once
#include <iostream>
#include <algorithm>

template <typename It>
void bubblesort(It begin, It end) {
    for (auto i = end,update=--end; i !=begin;i--)
       for (auto j = begin; j!=update;)
       {    
           auto temp=j;
           if(*j>*(++j)) std::swap(*temp,*(j));
       }
    
}

