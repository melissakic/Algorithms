#include "ura.hpp"
#include <vector>

// U main datoteci mozete testirati vas kod na proizvoljan nacin.

int main(int argc, char* argv[]) {
    std::vector<int> a{1,2,3,3,3,4,5,6,6,7,8,9};
    auto c=::unique(a.begin(),a.end());
    for (auto i:a)
    {
        std::cout << i <<' ';
    }
    
    return 0;
}
