#include <iostream>
#include <vector>
#include <algorithm>

int tour(std::vector<std::vector<int>>& putanja,int pozicija,int cijena){
    if(pozicija>=4) return 0; 
    std::vector<int> putevi;
    for (int i = 1; i < 5; i++)
    {
        if(i==pozicija)continue;
        std::cout << i << std::endl;
       putevi.push_back(tour(putanja,i,putanja[pozicija-1][i-1]));
    }
    return *std::min_element(putevi.begin(),putevi.end());
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> putanja= { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
                       int suma=1;
                       std::cout <<  tour(putanja,1,0)<< std::endl;
    return 0;
}
