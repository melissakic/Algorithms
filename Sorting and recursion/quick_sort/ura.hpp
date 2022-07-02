#pragma once
#include <iostream>
#include <algorithm>


template <typename It>
void insertionsort(It begin, It end) {
    for (auto i=begin; i !=end;++i)
    for (auto j = i,temp=i; temp!=begin; temp--)
    if(*temp<*(--j)) std::swap(*temp,*j);
}

template <typename It>
void quicksort(It begin, It end) {
    if (end - begin <=1){
    return;}
  auto pivot = end - 1;
  auto srednji = std::partition(
  begin, end, [pivot](const auto &elem) { return elem < *pivot; });
  std::swap(*pivot, *srednji);
  quicksort(begin, srednji);
  quicksort(srednji + 1, end);
}
