#include "ura.hpp"
#include <stdexcept>

unsigned int divide(unsigned int a, unsigned int b) {
    if (b==0) throw std::runtime_error("dijeljenje sa 0 nije definisano\n");
    if (a<b) return 0;
    return 1 + divide(a-b,b);
}


