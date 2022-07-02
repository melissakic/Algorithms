#include "ura.hpp"
#include <vector>
#include <iostream>


int main(int argc, char* argv[]) {
    std::vector<int> a{5,1,6,3,8,3,2,6};
    auto c=::partition(a.begin(),a.end(),[](int ele){return !(ele%2);});
    for (auto i:a)
    {
        std::cout << i <<' ';
    }
    
    
}
