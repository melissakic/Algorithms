#include "ura.hpp"
#include <vector>

// U main datoteci mozete testirati vas kod na proizvoljan nacin.

int main(int argc, char* argv[]) {
    std::vector<int> a{6,4,51,2,73,84,1,3};
    mergesort(a.begin(),a.end());
    for (auto i:a)
    {
        std::cout << i <<' ';
    }
    
}

