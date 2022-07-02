#pragma once
#include <iostream>

#include <algorithm>

template <typename It, typename P>
It partition(It begin, It end, P p) {
 if(begin==--end && !p(*begin))return begin;
 else if(begin==end && p(*begin))return end+1;
 else while(1)
 {
  if(!p(*begin) && p(*end)) std::swap(*begin,*end);
   else if(p(*begin) && p(*end)) std::swap(*(begin+1),*end);
   if(begin++==--end) break;
 }
 return begin;
}

