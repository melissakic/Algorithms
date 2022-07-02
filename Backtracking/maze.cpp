#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int>>& tabla){
    for (auto i = 0; i < tabla.size(); i++)
    {
        for (auto j = 0; j < tabla.size(); j++)
        {
            std::cout << tabla[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}


bool isDestination(int row,int column){
    if(row==3 && column==3) return true;
    return false;
}

bool isValid(std::vector<std::vector<int>>& a,int row,int column){
    if(row>=0 && row<4 && column>=0 && column<4 && a[row][column]==1)return true;
    return false;
}


bool SolveMaze(std::vector<std::vector<int>>& maze,int x,int y,std::vector<std::vector<int>>& output){
        if(isDestination(x,y)){
            output[x][y]=1;
            return true;
        }
        output[x][y]=1;
        if(isValid(maze,x+1,y)){
            output[x+1][y]=1;
            if(SolveMaze(maze,x+1,y,output))return true;
            output[x+1][y]=0;
        }
        if(isValid(maze,x,y+1)){
            output[x][y+1]=1;
            if(SolveMaze(maze,x,y+1,output))return true;
            output[x][y+1]=0;
        }
        output[x][y]=0;
    return false;

    //    if(isValid(a,row,column)){
    //     if(isDestination(row,column)){
    //         output[row][column]=1;
    //         return true;}
    //     if(output[row][column]==1) return false;
    // if(isValid(a,row+1,column) || isValid(a,row,column+1)){
    //     output[row][column]=1;
    // }else return false;
    // if(maze(a,row+1,column,output)){
    //     return true;
    // }
    // if(maze(a,row,column+1,output)){
    //     return true;
    // }
    // }
    // return false;
}

void Solve(std::vector<std::vector<int>>& maze){
    std::vector<std::vector<int>> output;
    output.resize(maze.size());
    for (auto i = 0; i < maze.size(); i++)
    {
        output[i].resize(maze[i].size());
    }

    if(SolveMaze(maze,0,0,output)){
        print(output);
        return;
    }
    std::cout << "Error" << std::endl;
}


int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> maze{{1,1,0,0},{1,0,0,0},{1,1,0,1},{1,1,1,1}};
    print(maze);
    std::cout << std::endl;
    Solve(maze);
    return 0;
}
