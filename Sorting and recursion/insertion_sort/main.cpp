#include "ura.hpp"
#include <iostream>
#include <vector>

// U main datoteci mozete testirati vas kod na proizvoljan nacin.

int main(int argc, char* argv[]) {
    std::vector<int> a{2,5,8,2,1,9,0,3};
    insertionsort(a.begin(),a.end());
    for (auto i:a)
    {
        std::cout << i << ' ';
    }
}
