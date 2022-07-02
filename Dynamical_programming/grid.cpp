#include <iostream>
#include <vector>
void print(std::vector<std::vector<int>>& grid){
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << grid[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    
}

//backtracking
// bool isValid(int row,int column,std::vector<std::vector<int>>& grid){
//     if(row>=0 && row<18 && column>=0 && column<18 && grid[row][column]==0) return true;
//     return false;
// }


// bool ways(int row,int column,std::vector<std::vector<int>>& grid){
//     if(row==17 && column==17){
//         grid[row][column]=1;
//         return true;
//     }
//     if(isValid(row+1,column,grid)){
//         grid[row+1][column]=1;
//         if(ways(row+1,column,grid)) return true;
//         grid[row+1][column]=0;
//     }
//     if(isValid(row,column+1,grid)){
//         grid[row][column+1]=1;
//        if(ways(row,column+1,grid)) return true;
//         grid[row][column+1]=0;
//     }
//     return false;
// }

// void calculate(std::vector<std::vector<int>>& grid){
//     std::cout << "Rjesenje" << std::endl;
//     ways(0,0,grid);
//     print(grid);
// }


//Dynamical approach-memo
// size_t travel(int row,int column,std::vector<std::vector<size_t>>& lookup){
//     if(lookup[row][column]!=0) return lookup[row][column];
//     if(row==1 && column==1) return 1;
//     if(row==0 || column==0) return 0;
//     lookup[row][column]=travel(row-1,column,lookup)+travel(row,column-1,lookup);
//     return lookup[row][column];
// }

//Dynamical approach-bottomup

bool isValid(int row,int column,std::vector<std::vector<int>>& table){
    if(row>=0 && row<4 && column>=0 && column<4) return true;
    return false;
}

size_t travel(std::vector<std::vector<int>>& table){
    table[1][1]=1;
    for (int i = 1; i < table.size(); i++)
    {
        for (int j = 1; j < table[i].size(); j++)
        {
           if(isValid(i+1,j,table)) table[i+1][j]+=table[i][j];
           if(isValid(i,j+1,table)) table[i][j+1]+=table[i][j];
        }
    }
    print(table);
    return table[3][3];
}

int main(int argc, char const *argv[])
{   
    std::vector<std::vector<int>> grid;
    grid.resize(4);
    for (int i = 0; i < 4; i++) grid[i].resize(4);
    std::cout << travel(grid) << std::endl;
    return 0;
}
