#include <iostream>
#include <vector>

int maxpath(std::vector<std::vector<int>>& put,int row,int column){
    if(row==put.size()-1 && column==put.size()-1) return put[row][column];
    if(row>put.size()-1 || column>put.size()-1) return 0;
    return put[row][column]+std::max(maxpath(put,row,column+1),maxpath(put,row+1,column));
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> put{ {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::cout << maxpath(put,0,0) << std::endl;
    return 0;
}
