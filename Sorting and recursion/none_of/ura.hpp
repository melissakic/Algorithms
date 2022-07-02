#pragma once

#include <algorithm>

template <typename It, typename P>
bool none_of(It begin, It end, P p) {
  while (begin!=end) if(p(*begin++)) return false;
 return true;
}

