#include <iostream>
#include <vector>


    std::vector<int> x{2,1,-1,-2,-2,-1,1,2};
    std::vector<int> y{1,2,2,1,-1,-2,-2,-1};

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

bool isValid(std::vector<std::vector<int>>& table,int row,int column){
    if(table[row][column]==0) return true;
    else return false;
}

bool validMove(std::vector<std::vector<int>>& table,int row,int column){
    if(row>=0 && row<table.size() && column>=0 && column<table.size() && isValid(table,row,column))
    return true;
    else return false;
}

bool tableSolve(std::vector<std::vector<int>>& tabla,int row,int column,int counter){
    int X_,Y_;
    if(counter==64)return true;
    for (auto i = 0; i < 8; i++)
    {
        X_=row+x[i];
        Y_=column+y[i];
        if (validMove(tabla,X_,Y_))
        {
            tabla[X_][Y_]=counter+1;
            if(tableSolve(tabla,X_,Y_,counter+1)) return true;
            else{
                tabla[X_][Y_]=0;
            }
        } 
    }
    return false;
}


void solveChess(std::vector<std::vector<int>>& tabla){
    tabla[0][0]=1;
    if(tableSolve(tabla,0,0,1)){
        print(tabla);}
    else std::cout << "Error" << std::endl;

}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> tabla;
    tabla.resize(8);
    for (auto i = 0; i < 8; i++)
    {
        tabla[i].resize(8);   
    }
    solveChess(tabla);
    return 0;
}
