#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
void merge(T dest,T middle,T end){
while (dest<middle)
  {
      if(*dest>*middle) {
          std::swap(*dest,*middle);
      for (auto i=middle+1; i !=end; i++)
      {
          if(*(i)<*(i-1)) std::swap(*(i),*(i-1));
          else break;
      }}
      ++dest;
  }
}




template <typename It>
void mergesort(It begin, It end) {
    auto size=std::distance(begin,end);
    if(size==1) return;
    auto middle=begin+size/2;
    mergesort(begin,middle);
    mergesort(middle,end);
    merge(begin,middle,end);
}
