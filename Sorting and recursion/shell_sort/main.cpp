#include "ura.hpp"
#include <iostream>
#include <vector>

// U main datoteci mozete testirati vas kod na proizvoljan nacin.

int main(int argc, char* argv[]) {
    std::vector<int> a{25,5,8,4,1,28,0,2,5,27};
    shellsort(a.begin(),a.end());
    for (auto i:a)
    {
        std::cout << i << ' ';
    }
}
