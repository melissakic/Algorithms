#include <iostream>
#include <vector>

template<typename T>
void print(const T& grid){
    for (int i = 0; i !=grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << grid[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    
}



int knapsack(std::vector<std::pair<int,int>> objekti,int masa_ruksaka){
    std::vector<std::vector<int>> tabela;
    tabela.resize(objekti.size()+1);
    for (size_t i = 0; i < tabela.size(); i++) tabela[i].resize(masa_ruksaka+1);
    for (int i = 1; i <objekti.size()+1; i++)
    {
       for (int j = 0; j < masa_ruksaka+1; j++)
       {
            int abs=j-objekti[i-1].second;
            if(abs<0){
                tabela[i][j]=tabela[i-1][j];
                continue;
            }
            tabela[i][j]=std::max(objekti[i-1].first+tabela[i][abs],tabela[i-1][j]);
       }
       
    }
    print(tabela);
    return tabela[objekti.size()][masa_ruksaka];
}



int main(int argc, char const *argv[])
{
    int masa_ruksaka=15;
    //vr,kg
    std::vector<std::pair<int,int>> objekti{{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
    int najveca=knapsack(objekti,masa_ruksaka);
    std::cout << "\n"<<najveca << std::endl;
    return 0;
}
