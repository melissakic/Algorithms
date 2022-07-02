#include <iostream>
#include <vector>
#include "print.hpp"

int rudnik(std::vector<std::vector<int>>& mine,int row,int column,std::vector<std::vector<int>>& lookup){
    if(row<0 || row>=mine.size() || column>=mine.size() ) return 0;
    if(lookup[row][column]!=-1) return lookup[row][column];
    int right=rudnik(mine,row,column+1,lookup);
    int goreright=rudnik(mine,row-1,column+1,lookup);
    int doleright=rudnik(mine,row+1,column+1,lookup);
    lookup[row][column]=mine[row][column]+std::max(std::max(right,doleright),goreright);
    return lookup[row][column];
}

void findmax(std::vector<std::vector<int>>& mine){
    int max=0;
    std::vector<std::vector<int>> lookup;
    lookup.resize(mine.size());
    for (int i = 0; i < lookup.size(); i++) lookup[i].resize(mine.size());
    for (int i = 0; i < lookup.size(); i++)
    {
       for (int j = 0; j < lookup[i].size(); j++)
       {
            lookup[i][j]=-1;
       }
       
    }
    for (int i = 0; i <mine.size(); i++)
    {
        max=std::max(max,rudnik(mine,i,0,lookup));
    }
    std::cout << max << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> mine{{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
    findmax(mine);
    return 0;
}
