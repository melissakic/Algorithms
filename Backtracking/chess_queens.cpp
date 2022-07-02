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

bool isValid(std::vector<std::vector<int>>& board,int x, int y) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      if (board[i][j] == 1) {
        if (i == x) return false;
        if (j == y) return false;
        if ((i - x) == (j - y)) return false;
        if ((i - x) == -(j - y)) return false;
      }
    }
  }
  return true;
}


bool table(std::vector<std::vector<int>>& tabla,int row){
    if(row==4) {
        print(tabla);
    return true;}
    for (auto i = 0; i < 4; i++)
    {
        if (isValid(tabla,row,i)){
            tabla[row][i]=1;
            if (table(tabla,row+1)) return true;
            tabla[row][i]=0;
        }
    }
    return false;
}


int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> polje;
    polje.resize(4);
    for (auto i = 0; i < 4; i++) polje[i].resize(4);
    table(polje,0);
    return 0;
}
