#pragma once
#include <iostream>
#include <algorithm>

//2,5,8,2,1,9,0,3
template <typename It>
void insertionsort(It begin, It end) {
    for (auto i=begin; i !=end;++i)
    for (auto j = i,temp=i; temp!=begin; temp--)
    if(*temp<*(--j)) std::swap(*temp,*j);
}

