#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>>& a){
    for (auto i = 0; i < a.size(); i++)
    {
        for (auto j = 0; j < a[i].size(); j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isValid(std::vector<std::vector<int>>& table,int x,int y){
    return table[x][y]==0;
}

bool ValidNum(std::vector<std::vector<int>>& tabla,int x,int y,int num){
    for (auto i = 0; i < 9; i++)
    {
        if(tabla[x][i]==num)return false;
        if(tabla[i][y]==num)return false;
    }

    int start=x-x%3;
    int ips=y-y%3;
    for (auto i = start; i < start+3; i++)
    {
        for (auto j = ips; j < ips+3; j++)
        {/* code */
            if(tabla[i][j]==num)return false;
        }
        
    }
    return true;
}

bool Solve(std::vector<std::vector<int>>& tabla,int x,int y){
    if(x==8 && y>8){
        return true;
    }
    if(y>8){
        y=0;
        x=x+1;
    }
    if(!isValid(tabla,x,y)) return Solve(tabla,x,y+1);
    for (auto i = 1; i <10 ; i++)
    {
        if(ValidNum(tabla,x,y,i)){
            tabla[x][y]=i;
            if(Solve(tabla,x,y+1))return true;
            tabla[x][y]=0;
        }
    }
    return false;
}


void SolveSudoku(std::vector<std::vector<int>>& tabla){
    if(Solve(tabla,0,0)){
        print(tabla);
    }
    else std::cout << "Error" << std::endl;
}


int main(int argc, char const *argv[])
{
     std::vector<std::vector<int>> sudoku;
    sudoku.resize(9);
    int temp;
    for (auto i = 0; i < 9; i++)
    {
        for (auto j = 0; j < 9; j++)
        {
            std::cin>>temp;
            sudoku[i].push_back(temp);
        }
    }
    SolveSudoku(sudoku);
    return 0;
}
