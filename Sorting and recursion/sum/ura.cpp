#include "ura.hpp"
#include <numeric>

int sum(const int* array, int n) {
    if (n==0) return 0;
    if (n==1) return array[n-1];
    return array[n-1] + sum(array,n-1);
}
