#include "ura.hpp"
#include <vector>
#include <iostream>
#include <hash_map>


int main(int argc, char* argv[]) {
    std::vector<int> a{2,61,27,3,9,0,14,6,61,26,94,21,4,11111,512,541};
    quicksort(a.begin(),a.end());
    for (auto i:a)
    {
        std::cout << i <<' ';
    }
    
}
