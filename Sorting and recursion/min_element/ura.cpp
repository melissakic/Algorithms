#include "ura.hpp"
#include <numeric>
#include <iostream>

int min(const int* array, int n) {
  if(n==0) throw std::runtime_error("Prazan niz");
  if(&array[0]==&array[n-1])return array[0];
  if(array[0]<array[n-1]) return min(array,n-1);
  return min(array+1,n-1);
}
